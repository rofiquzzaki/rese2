#include "widget.h"
#include <QPushButton>
#include <QLabel>
#include <QApplication>
#include <QDebug>

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    t_uname = new QPushButton("uname", this);
    t_uname->setGeometry(10, 10, 80, 30);
    l_uname = new QLabel("idle", this);
    l_uname->setGeometry(10, 100, 500, 30);



    connect(t_uname, SIGNAL(clicked(bool)), this, SLOT(dipencet(bool)));

    //iseng
    //m_penghitung = 0;
    //connect(this, SIGNAL (hitunganKe()), QApplication::instance(), SLOT (quit()));
}

void Widget::dipencet(bool cek)
{

    suruh pr;

    //QString unem = "uname -a";
    //String dari QLineEdit

    //QByteArray unm = unem.toUtf8();
    //String diubah ke QByteArray

    //char *punm = unm.data();
    char *punm = "uname -a";
    //QByteArray diubah ke char

    //qDebug() << punm;
    if (pr.otentikasi() == 0)
    {
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

    //fungsinya masi salah nih

    //if (pr.ngakon() == )
    //asli
    //t_uname->setText("sapi");

    //iseng
    /*
        if (cek) {
            t_uname->setText("dicentang");
        } else {
            t_uname->setText("Hello Hell");
        }

        m_penghitung ++;
        if (m_penghitung == 10) {
            emit hitunganKe();
        }
        */
}
