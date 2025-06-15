#ifndef NEWCHECKBOX_H
#define NEWCHECKBOX_H

#include <QObject>
#include <QPushButton>

#define SPACE_BETWEEN_ICON_AND_TEXT 3

class NewCheckBox : public QPushButton
{
Q_OBJECT

public:
    NewCheckBox(QWidget *parent = nullptr) : QPushButton(parent) {SetParams();}
    NewCheckBox(const QString &text, QWidget *parent = nullptr) : QPushButton(text, parent) {SetParams();}
    NewCheckBox(const QIcon &icon, const QString &text, QWidget *parent = nullptr) : QPushButton(icon, text, parent) {SetParams();}
    void SetOnIcon(QIcon Icon);
    void SetOffIcon(QIcon Icon);

protected:
    void paintEvent(QPaintEvent *) override;

private:
    void SetParams();
    QIcon OnIcon = QIcon(":/CheckBoxOnDefault.png");
    QIcon OffIcon = QIcon(":/CheckBoxOffDefault.png");
};

#endif // NEWCHECKBOX_H
