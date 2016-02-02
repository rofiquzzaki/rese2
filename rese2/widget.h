#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QApplication>
#include "suruh.h"

class QPushButton;
class QLabel;
class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    QLabel *l_os;
    QLabel *l_hostname;

private slots:
    void dipencet();
    void cekWs();
    void wsOn(bool cek);
    void nginxOn(bool cek);
    void mysqlOn(bool cek);
    void dc();
    void kon();
    void rst();
    void kstm();

signals:

private:
    QPushButton *t_uname;
    QPushButton *t_ws;
    QPushButton *t_wsOn;
    QPushButton *t_dc;
    QPushButton *t_kon;
    QPushButton *t_metu;
    QPushButton *t_rst;
    QPushButton *t_nOn;
    QPushButton *t_mati;
    QPushButton *t_mysql;
    QLineEdit *kastem;
    QPushButton *eksek;
    QString kstom() const;

    QLabel *l_ket;
    QLabel *l_apache;
    QLabel *l_nginx;
    QLabel *l_mysql;
    QLabel *l_server;
    QLabel *s_apache;
    QLabel *s_nginx;
    QLabel *s_mysql;
};

#endif // WIDGET_H
