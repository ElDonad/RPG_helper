#include "intspinboxattaqueformitem.h"
#include <attaqueform.h>

IntSpinBoxAttaqueFormItem::IntSpinBoxAttaqueFormItem(AttaqueForm *cible, QString label, int *toReturn, int defaultValue, int min, int max)
{
    m_cible = cible;
    m_defaultValue = defaultValue;
    m_itemType = AttaqueFormItem::IntSpinBoxItem;
    m_label = label;
    m_cible = cible;
    m_toReturn = toReturn;
    m_min = min;
    m_max = max;
}

void IntSpinBoxAttaqueFormItem::returnValues(int values)
{
    *m_toReturn = values;
}

void IntSpinBoxAttaqueFormItem::registerFormItem()
{
    m_cible->addIntSpinBoxItem(m_label,this,m_min,m_max,m_defaultValue);
}


