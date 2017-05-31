#ifndef ATTAQUE_H
#define ATTAQUE_H

#include <QVector>


class Attaque
{
public:
    Attaque();
    Attaque(QVector <QString> saveVector);
    Attaque(int degats,
            QString nom,
            int heal,
            int mpCost,
            int persistence,
            double degatsModifier,
            double armureModifier,
            double mpCostModifier,
            double absoModifier,
            int dodgeHitModifier,
            int critHitModifier,
            double critAttaqueModifier,
            QVector <int> effectsModifier,
            QVector <int> permanentEffectsModifier);
    

private :
	int m_degats;

    int m_heal;

    int m_mpCost;
    int m_persistence;
    QString m_nom;

    //augmentation/baisse des dégâts (buffer)
    double m_degatsModifier;
    double m_mpCostModifier;


    double m_armureModifier;//influence le defense state
    double m_absoModifier;


    //augmentation/baisse du dodge/critique
    int m_dodgeModifier;
    int m_criticalModifier;

    double m_attaqueCritModifier;

    QVector <int> m_effectsModifier;
    int m_charge;
    QVector <int> m_permanentEffectModifier; //totem, speedy, yin et yang


public :
    QString returnName ();
    //void returnPermanentEffect (int effects []); quoi ??
    int returnEffectModifier (int effect);

    //acesseurs
    int getDegats();//fait
    int getHeal();//fait
    int getMpCost();//fait
    int getPersistence();//fait
    QString getName();//fait
    double getDegatsModifier(); //nombre à multiplier, fait
    double getMpCostModifier();//fait
    double getArmureModifier();//fait
    double getAbsoModifier();//fait
    int getDodgeModifier();//fait
    int getCriticalModifier();//fait
    double getAttaqueCritModifier();//fait
    QVector <int> getEffectsModifier();//fait
    int getCharge();//fait
    QVector <int> getPermanentEffectsModifier();//fait

    //utilitaires supplémentaires
    int getTotalPersistence();//fait
    QVector <QString> returnSaveVector();

};

#endif // ATTAQUE_H
