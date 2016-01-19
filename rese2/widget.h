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

private slots:
    void dipencet();
    void cekWs();
    void wsOn();
    void wsOff();
    void wsR();
    void dc();
    void kon();
    void rst();
    void kstm();

signals:

private:
    QPushButton *t_uname;
    QPushButton *t_ws;
    QPushButton *t_wsOn;
    QPushButton *t_wsOff;
    QPushButton *t_wsr;
    QPushButton *t_dc;
    QPushButton *t_kon;
    QPushButton *t_metu;
    QPushButton *t_rst;
    QLineEdit *kastem;
    QPushButton *eksek;
    QString kstom() const;
    QLabel *l_uname;
};

#endif // WIDGET_H
