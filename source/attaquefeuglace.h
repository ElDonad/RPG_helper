#ifndef ATTAQUEFEUGLACE_H
#define ATTAQUEFEUGLACE_H

#include "attaque.h"
#include <attaqueform.h>
#include <attaqueformitem.h>
#include <checkboxattaqueformitem.h>

#include <QString>
#include <QVector>

class AttaqueFormItem;
class CheckBoxAttaqueFormItem;
class AttaqueFeuGlace : public Attaque
{
public:
    AttaqueFeuGlace(Personnage *parent, int degats, QString nom, double heal, int mpCost, int persistence, int charge, double degatsModifier, double armureModifier, double mpCostModifier, double absoModifier, int dodgeHitModifier, int critHitModifier, double critAttaqueModifier, QVector<int> effectsModifier, QVector<int> effectsLuck, QVector<int> permanentEffectsModifier, int attaqueId, int level, QString description);
    virtual void onSelected();

private:
    AttaqueForm *m_form;
    CheckBoxAttaqueFormItem m_fire;
    CheckBoxAttaqueFormItem m_glace;

    bool m_fireSelected;
    bool m_glaceSelected;


};

#endif // ATTAQUEFEUGLACE_H
