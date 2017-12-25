#ifndef CHECKBOXATTAQUEFORMITEM_H
#define CHECKBOXATTAQUEFORMITEM_H

#include <attaqueformitem.h>
//#include <attaqueform.h>

class AttaqueForm;
class CheckBoxAttaqueFormItem : public AttaqueFormItem
{
public:
    CheckBoxAttaqueFormItem(AttaqueForm *cible, QString label,bool*toReturn, bool defaultValue = 0);
    virtual void registerFormItem();
    virtual void returnValues(bool value);

private:
    bool m_defaultValue;
    bool *m_toReturn;
    QString m_label;
};

#endif // CHECKBOXATTAQUEFORMITEM_H
