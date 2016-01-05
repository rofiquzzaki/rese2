#ifndef PASUOT_H
#define PASUOT_H

#include <QDialog>

class QLineEdit;
class pasuot : public QDialog
{
    Q_OBJECT
public:
    explicit pasuot(QWidget *parent = 0);
    QString alamat() const;
    QString jeneng() const;
    QString pase() const;
    QString prot() const;

private:
    QLineEdit *almt;
    QLineEdit *nama;
    QLineEdit *kunci;
    QLineEdit *poret;

signals:

public slots:
};
#endif // PASUOT_H
