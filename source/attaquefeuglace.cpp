#include "attaquefeuglace.h"

AttaqueFeuGlace::AttaqueFeuGlace(
        Personnage *parent,
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
                    QString description = "Aucune description") : Attaque( parent,
                                                                           degats,
                                                                           nom,
                                                                           heal,
                                                                           mpCost,
                                                                           persistence,
                                                                           charge,
                                                                           degatsModifier,
                                                                           armureModifier,
                                                                           mpCostModifier,
                                                                           absoModifier,
                                                                           dodgeHitModifier,
                                                                           critHitModifier,
                                                                           critAttaqueModifier,
                                                                           effectsModifier,
                                                                           effectsLuck,
                                                                           permanentEffectsModifier,
                                                                           attaqueId,
                                                                           level,
                                                                           description),m_fire(m_form,"Feu (1 tr)",&m_fireSelected,false),
                                                                           m_glace(m_form,"Glace (3 trs)",&m_glaceSelected,false)
{

    QVector<AttaqueFormItem*>items;
    items.push_back(&m_fire);
    items.push_back(&m_glace);
    QString buffer = "Attaque Feu/glace";
    m_form = new AttaqueForm(items,buffer);
    m_fire.resetCible(m_form);
    m_glace.resetCible(m_form);
    m_fire.registerFormItem();
    m_glace.registerFormItem();

}

void AttaqueFeuGlace::onSelected()
{
    m_form->execute();
}
