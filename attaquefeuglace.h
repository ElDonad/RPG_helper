#ifndef ATTAQUEFEUGLACE_H
#define ATTAQUEFEUGLACE_H

#include "attaque.h"

class AttaqueFeuGlace : public Attaque
{
public:
    AttaqueFeuGlace(Personnage *parent, int degats, QString nom, double heal, int mpCost, int persistence, int charge, double degatsModifier, double armureModifier, double mpCostModifier, double absoModifier, int dodgeHitModifier, int critHitModifier, double critAttaqueModifier, QVector<int> effectsModifier, QVector<int> effectsLuck, QVector<int> permanentEffectsModifier, int attaqueId, int level, QString description);
};

#endif // ATTAQUEFEUGLACE_H
