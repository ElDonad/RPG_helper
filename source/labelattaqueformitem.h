#ifndef LABELATTAQUEFORMITEM_H
#define LABELATTAQUEFORMITEM_H

#include <attaqueformitem.h>

class AttaqueForm;
class LabelAttaqueFormItem : public AttaqueFormItem
{
public:
    LabelAttaqueFormItem(AttaqueForm *cible,QString label);
    virtual void returnValues();
    virtual void registerFormItem();

private:
    QString m_label;
    AttaqueForm* m_cible;
};

#endif // LABELATTAQUEFORMITEM_H
