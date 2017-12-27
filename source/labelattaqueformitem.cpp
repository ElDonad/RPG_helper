#include "labelattaqueformitem.h"
#include <attaqueform.h>

LabelAttaqueFormItem::LabelAttaqueFormItem(AttaqueForm* cible, QString label)
{
    m_label = label;
    m_cible = cible;
}

void LabelAttaqueFormItem::registerFormItem()
{
    m_cible->addLabel(m_label);
}

void LabelAttaqueFormItem::returnValues()
{

}


