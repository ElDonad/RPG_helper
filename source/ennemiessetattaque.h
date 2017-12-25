#ifndef ENNEMIESSETATTAQUE_H
#define ENNEMIESSETATTAQUE_H

#include <QDialog>

namespace Ui {
class EnnemiesSetAttaque;
}

class EnnemiesSetAttaque : public QDialog
{
    Q_OBJECT

public:
    explicit EnnemiesSetAttaque(QWidget *parent = 0);
    ~EnnemiesSetAttaque();

private:
    Ui::EnnemiesSetAttaque *ui;
};

#endif // ENNEMIESSETATTAQUE_H
