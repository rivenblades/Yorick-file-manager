#ifndef GRAPHICSFOLDERITEM_H
#define GRAPHICSFOLDERITEM_H
#include <QPainter>
#include <QGraphicsItem>
class GraphicsFolderItem : public QGraphicsItem
{
public:
    GraphicsFolderItem();
    QStringList labels;
    QPixmap pixmap;
    // QGraphicsItem interface
public:
    virtual QRectF boundingRect() const override;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // GRAPHICSFOLDERITEM_H
