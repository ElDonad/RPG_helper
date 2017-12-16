#ifndef ATTAQUE_H
#define ATTAQUE_H

#include <QVector>
//#include <personnage.h>

class Personnage;

class Attaque
{
public:
    Attaque();
    Attaque(QVector <QString> saveVector);
    Attaque(Personnage *parent,
            int degats,
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
            QVector <int> effectsLuck,
            QVector <int> permanentEffectsModifier,
            int attaqueId,
            int level,
            QString description = "Aucune description");
    
    virtual QVector<QString> supActions();//actions supplémentaires.
    Personnage *m_parent;
    virtual QVector<QString> attaque(Personnage* cible);
    virtual void onSelected();//méthode devant être appelée quand l'attaque est sélectionnée dans le tableau des attaques

    //La classe attaque est de base divisée en plusieurs sous-modules modifiables à volonté.
    //Ces modules listés en dessous renvoient tous un tableau des messages qu'ils retournent.
    //
    //Les subdivisions de la classe attaque :
    //- basicAttaque s'occupe de faire du dégât et de retirer les points de mana
private :
    virtual QVector <QString> basicAttaque(Personnage *cible);
    virtual QVector <QString> healAttaque(Personnage *cible);
    virtual QVector <QString> effects(Personnage *cible);


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
    QVector <int> m_effectsLuck;

    int m_charge;
    int m_level;
    bool m_isInitialized;
    QVector <int> m_permanentEffectModifier; //totem, speedy, yin et yang


public :
    QString returnName ();
    //void returnPermanentEffect (int effects []); quoi ??
    int returnEffectModifier (int effect);

    //acesseurs
    int getLevel();
    QVector <QString> save();
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
    QVector<int> getEffectsLuck();//fait

    //utilitaires supplémentaires
    int getTotalPersistence();//fait
    //classe du schnaps pour fusionner deux vecteurs de QString
    void mergeQVector(QVector<QString> *toMerge, QVector<QString> toMergeWith);
    //QVector <QString> returnSaveVector();
    void newTurn();

    int getId();
    QString getDescription();
    void initialize();
    bool isInitialized();

};

#endif // ATTAQUE_H
