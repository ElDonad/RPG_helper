#include "attaque.h"
#include "personnage.h"

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
    m_isInitialized = false;

}

Attaque::Attaque(QVector <QString> saveVector)
{
    bool ok = false; //attention, il faut remplacer tous les toInt() par des toInt(&ok, 10)
    m_isInitialized = false;
    int degats = saveVector[0].toInt();
    m_degats = degats;

    m_nom = saveVector[1];

    double heal = saveVector[2].toDouble();
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

Attaque::Attaque(Personnage* parent,
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
                 QVector<int> effectsModifier,
                 QVector<int> effectsLuck,
                 QVector<int> permanentEffectsModifier,
                 int attaqueId,
                 int level,
                 QString description)
{
    m_parent = parent;
    m_degats = degats;
    m_heal = heal;
    m_nom = nom;
    m_mpCost = mpCost;
    m_persistence = persistence + charge;
    m_charge = charge;
    m_degatsModifier = degatsModifier;
    m_armureModifier = armureModifier;
    m_mpCostModifier = mpCostModifier;
    m_absoModifier = absoModifier;
    m_dodgeModifier = dodgeHitModifier;
    m_criticalModifier = critHitModifier;
    m_attaqueCritModifier = critAttaqueModifier;
    m_effectsModifier = effectsModifier;
    m_effectsLuck = effectsLuck;
    m_permanentEffectModifier = permanentEffectsModifier;
    m_attaqueId = attaqueId;
    m_level = level;
    m_description = description;
    m_isInitialized = false;
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

double Attaque::getHeal()
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

QVector <int> Attaque::getEffectsLuck()
{
    return m_effectsLuck;
}

QString Attaque::getDescription()
{
    return m_description;
}

int Attaque::getLevel()
{
    return m_level;
}

void Attaque::newTurn()
{
    m_persistence--;
}

void Attaque::initialize()
{
    m_isInitialized = true;
}

bool Attaque::isInitialized()
{
    return m_isInitialized;
}

QVector <QString> Attaque::save()
{
    QVector<QString> save;

    save.push_back(QString::number(m_degats));
    save.push_back(m_nom);
    save.push_back(QString::number(m_heal));
    save.push_back(QString::number(m_mpCost));
    save.push_back(QString::number(m_persistence));
    save.push_back(QString::number(m_degatsModifier));
    save.push_back(QString::number(m_armureModifier));
    save.push_back(QString::number(m_mpCostModifier));
    save.push_back(QString::number(m_absoModifier));
    save.push_back(QString::number(m_dodgeModifier));
    save.push_back(QString::number(m_criticalModifier));
    save.push_back(QString::number(m_attaqueCritModifier));

    int loop = 0;
    while (loop != 4)
    {
        save.push_back(QString::number(m_effectsModifier[loop]));
        save.push_back(QString::number(m_effectsLuck[loop]));
        loop++;
    }
    save.push_back(QString::number(m_charge));
    save.push_back(QString::number(m_attaqueId));
    //en tout, 22 lignes de save
}

void Attaque::onSelected()
{
    return;
}

QVector<QString> Attaque::supActions()
{
    QVector<QString> messages;
    return messages;
}

QVector<QString> Attaque::attaque(Personnage *cible)
{
    QVector <QString> messages;
    if (m_parent->is_death() == false)
    {
        Attaque::mergeQVector(&messages, Attaque::basicAttaque(cible));
    }
    return messages;
}

QVector <QString> Attaque::basicAttaque(Personnage *cible)
{
    QVector <QString> messages;
    int de = (-50) + (rand() % static_cast<int>(50 - (-50) + 1));
    messages.push_back("Jet de dé. Résultat : " + QString::number(de));
    int totalDodge = cible->getTotalDodgeHit();
    if (de > totalDodge && m_parent->getMp() >= m_mpCost && m_parent->getEffect(4) == false)
    {
        double degats = static_cast <double> (m_degats);
        degats = degats * m_parent->getLevel();
        degats = degats * (1 + de/1000);
        degats = degats * (m_parent->getDegats() + m_parent->getDegatsBuffer());
        int totalCritique = m_parent->getTotalCriticalHit() + m_criticalModifier;
        if (de > totalCritique)
        {
            degats = degats * m_criticalModifier;
            messages.push_back("<span style=\"color: #993366;\">Coup critique !</span>");
        }
        QVector <QString> retourCible = cible->degat(static_cast <int> (degats));
        messages.push_back("<span style=\"color:Blue;\">" + cible->getName() + " a reçu " + QString::number(static_cast <int> (degats)) + " dégâts.</span>");
        int loop = 0;
        while (loop != retourCible.count())
        {
            messages.push_back(retourCible[loop]);
            loop++;
        }
        m_parent->setMp(m_parent->getMp() - m_mpCost);
        mergeQVector(&messages, this->healAttaque(cible));
        mergeQVector(&messages, this->effects(cible));

    }
    return messages;
}

void Attaque::mergeQVector(QVector <QString> *toMerge,QVector <QString> toMergeWith)
{
    int a = 0;
    while (a < toMergeWith.size())
    {
        toMerge->push_back(toMergeWith[a]);
        a++;
    }
}

QVector<QString> Attaque::effects(Personnage *cible)
{
    QVector <QString> messages;
    for (int i = 0; i == 3; i++)
    {
        if (m_effectsModifier[i] > 0)
            cible->putOnEffect(i + 1, m_effectsModifier[i]);
        switch (i)
        {
            case 0:
                messages.push_back("<span style=\"color:Green;\">" + cible->getName() + " a été mis en feu pour " + QString::number(cible->getTimer(1)) + "tour(s) !</span>");
            break;
            case 1:
                messages.push_back("<span style=\"color:Green;\">" + cible->getName() + " a été glacé pour " + QString::number(cible->getTimer(2)) + "tour(s) !</span>");
            break;
            case 2:
                messages.push_back("<span style=\"color:Green;\">" + cible->getName() + " a été empoisonné pour " + QString::number(cible->getTimer(3)) + "tour(s) !</span>");
            break;
            case 3:
                messages.push_back("<span style=\"color:Green;\">" + cible->getName() + " a été stun pour " + QString::number(cible->getTimer(4)) + "tour(s) !</span>");
            break;
        }
    }
    return messages;

}

QVector<QString> Attaque::healAttaque(Personnage *cible)
{
    QVector<QString> messages;
    cible->setVie(cible->getVie() + m_heal);
    if (m_heal > 0)
        messages.push_back("<span style=\"color:Blue;\">" + cible->getName() + " a été healé à hauteur de " + QString::number(m_heal) + "PV ! Sa vie est maintenant de " + cible->getVie() + " PV.</span>");
    return messages;
}
