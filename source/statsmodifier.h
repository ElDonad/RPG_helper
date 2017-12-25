#ifndef STATSMODIFIER_H
#define STATSMODIFIER_H

#include <QDialog>
#include <heros.h>
#include <QString>
#include <QVector>

namespace Ui {
class StatsModifier;
}

class StatsModifier : public QDialog
{
    Q_OBJECT

public:
    explicit StatsModifier(Personnage &cible, QWidget *parent = 0);
    ~StatsModifier();
signals :
    void truc();

private slots:
    void on_pushButton_clicked();

    void on_maxVieSpinBox_valueChanged(int arg1);

    void on_maxMpSpinBox_valueChanged(int arg1);

    void on_pushButton_2_clicked();

private:
    Ui::StatsModifier *ui;
    Personnage *m_cible;

};

#endif // STATSMODIFIER_H
