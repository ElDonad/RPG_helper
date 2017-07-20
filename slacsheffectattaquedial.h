#ifndef SLACSHEFFECTATTAQUEDIAL_H
#define SLACSHEFFECTATTAQUEDIAL_H

#include <QDialog>
#include <QVector>

namespace Ui {
class SlacshEffectAttaqueDial;
}

class SlacshEffectAttaqueDial : public QDialog
{
    Q_OBJECT

public:
    explicit SlacshEffectAttaqueDial(QVector <int> *effets,QWidget *parent = 0);
    ~SlacshEffectAttaqueDial();

private slots:
    void on_pushButton_clicked();

private:
    Ui::SlacshEffectAttaqueDial *ui;

    QVector <int> *m_effects;
};

#endif // SLACSHEFFECTATTAQUEDIAL_H
