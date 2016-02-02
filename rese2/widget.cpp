#include "widget.h"

#include <QDebug>

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    l_uname = new QLabel("idle", this);
    t_wsOn = new QPushButton("WS On", this);
    t_wsOn->setCheckable(true);
    t_nOn = new QPushButton("nginx On", this);
    t_nOn->setCheckable(true);
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
    t_rst = new QPushButton("Restart", this);

    t_metu = new QPushButton("Keluar", this);

    kastem = new QLineEdit(this);
    eksek = new QPushButton("Eksekusi", this);

    connect(t_wsOn, SIGNAL(clicked(bool)), this, SLOT(wsOn(bool)));
    connect(t_nOn, SIGNAL(clicked(bool)), this, SLOT(nginxOn(bool)));
    connect(t_mysql, SIGNAL(clicked(bool)), this, SLOT(mysqlOn(bool)));
    connect(t_dc, SIGNAL(clicked()), this, SLOT(dc()));
    connect(t_rst, SIGNAL(clicked()), this, SLOT(rst()));
    connect(t_metu, SIGNAL(clicked()), this, SLOT(dc()));
    connect(t_metu, SIGNAL(clicked()), this, SLOT(close()));
    connect(eksek, SIGNAL(clicked()), this, SLOT(kstm()));



    QVBoxLayout *mein = new QVBoxLayout;

    QGroupBox *boks = new QGroupBox;
    QGridLayout *leot = new QGridLayout;
    leot->addWidget(l_uname, 0, 0);
    leot->addWidget(l_apache, 1, 0);
    leot->addWidget(s_apache, 1, 1);
    leot->addWidget(t_wsOn, 1, 2);
    leot->addWidget(l_nginx, 2, 0);
    leot->addWidget(s_nginx, 2, 1);
    leot->addWidget(t_nOn, 2, 2);
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
    boksa->setLayout(stata);

    mein->addWidget(boks);
    mein->addWidget(boksa);
    setLayout(mein);
}

void Widget::dipencet()
{

    suruh pr;
    const char *punm = "uname -a";
    pr.ngakon(punm);
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
        t_wsOn->setText("Matiin");
        suruh pr;
        const char *pwsn = "service httpd start";
        const char *pwsg = "systemctl start httpd";
        pr.ngakon(pwsn);
        pr.ngakon(pwsg);
        s_apache->setText("Berjalan");
        s_apache->setStyleSheet("QLabel { background-color : #00ff00; color : black; }");
        //l_uname->setText(pr.otput);
    }
    else
    {
        t_wsOn->setText("Nyalain");
        suruh px;
        const char *pxws = "service httpd stop";
        const char *psds = "systemctl stop httpd";
        px.ngakon(pxws);
        px.ngakon(psds);
        s_apache->setText("Berhenti");
        s_apache->setStyleSheet("QLabel { background-color : red; color : black; }");
        //l_uname->setText(px.otput);
    }
}

void Widget::nginxOn(bool cek)
{
    if (cek)
    {
        t_nOn->setText("Matiin");
        suruh pr;
        const char *pwsn = "service nginx start";
        const char *pqwe = "systemctl start nginx";
        pr.ngakon(pwsn);
        pr.ngakon(pqwe);
        s_nginx->setText("Berhenti");
        s_nginx->setStyleSheet("QLabel { background-color : #00ff00; color : black; }");
        //l_uname->setText(pr.otput);
    }
    else
    {
        t_nOn->setText("Nyalain");
        suruh px;
        const char *pxws = "service nginx stop";
        const char *pasq = "systemctl stop nginx";
        px.ngakon(pxws);
        px.ngakon(pasq);
        s_nginx->setText("Berhenti");
        s_nginx->setStyleSheet("QLabel { background-color : red; color : black; }");
        //l_uname->setText(px.otput);
    }
}

void Widget::mysqlOn(bool cek)
{
    if (cek)
    {
        t_mysql->setText("Matiin");
        suruh pr;
        const char *psql = "service mysqld start";
        const char *psal = "systemctl start mysqld";
        pr.ngakon(psql);
        pr.ngakon(psal);
        s_mysql->setText("Berhenti");
        s_mysql->setStyleSheet("QLabel { background-color : #00ff00; color : black; }");
        //l_uname->setText(pr.otput);
    }
    else
    {
        t_mysql->setText("Nyalain");
        suruh px;
        const char *psss = "service mysqld stop";
        const char *psas = "systemctl stop mysqld";
        px.ngakon(psss);
        px.ngakon(psas);
        s_mysql->setText("Berhenti");
        s_mysql->setStyleSheet("QLabel { background-color : red; color : black; }");
        //l_uname->setText(px.otput);
    }
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
