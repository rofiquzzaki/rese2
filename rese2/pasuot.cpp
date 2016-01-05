#include "pasuot.h"
#include <QLineEdit>
#include <QPushButton>
#include <QDialogButtonBox>
#include <QVBoxLayout>

pasuot::pasuot(QWidget *parent) : QDialog(parent)
{
    almt = new QLineEdit(this);
    nama = new QLineEdit(this);
    kunci = new QLineEdit(this);
    poret = new QLineEdit(this);

    QPushButton *pass_in = new QPushButton(tr("Masuk"));
    pass_in->setDefault(true);

    QPushButton *gagal = new QPushButton(tr("rasido"));

    QDialogButtonBox *buttonBox = new QDialogButtonBox(Qt::Horizontal);
    buttonBox->addButton(pass_in, QDialogButtonBox::AcceptRole);
    buttonBox->addButton(gagal, QDialogButtonBox::RejectRole);

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

    QVBoxLayout *posisi = new QVBoxLayout;
    posisi->addWidget(almt);
    posisi->addWidget(nama);
    posisi->addWidget(kunci);
    posisi->addWidget(poret);
    posisi->addWidget(buttonBox);

    setLayout(posisi);
}

QString pasuot::alamat() const
{
    return almt->text();
}

QString pasuot::jeneng() const
{
    return nama->text();
}

QString pasuot::pase() const
{
    return kunci->text();
}

QString pasuot::prot() const
{
    return poret->text();
}
