#include "widget.h"
#include "ui_widget.h"
#include "suruh.h"
#include <QPushButton>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{

    ui->setupUi(this);


    t_uname = new QPushButton("uname", this);
    t_uname->setGeometry(10, 10, 80, 30);
    connect(t_uname, SIGNAL(clicked(bool)), this, SLOT(dipencet(bool)));

    //iseng
    m_penghitung = 0;
    connect(this, SIGNAL (hitunganKe()), QApplication::instance(), SLOT (quit()));



}

Widget::~Widget()
{
    delete ui;
}

void Widget::dipencet(bool cek)
{
    suruh pr;
    QString unem = "uname -a";
    //String dari QLineEdit

    QByteArray unm = unem.toUtf8();
    //String diubah ke QByteArray

    char *punm = unm.data();
    //QByteArray diubah ke char
    pr.ngakon(punm);
    //fungsinya masi salah nih

    if (pr.ngakon() == )
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
