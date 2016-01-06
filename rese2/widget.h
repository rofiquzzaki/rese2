#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "suruh.h"

/*
extern ssh_session sesi_ssh;
extern char *alb;
extern int porb;
extern char *jenb;
extern char *pasb;
*/

class QPushButton;
class QLabel;
class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);

private slots:
    void dipencet(bool cek);

signals:
    void hitunganKe();

private:
    QPushButton *t_uname;
    QLabel *l_uname;
    int m_penghitung;

};

#endif // WIDGET_H
