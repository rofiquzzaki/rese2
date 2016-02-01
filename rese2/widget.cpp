#include "widget.h"

#include <QDebug>

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    //t_uname = new QPushButton("uname", this);
    l_uname = new QLabel("idle", this);

    //t_ws = new QPushButton("cek WS", this);
    t_wsOn = new QPushButton("WS On", this);
    t_wsOn->setCheckable(true);
    //t_wsOff = new QPushButton("WS Off", this);
    //t_wsr = new QPushButton("WS Restart", this);
    t_nOn = new QPushButton("nginx On", this);
    t_nOn->setCheckable(true);
    //t_nOff= new QPushButton("nginx Off", this);
    //t_nR = new QPushButton("Restart Ng", this);
    t_mysql = new QPushButton("MySQL", this);
    t_mysql->setCheckable(true);

    s_apache = new QLabel("berhenti");
    s_apache->setStyleSheet("QLabel { background-color : red; color : blue; }");
    s_nginx = new QLabel("berhenti");
    s_nginx->setStyleSheet("QLabel { background-color : red; color : blue; }");
    s_mysql = new QLabel("berhenti");
    s_mysql->setStyleSheet("QLabel { background-color : red; color : blue; }");
    
    t_mati = new QPushButton("Shutdown", this);
    l_apache = new QLabel("Apache");
    l_nginx = new QLabel("Nginx");
    l_mysql = new QLabel("MySQL");
    l_server = new QLabel("Server");

    t_dc = new QPushButton("Disconnect", this);
    //t_kon = new QPushButton("Konek", this);
    t_rst = new QPushButton("Restart", this);

    t_metu = new QPushButton("Keluar", this);

    kastem = new QLineEdit(this);
    eksek = new QPushButton("Eksekusi", this);

    //connect(t_uname, SIGNAL(clicked()), this, SLOT(dipencet()));

    //connect(t_ws, SIGNAL(clicked()), this, SLOT(cekWs()));
    connect(t_wsOn, SIGNAL(clicked(bool)), this, SLOT(wsOn(bool)));
    //connect(t_wsOff, SIGNAL(clicked()), this, SLOT(wsOff()));
    //connect(t_wsr, SIGNAL(clicked()), this, SLOT(wsR()));
    //connect(t_wsr, SIGNAL(clicked()), this, SLOT(wsOff()));
    //connect(t_wsr, SIGNAL(clicked()), this, SLOT(wsOn()));
    connect(t_nOn, SIGNAL(clicked(bool)), this, SLOT(nginxOn(bool)));
    //connect(t_nOff, SIGNAL(clicked()), this, SLOT(nginxOff()));
    //connect(t_nR, SIGNAL(clicked()), this, SLOT(nginxR()));
    connect(t_dc, SIGNAL(clicked()), this, SLOT(dc()));
    
    //connect(t_kon, SIGNAL(clicked()), this, SLOT(kon()));
    connect(t_rst, SIGNAL(clicked()), this, SLOT(rst()));
    connect(t_metu, SIGNAL(clicked()), this, SLOT(dc()));
    connect(t_metu, SIGNAL(clicked()), this, SLOT(close()));
    connect(eksek, SIGNAL(clicked()), this, SLOT(kstm()));



    QVBoxLayout *mein = new QVBoxLayout;

    QGroupBox *boks = new QGroupBox;
    QGridLayout *leot = new QGridLayout;
    //leot->addWidget(t_uname, 0, 0);
    leot->addWidget(l_uname, 0, 0);
    leot->addWidget(l_apache, 1, 0);
    //leot->addWidget(t_ws, 0, 1);
    leot->addWidget(s_apache, 1, 1);
    leot->addWidget(t_wsOn, 1, 2);
    //leot->addWidget(t_wsOff, 0, 3);
    //leot->addWidget(t_wsr, 0, 4);
    leot->addWidget(l_nginx, 2, 0);
    leot->addWidget(s_nginx, 2, 1);
    leot->addWidget(t_nOn, 2, 2);
    //leot->addWidget(t_nOff, 1, 3);
    //leot->addWidget(t_nR, 1, 4);
    leot->addWidget(l_mysql, 3, 0);
    leot->addWidget(s_mysql, 3, 1);
    leot->addWidget(t_mysql, 3, 2);
    leot->addWidget(t_dc, 5, 1);
    leot->addWidget(l_server, 4, 0);
    leot->addWidget(t_rst, 4, 1);
    leot->addWidget(t_mati, 4, 2);
    leot->addWidget(t_metu, 5, 2);
    leot->addWidget(kastem, 6, 0, 1, 2);
    leot->addWidget(eksek, 6, 2);
    boks->setLayout(leot);

    QGroupBox *boksa = new QGroupBox;
    QGridLayout *stata = new QGridLayout;
    //stata->addWidget(l_uname);
    boksa->setLayout(stata);

    mein->addWidget(boks);
    mein->addWidget(boksa);
    setLayout(mein);
}

void Widget::dipencet()
{

    suruh pr;

    const char *punm = "uname -a";

    qDebug() << "waha" << alb << porb << jenb << pasb;
    qDebug() << &alb << &porb << &jenb << &pasb;

    pr.ngakon(punm);
    /*
        qDebug() << "qd" << pr.otput;

        QString hasl = QString::fromUtf16((ushort*)(pr.otput));
        qDebug() << "str" << hasl;
        */
    //metune apik

    l_uname->setText(pr.otput);

}

void Widget::cekWs()
{
    suruh pr;
    const char *pws = "ps aux | grep 'apache\\|httpd\\|nginx'";
    pr.ngakon(pws);
    l_uname->setText(pr.otput);
}

void Widget::wsOn(bool cek)
{
    if (cek)
    {
        t_wsOn->setText("On");
        suruh pr;
        const char *pwsn = "service httpd start";
        const char *pwsg = "systemctl start httpd";
        pr.ngakon(pwsn);
        pr.ngakon(pwsg);
        l_uname->setText(pr.otput);
    }
    else
    {
        t_wsOn->setText("Off");
        suruh px;
        const char *pxws = "service httpd stop";
        const char *psds = "systemctl stop httpd";
        px.ngakon(pxws);
        px.ngakon(psds);
        l_uname->setText(px.otput);
    }
}

void Widget::wsOff()
{
    suruh pr;
    const char *pwsf = "service httpd stop";
    pr.ngakon(pwsf);
    l_uname->setText(pr.otput);
}

void Widget::wsR()
{
    suruh pr;
    const char *pwsr = "service httpd restart";
    pr.ngakon(pwsr);
    l_uname->setText(pr.otput);
}

void Widget::nginxOn(bool cek)
{
    if (cek)
    {
        t_nOn->setText("On");
        suruh pr;
        const char *pwsn = "service nginx start";
        const char *pqwe = "systemctl start nginx";
        pr.ngakon(pwsn);
        pr.ngakon(pqwe);
        l_uname->setText(pr.otput);
    }
    else
    {
        t_nOn->setText("Off");
        suruh px;
        const char *pxws = "service nginx stop";
        const char *pasq = "systemctl stop nginx";
        px.ngakon(pxws);
        px.ngakon(pasq);
        l_uname->setText(px.otput);
    }
}

void Widget::nginxOff()
{
    suruh pr;
    const char *noff = "service nginx stop";
    pr.ngakon(noff);
    l_uname->setText(pr.otput);
}

void Widget::nginxR()
{
    suruh pr;
    const char *nr = "service nginx restart";
    pr.ngakon(nr);
    l_uname->setText(pr.otput);
}

void Widget::dc()
{
    suruh pr;
    pr.diskonek();
    l_uname->setText("Diskonek");
}

void Widget::kon()
{
    suruh pr;
    pr.diskonek();
    pr.otentikasi();
    const char *punm = "uname -a";
    pr.ngakon(punm);
    l_uname->setText(pr.otput);
}

void Widget::rst()
{
    suruh pr;
    const char *rstr = "reboot";
    pr.ngakon(rstr);
    pr.diskonek();
}

QString Widget::kstom() const
{
    return kastem->text();
}

void Widget::kstm()
{
    suruh pr;
    //QString kast = this->kstom();
    QString kast = kastem->text();
    QByteArray kss = kast.toUtf8();
    const char *kstt = kss.data();
    pr.ngakon(kstt);
    l_uname->setText(pr.otput);
}
