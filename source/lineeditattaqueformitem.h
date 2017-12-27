#ifndef LINEEDITATTAQUEFORMITEM_H
#define LINEEDITATTAQUEFORMITEM_H

#include <attaqueformitem.h>

class AttaqueForm;
class LineEditAttaqueFormItem : public AttaqueFormItem
{
public:
    LineEditAttaqueFormItem(AttaqueForm *cible, QString label, QString *toReturn, QString DefaultValue = "");
    virtual void registerFormItem();
    virtual void returnValues(QString values);

private:
    QString m_defaultValue;
    QString* m_toReturn;
    QString m_label;
};

#endif // LINEEDITATTAQUEFORMITEM_H
