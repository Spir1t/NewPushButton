#include "headers/newcheckbox.h"
#include <QStylePainter>
#include <QStyleOptionButton>

void NewCheckBox::SetOnIcon(QIcon Icon)
{
    OnIcon = Icon;
}

void NewCheckBox::SetOffIcon(QIcon Icon)
{
    OffIcon = Icon;
}

void NewCheckBox::SetParams()
{
    setCheckable(true);
    setStyleSheet("QPushButton "
                  "{"
                  "  background: none;"
                  "  border: none;"
                  "  color: black;"
                  "}"
                  "QPushButton:hover "
                  "{"
                  "  background: none;"
                  "}");
}

void NewCheckBox::paintEvent(QPaintEvent *)
{
    QStylePainter p(this);
    QStyleOptionButton opt;
    initStyleOption(&opt);
    if(isChecked())
    {
        setIcon(OnIcon);
        QRect Contents = rect();
        QRect TextRect = QRect(Contents.x() + icon().pixmap(iconSize()).rect().width() + SPACE_BETWEEN_ICON_AND_TEXT, Contents.y(), Contents.width() - icon().pixmap(iconSize()).rect().width(), Contents.height());

        p.drawItemPixmap(Contents, Qt::AlignLeft | Qt::AlignVCenter, icon().pixmap(iconSize()));
        p.drawItemText(TextRect, Qt::AlignLeft | Qt::AlignVCenter, palette(), isEnabled(), text());
        return;
    }
    else if(!isChecked())
    {
        setIcon(OffIcon);
        QRect Contents = rect();
        QRect TextRect = QRect(Contents.x() + icon().pixmap(iconSize()).rect().width() + SPACE_BETWEEN_ICON_AND_TEXT, Contents.y(), Contents.width() - icon().pixmap(iconSize()).rect().width(), Contents.height());

        p.drawItemPixmap(Contents, Qt::AlignLeft | Qt::AlignVCenter, icon().pixmap(iconSize()));
        p.drawItemText(TextRect, Qt::AlignLeft | Qt::AlignVCenter, palette(), isEnabled(), text());
        return;
    }
}

