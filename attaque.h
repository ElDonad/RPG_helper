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
            double heal,
            int mpCost,
            int persistence,
            int charge,
            double degatsModifier,
            double armureModifier,
            double mpCostModifier,
            double absoModifier,
            int dodgeHitModifier,
            int critHitModifier,
            double critAttaqueModifier,
            QVector <int> effectsModifier,
            QVector <double> effectsLuck,
            QVector <int> permanentEffectsModifier,
            int attaqueId,
            int level,
            QString description = "Aucune description");
    

private :
    virtual void supActions();//actions supplémentaires.

    virtual void onSelected();//méthode devant être appelée quand l'attaque est sélectionnée dans le tableau des attaques

    QString m_description;
    int m_attaqueId;

    int m_degats;

    double m_heal;//en pourcentages

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
    QVector <double> m_effectsLuck;

    int m_charge;
    int m_level;
    QVector <int> m_permanentEffectModifier; //totem, speedy, yin et yang


public :
    QString returnName ();
    //void returnPermanentEffect (int effects []); quoi ??
    int returnEffectModifier (int effect);

    //acesseurs
    int getLevel();
    int getDegats();//fait
    double getHeal();//fait
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
    QVector <double> getEffectsLuck();//fait

    //utilitaires supplémentaires
    int getTotalPersistence();//fait
    //QVector <QString> returnSaveVector();

    int getId();
    QString getDescription();

};

#endif // ATTAQUE_H
