#include "checkboxattaqueformitem.h"
#include "attaqueform.h"

CheckBoxAttaqueFormItem::CheckBoxAttaqueFormItem(AttaqueForm *cible, QString label, bool *toReturn, bool defaultValue)
{
    m_toReturn = toReturn;
    m_defaultValue = defaultValue;
    m_itemType = AttaqueFormItem::CheckBoxItem;
    m_label = label;
    m_cible = cible;
}

void CheckBoxAttaqueFormItem::registerFormItem()
{
    m_cible->addCheckBoxItem(m_label,this,m_defaultValue);
}

void CheckBoxAttaqueFormItem::returnValues(bool value)
{
    *m_toReturn = value;
}
