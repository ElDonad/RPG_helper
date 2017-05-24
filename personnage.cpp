#include "personnage.h"

Personnage::Personnage(QObject *parent) : QObject(parent)
{
    m_vie = 100;
    m_vieMax = 100;
    m_mp = 50;
    m_mpMax = 50;

    //m_description = "Perso par défaut, pour les tests";
    m_nom = "Test";

    m_level = 1;
    m_isOnFire = m_isFrozen = m_isPoisoned = m_isStuned = false;
    m_isDeath = false;
}

Personnage::Personnage(int vie, int mp, QString nom, QString description, int level, QObject *parent) : QObject(parent)
{
    m_vie = vie;
    m_mp = mp;
    m_nom = nom;
    //m_description = description;
    m_level = level;

    m_isOnFire = m_isFrozen = m_isPoisoned = m_isStuned = false;
    m_isDeath = false;
}

void Personnage::setVie(int newVie){
    if (newVie <= m_vieMax && newVie>= 0)
    {
        m_vie = newVie;
    }
    else
    {
        m_vie = 0;
    }
}

Personnage::Personnage(QString path, QObject *parent) : QObject(parent) //constructeur à partir de fichier
{
    QVector <QString> donnees = getFile(path);
    int newVie = donnees[0].toInt();
    m_vie = newVie;

    int newMp = donnees[1].toInt();
    m_mp = newMp;

    int newVieMax = donnees[2].toInt();
    m_vieMax = newVieMax;

    int newMpMax = donnees[3].toInt();
    m_mpMax = newMpMax;

    m_nom = donnees[4];

    int newDefense = donnees[4].toInt();
    m_defense = newDefense;

    int newCritique = donnees[5].toInt();
    m_critique = newCritique;

    int newDodge = donnees[6].toInt();
    m_dodge = newDodge;

    int newAbsorption = donnees[7].toInt();
    m_absorption = newAbsorption;

    bool onFire = toBool(donnees[8]);
    m_isOnFire = onFire;

    bool poisonned = toBool(donnees[9]);
    m_isPoisoned = poisonned;

    bool frozen = toBool(donnees[10]);
    m_isFrozen = frozen;

    bool stunned = toBool(donnees[11]);
    m_isStuned = stunned;

    int newLevel = donnees[12].toInt();
    m_level = newLevel;
}

int Personnage::getVie()
{
    return m_vie;
}

void Personnage::setMp(int newMp)
{
    if (newMp <= m_mpMax && newMp>= 0)
    {
        m_mp = newMp;
    }
    else
    {
        m_mp = 0;
    }
}

int Personnage::getMp()
{
    return m_mp;
}

void Personnage::setVieBuffer(int newVieBuffer)
{
    m_vieBuffer = newVieBuffer;
}

int Personnage::getVieBuffer()
{
    return m_vieBuffer;
}

void Personnage::setMpBuffer(int newMpBuffer)
{
    m_mpBuffer = newMpBuffer;
}

int Personnage::getMpBuffer()
{
    return m_mpBuffer;
}

void Personnage::setCritique(int newCritique)
{
    if(newCritique >= 0)
    {
        m_critique = newCritique;
    }
}

int Personnage::getCritique()
{
    return m_critique;
}

void Personnage::setDodge(int newDodge)
{
    if (newDodge >= 0)
    {
        m_dodge = newDodge;
    }
}

int Personnage::getDodge()
{
    return m_dodge;
}

void Personnage::setDodgeBuffer(int newDodgeBuffer)
{
    if (m_dodgeBuffer + newDodgeBuffer >= 0 && m_dodgeBuffer + newDodgeBuffer <= 100)
    {
        m_dodgeBuffer = newDodgeBuffer;
    }
    else
    {
        m_dodgeBuffer = 0;
    }
}

int Personnage::getDodgeBuffer()
{
    return m_dodgeBuffer;
}

void Personnage::setCritiqueBuffer(int newCritiqueBuffer)
{
    if (m_critiqueBuffer + newCritiqueBuffer >= 0 && m_critiqueBuffer + newCritiqueBuffer <= 100)
    {
        m_critiqueBuffer = newCritiqueBuffer;
    }
    else
    {
        m_critiqueBuffer = 0;
    }
}

int Personnage::getCritiqueBuffer()
{
    return m_critiqueBuffer;
}



void Personnage::setDefense(int newDefense)
{
    m_defense = newDefense;
}

int Personnage::getDefense()
{
    return m_defense;
}

void Personnage::setDefenseBuffer(int newDefenseBuffer)
{
    m_defenseBuffer = newDefenseBuffer;
}

int Personnage::getDefenseBuffer()
{
    return m_defenseBuffer;
}

void Personnage::setVieMax(int newVieMax)
{
    if(newVieMax > 0)
    {
        m_vieMax = newVieMax;
    }
}

int Personnage::getVieMax()
{
    return m_vieMax;
}

void Personnage::setMpMax(int newMpMax)
{
    if (newMpMax > 0)
    {
        m_mpMax = newMpMax;
    }
}

int Personnage::getMpMax()
{
    return m_mpMax;
}

void Personnage::setName(QString newName)
{
    m_nom = newName;
}

QString Personnage::getName()
{
    return m_nom;
}


bool* Personnage::returnEffect(int effect) //private, en pointeur car cela permet à une métode d'influer directement sur la variable membre
{
    bool *cible;
    switch (effect) {
    case 1:
        cible = &m_isOnFire;
        break;

    case 2:
        cible = &m_isFrozen;
        break;

    case 3:
        cible = &m_isPoisoned;
        break;

    case 4:
        cible = &m_isStuned;
        break;
    default:
        break;
    }
    return cible;
}

int *Personnage::returnEffectTimer(int effect)
{
    int *cible;
    switch (effect) {
    case 1:
        cible = &m_fireTimer;
        break;

    case 2:
        cible = &m_frozenTimer;
        break;

    case 3:
        cible = &m_poisonTimer;
        break;

    case 4:
        cible = &m_stunTimer;
        break;
    default:
        break;
    }
    return cible;
}

void Personnage::toggleEffect(int effectNumber)
{
    bool *cible = returnEffect(effectNumber);
    int *cibleTimer = returnEffectTimer(effectNumber);
    if (*cible == true)
    {
        *cible = false;
        *cibleTimer = 0;

    }
    else if (*cible == false)
    {
        *cible = true;
    }
}

void Personnage::toggleEffect(int effectNumber, bool newState)
{
    bool *cible = returnEffect(effectNumber);
    *cible = newState;
}

bool Personnage::getEffect(int effect)
{
    bool *cible = returnEffect(effect);
    return *cible;
}

void Personnage::setLevel(int newLevel)
{
    if (newLevel<= 1 && newLevel >= 10)
    {
        m_level = newLevel;
    }
}

int Personnage::getLevel()
{
    return m_level;
}

void Personnage::save(QString filePath) //a finir...
{
    QVector <QString> merd;
    merd.push_back(m_nom);

    saveFile(merd, filePath);
}

QString Personnage::returnVieSurVieMax()
{
    QString vieQString = QString::number(m_vie);
    QString vieMaxQString = QString::number(m_vieMax);
    QString returnQString = vieQString + "/" + vieMaxQString;
    return returnQString;
}

int Personnage::returnPurcentVie()
{
    int purcent = m_vie * m_vieMax;
    purcent = purcent / 100;
    return purcent;
}



//Partie spécifique combat (général à tous les mobs)


int Personnage::getTotalCritique()
{
    int returnValue = m_critique + m_critiqueBuffer;
    return returnValue;
}

int Personnage::getTotalDodge()
{
    return m_dodge + m_dodgeBuffer;
}

int Personnage::getTotalDefense()
{
    return m_defense + m_defenseBuffer;
}

int Personnage::getTotalVie()
{
    return m_vie + m_vieBuffer;
}

int Personnage::getTotalMp()
{
    return m_mp + m_mpBuffer;
}

int Personnage::getTotalAbso()
{
    return m_absorption + m_absoptionBuffer;
}

void Personnage::degat(int degatCount)
{
    // à prendre en compte : vie totale, défense, abso
    /*int vie = this->getTotalVie();
    int absoTotale = this->getTotalAbso();
    vie =+ (absoTotale * vie) / 100;
    vie =+ this->getTotalDefense();*/

    int degatsFinaux = degatCount;
    int defense = this->getTotalDefense();
    degatsFinaux = degatsFinaux - defense;
    if (degatsFinaux > 0)
    {
        //abso
        int abso = this->getTotalAbso();
        while (abso > 0)
        {
            degatsFinaux --;
            abso--;
        }
    }
    if (degatsFinaux > 0)
    {
        m_vie =- degatsFinaux;
    }

    if (m_vie <= 0)
    {
        m_isDeath = true;
    }

}

void Personnage::levelUp() //variables à définir exactement avec Marin
{
    if (m_level < 10 && m_isDeath == false)
    {
        m_vieMax =+ (m_vieMax * 15)/100;
        m_mpMax =+ (m_vieMax * 10)/100;
        m_dodge =+ 2;
        m_critique =- 2;

    }

}

void Personnage::setTimer(int effectTimer, int value)
{
    int *cible = returnEffectTimer(effectTimer);
    *cible = value;
}

int Personnage::getTimer(int effectTimer)
{
    int *cible = returnEffectTimer(effectTimer);
    return *cible;
}

void Personnage::putOnEffect(int effect, int turnCount) // version finale de la fonction de set des effets
{
    bool* effectToggle = this->returnEffect(effect);
    int* effectTimer = this->returnEffectTimer(effect);

    if (*effectTimer > 0)
    {
        *effectToggle = true;
        if (*effectTimer < turnCount)
        {
           *effectTimer = turnCount;
        }
    }
}

void Personnage::newTurn()
{
    for (int loop = 1; loop == 4; loop++) //gestion des effets
    {
        bool *effectToggle = this->returnEffect(loop);
        int *effectTimer = this->returnEffectTimer(loop);

        if (*effectTimer > 0)
        {
            *effectTimer =- *effectTimer;
        }
        if (*effectTimer == 0)
        {
            *effectToggle = false;
        }

        if (*effectTimer > 0)
        {
            *effectToggle = true;
        }
    }
}

void Personnage::endFight()
{
    for (int loop = 1; loop == 4; loop++)
    {
        bool *effectToggle = this->returnEffect(loop);
        int *effectTimer = this->returnEffectTimer(loop);

        *effectTimer = 0;
        *effectToggle = false;
    }
}

