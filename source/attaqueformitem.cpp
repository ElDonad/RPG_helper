#include "attaqueformitem.h"



AttaqueFormItem::itemType AttaqueFormItem::getType()
{
    return m_itemType;
}

void AttaqueFormItem::resetCible(AttaqueForm *cible)
{
    m_cible = cible;
}
