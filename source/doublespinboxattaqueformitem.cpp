#include "doublespinboxattaqueformitem.h"
#include <attaqueform.h>

DoubleSpinBoxAttaqueFormItem::DoubleSpinBoxAttaqueFormItem(AttaqueForm *cible, QString label, double *toReturn, double defaultValue, double min, double max)
{
    m_cible = cible;
    m_defaultValue = defaultValue;
    m_itemType = AttaqueFormItem::DoubleSpinBoxItem;
    m_label = label;
    m_cible = cible;
    m_toReturn = toReturn;
    m_min = min;
    m_max = max;
}

void DoubleSpinBoxAttaqueFormItem::returnValues(double value)
{
    *m_toReturn = value;
}

void DoubleSpinBoxAttaqueFormItem::registerFormItem()
{
    m_cible->addDoubleSpinBoxItem(m_label,this,m_min,m_max,m_defaultValue);
}
