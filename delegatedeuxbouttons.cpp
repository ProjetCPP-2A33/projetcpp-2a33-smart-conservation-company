#include "delegateDeuxBouttons.h"
#include <QPushButton>
#include <QPainter>
#include <QMouseEvent>

delegateDeuxBouttons::delegateDeuxBouttons(QObject *parent)
    : QStyledItemDelegate(parent)
{
}

void delegateDeuxBouttons::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{int buttonSpacing = 8;
    if (index.column() == index.model()->columnCount() - 1) {
        //  Modifier boutton
        QRect modifierRect = option.rect.adjusted(0, 0, -option.rect.width() / 2 - buttonSpacing / 2, 0);
        painter->save();
        painter->setPen(Qt::NoPen);
        painter->setBrush(Qt::blue);
        painter->drawRect(modifierRect);
        painter->setPen(Qt::white);
        painter->drawText(modifierRect, Qt::AlignCenter, "Modifier");
        painter->restore();

        // Supprimer boutton
        QRect supprimerRect = option.rect.adjusted(option.rect.width() / 2, 0, 0, 0);

        painter->save();
        painter->setPen(Qt::NoPen);
        painter->setBrush(Qt::red);
        painter->drawRect(supprimerRect);
        painter->setPen(Qt::white);
        painter->drawText(supprimerRect, Qt::AlignCenter, "Supprimer");
        painter->restore();
    } else {
        QStyledItemDelegate::paint(painter, option, index);
    }
}

bool delegateDeuxBouttons::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
{
    if (event->type() == QEvent::MouseButtonRelease && index.column() == index.model()->columnCount() - 1) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        int row = index.row();
        int buttonWidth = option.rect.width() / 2;

        if (mouseEvent->pos().x() < option.rect.left() + buttonWidth) {
            emit modifierClicked(row);
        } else {
            emit supprimerClicked(row);
        }
        return true;
    }
    return QStyledItemDelegate::editorEvent(event, model, option, index);
}
