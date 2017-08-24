#ifndef INFOSPERSOS_H
#define INFOSPERSOS_H

#include <QDialog>
#include <personnage.h>
#include <QString>
#include <QVector>

namespace Ui {
class InfosPersos;
}

class InfosPersos : public QDialog
{
    Q_OBJECT

public:
    explicit InfosPersos(Personnage *info, QWidget *parent = 0);
    ~InfosPersos();

private slots:
    void on_checkBox_clicked(bool checked);

    void on_pushButton_clicked();

private:
    Ui::InfosPersos *ui;
    Personnage *m_info;
};

#endif // INFOSPERSOS_H
