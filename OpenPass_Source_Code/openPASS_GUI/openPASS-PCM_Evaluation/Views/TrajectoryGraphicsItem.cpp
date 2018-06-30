#include "TrajectoryGraphicsItem.h"

TrajectoryGraphicsItem::TrajectoryGraphicsItem(QVector<QPointF> *trajectoryData,
                                               QPen pen,
                                               QGraphicsItem *parent) :
    QGraphicsItem(parent)
{
    if (trajectoryData == nullptr)
    {
        return;
    }

    for (int i = 1; i < trajectoryData->size(); i++)
    {
        QPointF firstPoint = trajectoryData->at(i - 1);
        QPointF secondPoint = trajectoryData->at(i);
        QGraphicsLineItem *line = new QGraphicsLineItem(QLineF(firstPoint,
                                                               secondPoint),
                                                        this);
        line->setPen(pen);

        minX = std::min(minX, std::min(firstPoint.x(), secondPoint.x()));
        minY = std::min(minY, std::min(firstPoint.y(), secondPoint.y()));
        maxX = std::max(maxX, std::max(firstPoint.x(), secondPoint.x()));
        maxY = std::max(maxY, std::max(firstPoint.y(), secondPoint.y()));

    }
}

QRectF TrajectoryGraphicsItem::boundingRect() const
{
    return QRectF(QPointF(minX, minY), QPointF(maxX, maxY));
}

void TrajectoryGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                                   QWidget *widget)
{
    Q_UNUSED(painter);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

