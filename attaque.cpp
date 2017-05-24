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
    m_mpCostBuffer = 0;
    m_absoModifier = 0;
    m_dodgeBuffer = 0;
    m_criticalBuffer = 0;

    m_attaqueCritBuffer = 1.20;
    m_attaqueDodgeBuffer = 0.80;
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

void Attaque::attaque(int de, Personnage &attaquant, Personnage &defenseur)
{
    //1. On vérifie si on a affaire à un crit ou pas
    bool isCrit = false;
    bool isDodge = false;

    int critAttaquant = attaquant.getTotalCritique();
    int dodgeAttaquant = attaquant.getTotalDodge();

    if (critAttaquant + de >= 100)
    {
        isCrit = true;
    };
    if (de - dodgeAttaquant <= 0)
    {
        isDodge = true;
    };
    //2. traitement éventuel du crit/dodge

    int degats = m_degats;
    int heal = m_heal;
    QVector <int> effects = m_effectsModifier;


    if (isCrit == true)
    {
        degats = degats*m_attaqueCritBuffer;
        heal = degats*m_attaqueCritBuffer;

        int loop = 0;
        while (loop < 4)
        {
            effects[loop] = effects[loop]*m_attaqueCritBuffer;

            loop++;
        }
    }

    if (isCrit == false)
    {
        degats = degats * m_attaqueDodgeBuffer;
        heal = degats * m_attaqueDodgeBuffer;

        int loop = 0;
        while (loop < 4)
        {
            effects[loop] = effects[loop] * m_attaqueDodgeBuffer;

            loop++;
        }
    }

    defenseur.degat(degats);
    defenseur.setVie(defenseur.getVie() + heal);

    //gestion des effets
    int loop = 0;
    while (loop < 4)
    {
        int effectBuffer = effects[loop];
        if (effectBuffer > 0)
        {
            defenseur.putOnEffect(effectBuffer, returnEffectModifier(loop + 1));
        }
    }


}

int Attaque::returnEffectModifier(int effect)
{
    return m_effectsModifier[effect - 1]; //car effets commencent à 1, et les tableaux à 0
}

