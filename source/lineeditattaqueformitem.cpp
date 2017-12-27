#include "lineeditattaqueformitem.h"
#include <attaqueform.h>

LineEditAttaqueFormItem::LineEditAttaqueFormItem(AttaqueForm *cible, QString label, QString *toReturn, QString DefaultValue)
{
    m_cible = cible;
    m_defaultValue = DefaultValue;
    m_itemType = AttaqueFormItem::LineEdit;
    m_label = label;
    m_cible = cible;
    m_toReturn = toReturn;
}

void LineEditAttaqueFormItem::returnValues(QString values)
{
    *m_toReturn = values;
}

void LineEditAttaqueFormItem::registerFormItem()
{
    m_cible->addLineEdit(m_label,this, m_defaultValue);
}
