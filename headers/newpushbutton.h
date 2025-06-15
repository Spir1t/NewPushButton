#ifndef NEWPUSHBUTTON_H
#define NEWPUSHBUTTON_H

#include <QPushButton>

#define OFFSET 2

class NewPushButton : public QPushButton
{
Q_OBJECT

public:
    NewPushButton(QWidget *parent = nullptr) : QPushButton(parent) {}
    NewPushButton(const QString &text, QWidget *parent = nullptr) : QPushButton(text, parent) {}
    NewPushButton(const QIcon &icon, const QString &text, QWidget *parent = nullptr) : QPushButton(icon, text, parent) {}
    void SetIconPosition(Qt::Alignment Position = Qt::AlignCenter);

protected:
    virtual void paintEvent(QPaintEvent *) override;

private:
    Qt::Alignment IconPosition = Qt::AlignCenter;
};

#endif // NEWPUSHBUTTON_H
