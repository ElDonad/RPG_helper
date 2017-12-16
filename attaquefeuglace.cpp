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
                                                                           description)
{

}
