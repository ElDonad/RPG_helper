#ifndef BRIEFING_H
#define BRIEFING_H

#include <QDialog>
#include <QString>
#include <QVector>
#include <personnage.h>
#include <attaque.h>
#include <savetools.h>
#include <QDebug>

namespace Ui {
class Briefing;
}

class Briefing : public QDialog
{
    Q_OBJECT

public:
    explicit Briefing(QVector <QVector <Personnage*>>&ciblesAttaque,QVector <Attaque*> &attaquesSelected,QWidget *parent = 0);
    ~Briefing();

private:
    Ui::Briefing *ui;
    QVector <QVector <Personnage*>> m_cibles;
    QVector <Attaque*> m_attaques;
    void bakeTurn();
    void newEvent(QString event);
};

#endif // BRIEFING_H
