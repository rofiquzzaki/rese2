#include "suruh.h"
#include "pasuot.h"
#include <QDebug>
#include <QMessageBox>
#include <QPushButton>

ssh_session sesi_ssh;
char *alb;
int porb;
char *jenb;
char *pasb;

suruh::suruh()
{

}

int suruh::ngakon(char *printah)
{
    //char buffer[256];
    //int nbytes;

    qDebug() << printah;
    qDebug() << alb << porb << jenb << pasb;
    qDebug() << &alb << &porb << &jenb << &pasb;
    //konek_ssh(alb, porb);
    //minta(jenb, pasb);
    //ssh_channel channel;
    //channel bisa dibuat per perintah, karena channel tak terbatas

    //channel = ssh_channel_new(sesi_ssh);
    //pembuatan channel

    //rc = ssh_channel_open_session(channel);

    /*
    if (rc != SSH_OK)
    {
        ssh_channel_free(channel);
        return rc;
    }
    //nyambungke channel

    rc = ssh_channel_request_exec(channel, printah);
    if (rc != SSH_OK)
    {
        ssh_channel_close(channel);
        ssh_channel_free(channel);
        return rc;
    }
    */
    //masukkan perintah

    /*
    nbytes = ssh_channel_read(channel, buffer, sizeof(buffer), 0);
    while (nbytes > 0)
    {
      if (fwrite(buffer, 1, nbytes, stdout) != nbytes)
      {
        ssh_channel_close(channel);
        ssh_channel_free(channel);
        return SSH_ERROR;
      }
      nbytes = ssh_channel_read(channel, buffer, sizeof(buffer), 0);
    }
    if (nbytes < 0)
    {
      ssh_channel_close(channel);
      ssh_channel_free(channel);
      return SSH_ERROR;
    }
    */
    //maca inputan, ceritane ngono
    //qDebug() << buffer;

    return rc;
}



int suruh::konek_ssh(char *alamat, int s_port)
{
    int verbosity = SSH_LOG_PROTOCOL;
    sesi_ssh = ssh_new();
    if (sesi_ssh == NULL)
        exit(-1);

    ssh_options_set(sesi_ssh, SSH_OPTIONS_HOST, alamat);
    ssh_options_set(sesi_ssh, SSH_OPTIONS_LOG_VERBOSITY, &verbosity);

    if (s_port == 0)
        s_port = 22;
    //port kalo kaga diisi jadi 22

    ssh_options_set(sesi_ssh, SSH_OPTIONS_PORT, &s_port);
    //inisialisasi sesi

    rc = ssh_connect(sesi_ssh);
    //konek ke sesi
    qDebug() << "konek ssh" << alb << porb << jenb << pasb;

    //alb = alamat;

    return rc;
}

int suruh::minta(char *orang, char *pase)
{
    rc = ssh_userauth_password(sesi_ssh, orang, pase);
    //otentikasi password
    if (rc != SSH_AUTH_SUCCESS)
    {
        rc = 9;
        //9 artinya bisa masuk tapi password salah;
    }
    else
    {

        rc = 8;
        //8 artinya bisa masuk;
        //qDebug() << alamat << orang << s_port << pase << sesi_ssh;
    }

    qDebug() << "minta" << alb << porb << jenb << pasb;
    return rc;
}

int suruh::otentikasi()
{
    pasuot *mintapas = new pasuot();
    //inisialisasi dialog untuk pasuot
    if (mintapas->exec())
    {
        QString alamat = mintapas->alamat();
        QString jeneng = mintapas->jeneng();
        QString pase = mintapas->pase();
        QString prot = mintapas->prot();
        //String dari QLineEdit
        qDebug() << alamat;

        QByteArray alba = alamat.toUtf8();
        QByteArray jenba = jeneng.toUtf8();
        QByteArray pasba = pase.toUtf8();
        //String diubah ke QByteArray

        char *albx = alba.data();
        char *jenbx = jenba.data();
        char *pasbx = pasba.data();
        int porbx = prot.toInt();
        //QByteArray diubah ke char
        qDebug() << alb;

        QMessageBox pesen;
        QPushButton *tombol = pesen.addButton(("uwis"), QMessageBox::ActionRole);
        //pesan koneksi

        rc = konek_ssh(albx, porbx);
        if (rc != SSH_OK)
        {
            rc = 7;
        }
        else {
            minta(jenbx, pasbx);


            qDebug() << alamat;
            qDebug() << alb;
            qDebug() << "otentikasi" << alb << porb << jenb << pasb;
            qDebug() << "otentikasi" << &alb << &porb << &jenb << &pasb;
            alb = albx;
            jenb = jenbx;
            pasb = pasbx;
            porb = porbx;

        }

        switch (rc) {
        case 9:
            pesen.setText("Salah password atau user, mbuh");
            pesen.exec();
            break;
        case 8:
            return 0;
            //pesen.setText("Alhamdulillah");
            //pesen.exec();
            break;
        case 7:
            pesen.setText("Kaga bisa konek lu");
            pesen.exec();
            break;
        default:
            break;
        }

        if (pesen.clickedButton() == tombol)
        {
            exit(0);
        }

        //qDebug() << alb << jenb << pasb << porb;
        //return 0;

    }
    else {
        return 1;
    }

    return 0;

}
