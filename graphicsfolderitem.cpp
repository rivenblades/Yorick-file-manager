#include "graphicsfolderitem.h"

GraphicsFolderItem::GraphicsFolderItem()
{
pixmap = QPixmap("/home/kostas/Documents/Qt-projects/Yorick-File_Manager/folder_icon.png");
labels.push_back(QString("kostas"));
labels.push_back(QString("lena"));
setAcceptHoverEvents(true);
setFlags(ItemIsSelectable|ItemIsMovable);
}

QRectF GraphicsFolderItem::boundingRect() const{
    return QRectF(0,0,40,40);
}
void GraphicsFolderItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    int i=0,j=0;
    for (auto label : labels){
     painter->drawPixmap(i,j,40,40,pixmap);
     painter->drawText(QPointF(i,j+50),label);
     i+=45;
//     j+=45;
    }
}
