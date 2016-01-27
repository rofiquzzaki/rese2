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

int suruh::ngakon(const char *printah)
{
    char buffer[256] = {0};
    int nbytes;

    qDebug() << printah;
    qDebug() << alb << porb << jenb << pasb;
    qDebug() << &alb << &porb << &jenb << &pasb;

    if (sesi_ssh == NULL)
    {
        otentikasi();
        return rc;
    }
    else
    {
    ssh_channel channel;
    //channel bisa dibuat per perintah, karena channel tak terbatas

    channel = ssh_channel_new(sesi_ssh);
    //pembuatan channel

    rc = ssh_channel_open_session(channel);
    //nyambungke channel

    rc = ssh_channel_request_exec(channel, printah);
    //masukkan perintah
    //nbytes =
    ssh_channel_read(channel, buffer, sizeof(buffer), 0);

    while (nbytes > 0)
    {
        /*
      if (fwrite(buffer, 1, nbytes, stdout) != nbytes)
      {
        ssh_channel_close(channel);
        ssh_channel_free(channel);
        return SSH_ERROR;
      }
      */
      nbytes = ssh_channel_read(channel, buffer, sizeof(buffer), 0);
    }
    if (nbytes < 0)
    {
      ssh_channel_close(channel);
      ssh_channel_free(channel);
      //return SSH_ERROR;
    }


    strcpy(otput, buffer);
    //maca inputan, ceritane ngono
    qDebug() << buffer;

    ssh_channel_send_eof(channel);
    ssh_channel_close(channel);
    ssh_channel_free(channel);
    //channel ditutup
    return rc;
    }
}



int suruh::konek_ssh(char *alba, int porba)
{
    int rc;
    alb = alba;
    porb = porba;
    int verbosity = SSH_LOG_PROTOCOL;
    sesi_ssh = ssh_new();
    if (sesi_ssh == NULL)
        exit(-1);

    ssh_options_set(sesi_ssh, SSH_OPTIONS_HOST, alba);
    ssh_options_set(sesi_ssh, SSH_OPTIONS_LOG_VERBOSITY, &verbosity);

    if (porba == 0)
        porba = 22;
        porb = 22;
    //port kalo kaga diisi jadi 22

    ssh_options_set(sesi_ssh, SSH_OPTIONS_PORT, &porba);
    //inisialisasi sesi

    rc = ssh_connect(sesi_ssh);
    //konek ke sesi
    qDebug() << "konek ssh" << alb << porb << jenb << pasb;
    qDebug() << &alb << &porb << &jenb << &pasb;

    return rc;
}

int suruh::minta(char *jenba, char *pasba)
{
    jenb = jenba;
    pasb = pasba;
    rc = ssh_userauth_password(sesi_ssh, jenba, pasba);
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
    qDebug() << &alb << &porb << &jenb << &pasb;
    return rc;
}

int suruh::otentikasi()
{
    pasuot mintapas;
    //inisialisasi dialog untuk pasuot
    if (mintapas.exec())
    {
        QString alamat = mintapas.alamat();
        QString jeneng = mintapas.jeneng();
        QString pase = mintapas.pase();
        QString prot = mintapas.prot();
        //String dari QLineEdit
        qDebug() << alamat;

        QByteArray alba = alamat.toUtf8();
        QByteArray jenba = jeneng.toUtf8();
        QByteArray pasba = pase.toUtf8();
        //String diubah ke QByteArray

        char *alb = alba.data();
        char *jenb = jenba.data();
        char *pasb = pasba.data();
        int porb = prot.toInt();
        //QByteArray diubah ke char
        qDebug() << alb;

        QMessageBox pesen;
        QPushButton *tombol = pesen.addButton(("keluar"), QMessageBox::ActionRole);
        //pesan koneksi

        rc = konek_ssh(alb, porb);
        qDebug() << "barkonek" << alb << porb << jenb << pasb;
        if (rc != SSH_OK)
        {
            rc = 7;
        }
        else {
            minta(jenb, pasb);
            qDebug() << "barminta" << alb << porb << jenb << pasb;


            qDebug() << alamat;
            qDebug() << alb;
            qDebug() << "otentikasi" << alb << porb << jenb << pasb;
            qDebug() << "otentikasi" << &alb << &porb << &jenb << &pasb;

        }

        switch (rc) {
        case 9:
            pesen.setText("Salah password atau user");
            pesen.exec();
            break;
        case 8:
            return 0;
            //pesen.setText("Alhamdulillah");
            //pesen.exec();
            break;
        case 7:
            pesen.setText("Server tidak terjangkau");
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

void suruh::diskonek()
{
    ssh_disconnect(sesi_ssh);
    ssh_free(sesi_ssh);
    sesi_ssh = NULL;
}
