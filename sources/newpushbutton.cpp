#include "headers/newpushbutton.h"
#include <QStylePainter>
#include <QStyleOptionButton>

void NewPushButton::SetIconPosition(Qt::Alignment Position)
{
    IconPosition = Position;
}

void NewPushButton::paintEvent(QPaintEvent *)
{
    QStylePainter p(this);
    QStyleOptionButton option;
    initStyleOption(&option);
    QRect Contents = style()->subElementRect(QStyle::SE_PushButtonContents, &option);

    if(IconPosition != Qt::AlignCenter)
    {
        Contents = QRect(Contents.x() + OFFSET, Contents.y() + OFFSET, Contents.width() - 2 * OFFSET, Contents.height() - 2 * OFFSET);
        p.drawControl(QStyle::CE_PushButtonBevel, option);
        p.drawPrimitive(QStyle::PE_FrameFocusRect, option);
        p.drawItemPixmap(Contents, IconPosition, icon().pixmap(iconSize()));
        p.drawItemText(Contents, Qt::AlignCenter, palette(), isEnabled(), text());
    }
    else
    {
        p.drawControl(QStyle::CE_PushButton, option);
    }

    Contents = style()->subElementRect(QStyle::SE_PushButtonContents, &option);
    if(IconPosition & Qt::AlignTop)
    {
        p.drawItemText(Contents, Qt::AlignBottom | Qt::AlignRight, palette(), isEnabled(), shortcut().toString());
    }
    else
    {
        p.drawItemText(Contents, Qt::AlignTop | Qt::AlignRight, palette(), isEnabled(), shortcut().toString());
    }
}
