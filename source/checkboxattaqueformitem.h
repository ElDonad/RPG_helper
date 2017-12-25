#ifndef CHECKBOXATTAQUEFORMITEM_H
#define CHECKBOXATTAQUEFORMITEM_H

#include <attaqueformitem.h>


class CheckBoxAttaqueFormItem : public AttaqueFormItem
{
public:
    CheckBoxAttaqueFormItem(QString label, bool defaultValue = false);
    bool returnValue();
    virtual QWidget* getWidget(QGridLayout layout, int value);

private:
    QString m_label;
    bool m_value;

};

#endif // CHECKBOXATTAQUEFORMITEM_H
