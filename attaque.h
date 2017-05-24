#ifndef ATTAQUE_H
#define ATTAQUE_H

#include <personnage.h>
#include <heros.h>
#include <QVector>


class Attaque
{
public:
    Attaque();
    void makeAttaque(Personnage &cible);

private :
    int m_degats;

    int m_heal;

    int m_mpCost;
    int m_persistence;
    QString m_nom;

    //augmentation/baisse des dégâts (buffer)
    int m_degatsModifier;
    int m_mpCostBuffer;


    int m_armureModifier; //influence le defense state
    int m_absoModifier;


    //augmentation/baisse du dodge/critique
    int m_dodgeBuffer;
    int m_criticalBuffer;

    float m_attaqueCritBuffer;
    float m_attaqueDodgeBuffer;

    QVector <int> m_effectsModifier;
    int m_charge;
    QVector <int> m_permanentEffectModifier; //totem, speedy, yin et yang


public :
    void attaque (int de, Personnage &attaquant, Personnage &defenseur);
    QString returnName ();
    //void returnPermanentEffect (int effects []); quoi ??
    int returnEffectModifier (int effect);



};

#endif // ATTAQUE_H
