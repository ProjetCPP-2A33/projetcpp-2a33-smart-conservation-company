#ifndef DELEGATEDEUXBOUTTONS_H
#define DELEGATEDEUXBOUTTONS_H

#include <QStyledItemDelegate>

class delegateDeuxBouttons : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit delegateDeuxBouttons(QObject *parent = nullptr);

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index) override;

signals:
    void modifierClicked(int row);
    void supprimerClicked(int row);
};

#endif // DELEGATEDEUXBOUTTONS_H
