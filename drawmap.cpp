#include "drawmap.h"
#include <QGraphicsItem>
#include <QPoint>
#include <QGraphicsSceneMouseEvent>
#include <QLineF>
#include <QDebug>
DrawBlock::DrawBlock(QGraphicsScene *Scene)
{
    this->setRect(0,0,50,50);
    this->setBrush(Qt::blue);
    linelist.append(new QGraphicsLineItem());
    linelist.append(new QGraphicsLineItem());
    linelist.append(new QGraphicsLineItem());
    linelist.append(new QGraphicsLineItem());

    this->setFlags(QGraphicsItem::ItemIsMovable);
    this->AddItemToScene(Scene);
    foreach(QGraphicsItem *a,this->drawline())
    {
        this->AddItemToScene(Scene,a);
    }
    blockList.append(this);
}
QList<DrawBlock*> DrawBlock ::  blockList;
int DrawBlock::randomPos(int hi, int low)
{
    return (qrand() % ((hi + 1) - low) + low);
}

QList<QPointF*>* DrawBlock::getVertex()
{
    QList<QPointF*> *tmp = new QList<QPointF*> ;
    tmp->append(new QPointF(this->pos()));//vertex top left
    tmp->append(new QPointF(this->pos().x()+50,this->pos().y()));//vertex top right
    tmp->append(new QPointF(this->pos().x(),this->pos().y()+50));//vertex top right
    tmp->append(new QPointF(this->pos().x()+50,this->pos().y()+50));//vertex top right
    return tmp;

}

QList<QGraphicsLineItem*> DrawBlock::drawline()
{
    QLineF line1 , line2 , line3 ,line4;
    line1.setLine(getVertex()->at(0)->x()
                 ,getVertex()->at(0)->y()
                 ,getVertex()->at(0)->x()
                 ,0);
    line2.setLine(getVertex()->at(1)->x()
                 ,getVertex()->at(1)->y()
                 ,getVertex()->at(1)->x()
                 ,0);
    line3.setLine(getVertex()->at(2)->x()
                 ,getVertex()->at(2)->y()
                 ,getVertex()->at(2)->x()
                 ,600);
    line4.setLine(getVertex()->at(3)->x()
                 ,getVertex()->at(3)->y()
                 ,getVertex()->at(3)->x()
                 ,600);
    linelist.at(0)->setLine(line1);
    linelist.at(1)->setLine(line2);
    linelist.at(2)->setLine(line3);
    linelist.at(3)->setLine(line4);
    return linelist;

}

void DrawBlock::AddItemToScene(QGraphicsScene *Map)
{
    Map->addItem(this);
    this->setPos((int)this->randomPos(0,200)
                 ,(int)this->randomPos(0,200));
}

void DrawBlock::AddItemToScene(QGraphicsScene *Map,QGraphicsItem *item)
{
    Map->addItem(item);
}

void DrawBlock::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
   if( (mapToScene(event->pos()).x() >= 25 && mapToScene(event->pos()).x() <= 575) && (mapToScene(event->pos()).y() >= 25 && mapToScene(event->pos()).y() <= 575)  )
   {
   this->drawline();
   this->setBrush(Qt::red);
   this->setPos(mapToScene(event->pos().x()-25,event->pos().y()-25));
   }
    Q_UNUSED(event);
}

void DrawBlock::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    drawline();
    this->setBrush(Qt::blue);
    Q_UNUSED(event);
}


