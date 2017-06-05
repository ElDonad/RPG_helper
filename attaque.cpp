#include "attaque.h"

Attaque::Attaque()
{
    m_degats = 10;
    m_nom = "test";
    m_heal = 0;
    m_mpCost = 0;
    m_persistence = m_charge + 0;
    m_degatsModifier = 0;
    m_armureModifier = 0;
    m_mpCostModifier = 0;
    m_absoModifier = 0;
    m_dodgeModifier = 0;
    m_criticalModifier = 0;

    m_attaqueCritModifier = 1.20;
    m_effectsModifier.push_back(0);
    m_effectsModifier.push_back(0);
    m_effectsModifier.push_back(0);
    m_effectsModifier.push_back(0);

    m_charge = 0;

    m_permanentEffectModifier.push_back(0);
    m_permanentEffectModifier.push_back(0);
    m_permanentEffectModifier.push_back(0);
    m_permanentEffectModifier.push_back(0);

}

Attaque::Attaque(QVector <QString> saveVector)
{
    bool ok = false; //attention, il faut remplacer tous les toInt() par des toInt(&ok, 10)
    int degats = saveVector[0].toInt();
    m_degats = degats;

    m_nom = saveVector[1];

    int heal = saveVector[2].toInt();
    m_heal = heal;

    int mpCost = saveVector[3].toInt();
    m_mpCost = mpCost;

    int persistence = saveVector[4].toInt();
    m_persistence = persistence;

    double degatsModifier = saveVector[5].toDouble();
    m_degatsModifier = degatsModifier;

    double armureModifier = saveVector[6].toDouble();
    m_armureModifier = armureModifier;

    double mpCostModifier = saveVector[7].toDouble();
    m_mpCostModifier = mpCostModifier;

    double absoModifier = saveVector[8].toDouble();
    m_absoModifier = absoModifier;

    int dodgeHitModifier = saveVector[9].toInt();
    m_dodgeModifier = dodgeHitModifier;

    int critHitModifier = saveVector[10].toInt();
    m_criticalModifier = critHitModifier;

    double critModifier = saveVector[11].toDouble();
    m_attaqueCritModifier = critModifier;

    //effects
    int poison = saveVector[12].toInt();
    m_effectsModifier[0] = poison;

    int fire = saveVector[13].toInt();
    m_effectsModifier[1] = fire;

    int freeze = saveVector[14].toInt();
    m_effectsModifier[2] = freeze;

    int stun = saveVector[15].toInt();
    m_effectsModifier[3] = stun;

    int charge = saveVector[16].toInt();
    m_charge = charge;

    int permanentEffect1 = saveVector[17].toInt();
    m_permanentEffectModifier[0] = permanentEffect1;

    int permanentEffect2 = saveVector[18].toInt();
    m_permanentEffectModifier[1] = permanentEffect2;

    int permanentEffect3 = saveVector[19].toInt();
    m_permanentEffectModifier[2] = permanentEffect3;

    int permanentEffect4 = saveVector[20].toInt();
    m_permanentEffectModifier[3] = permanentEffect4;

    int attaqueId = saveVector[21].toInt();
    m_attaqueId = attaqueId;



}

Attaque::Attaque(int degats,
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
                 QVector<int> effectsModifier,
                 QVector<int> permanentEffectsModifier,
                 int attaqueId)
{
    m_degats = degats;
    m_heal = heal;
    m_nom = nom;
    m_mpCost = mpCost;
    m_persistence = persistence;
    m_degatsModifier = degatsModifier;
    m_armureModifier = armureModifier;
    m_mpCostModifier = mpCostModifier;
    m_absoModifier = absoModifier;
    m_dodgeModifier = dodgeHitModifier;
    m_criticalModifier = critHitModifier;
    m_attaqueCritModifier = critAttaqueModifier;
    m_effectsModifier = effectsModifier;
    m_permanentEffectModifier = permanentEffectsModifier;
    m_attaqueId = attaqueId;
}

int Attaque::returnEffectModifier(int effect)
{
    return m_effectsModifier[effect - 1]; //car effets commencent à 1, et les tableaux à 0
}

//acesseurs
int Attaque::getDegats()
{
    return m_degats;
}

int Attaque::getHeal()
{
    return m_heal;
}

int Attaque::getMpCost()
{
    return m_mpCost;
}

int Attaque::getPersistence()
{
    return m_persistence;
}

QString Attaque::getName()
{
    return m_nom;
}

double Attaque::getDegatsModifier()
{
    return m_degatsModifier;
}

double Attaque::getMpCostModifier()
{
    return m_mpCostModifier;
}

double Attaque::getArmureModifier()
{
    return m_armureModifier;
}

double Attaque::getAbsoModifier()
{
    return m_absoModifier;
}

int Attaque::getDodgeModifier()
{
    return m_dodgeModifier;
}

int Attaque::getCriticalModifier()
{
    return m_criticalModifier;
	
};

double Attaque::getAttaqueCritModifier()
{
    return m_attaqueCritModifier;
}

QVector <int> Attaque::getEffectsModifier()
{
    return m_effectsModifier;
}

int Attaque::getCharge()
{
    return m_charge;
}

QVector <int> Attaque::getPermanentEffectsModifier()
{
    return m_permanentEffectModifier;
}

int Attaque::getTotalPersistence()
{
    int aRetourner = m_charge + m_persistence;
    return aRetourner;
}

int Attaque::getId()
{
    return m_attaqueId;
}

