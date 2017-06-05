#ifndef SETATTAQUE_H
#define SETATTAQUE_H

#include <QDialog>
#include <attaque.h>
#include <heros.h>
#include <personnage.h>
#include <QVector>
#include <QVector2D>

namespace Ui {
class setAttaque;
}

class setAttaque : public QDialog
{
    Q_OBJECT

public:
    explicit setAttaque(Personnage *attaquant,
                        QVector <Personnage*> ennemis,
                        QVector <Heros*> personnages,
                        QVector <Attaque*> &attaquesBuffer,
                        QVector <QVector<Personnage*>> &ciblesAttaque,
                        QWidget *parent = 0);
    ~setAttaque();

private:
    Ui::setAttaque *ui;
    QVector <Heros*> m_personnages;
    QVector <Personnage> m_ennemis;
    QVector <Attaque*> *m_attaquesBuffer;
    QVector <QVector<Personnage*>> *ciblesAttaque;

    /* à propos du tableau ciblesAttaque :
     * une colonne : une attaque
     * une ligne : une cible
     *
     * ex :
     *
     * Attaque1         Attaque2
     * *Personnage1     *Personnage1 */

};

#endif // SETATTAQUE_H
