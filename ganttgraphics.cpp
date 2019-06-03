/*
    Qantt is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    HuwInterpreter is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with Qantt.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "ganttgraphics.h"

GanttGraphics::GanttGraphics()
{
    scene = new QGraphicsScene();
    reset();
}

GanttGraphics::GanttGraphics(QGraphicsScene *scene)
{
    this->scene = scene;
    reset();
}

void GanttGraphics::reset()
{
    start = QDate();
    end = QDate();
    headerHeight = 10;
    headerWidth = 20;
    positionX = 0;
    positionY = 0;

}

GanttGraphics::~GanttGraphics()
{
    delete scene;
}

void GanttGraphics::parse(QStandardItemModel *model, QGraphicsScene *scene)
{
    // Add more checks!

    reset();

    for (int r = 0; r < model->rowCount(); r++)
    {

        QDate start = model->index(r,1).data(Qt::DisplayRole).toDate();
        QDate end = model->index(r,2).data(Qt::DisplayRole).toDate();


        if (this->start > start || this->start.isNull())
        {
            if (start.isValid())
                this->start = start;
        }

        if (end > this->end || this->end.isNull())
        {
            if (end.isValid())
            this->end = end;
        }

    }
}

void GanttGraphics::addHeader(QGraphicsScene *scene)
{
    QBrush headerBrush(Qt::white);
    QPen headerPen(Qt::black);

    int i = 0;

    if (!start.isValid())
    {
        return;
    }
    if (!end.isValid())
    {
        return;
    }
    if (start > end)
    {
        return;
    }

    QDate current = start;
    QDate week = current;
    while (current <= end)
    {
        if (current.weekNumber() != week.weekNumber())
        {
            week = current;
            QGraphicsTextItem *item = new QGraphicsTextItem(current.toString("dd"));
            item->setPos(i*headerWidth+positionX,positionY);
            item->setPlainText(current.toString());
            scene->addItem(item);
        }

        QGraphicsTextItem *item = new QGraphicsTextItem();
        item->setPos(i*headerWidth+positionX,headerHeight+positionY);
        item->setPlainText(current.toString().at(0));
        scene->addItem(item);

        i++;
        current = current.addDays(qint64(1));
    }

    positionY += 30;
}

void GanttGraphics::addTasks(QStandardItemModel *model, QGraphicsScene *scene)
{
    QBrush headerBrush(Qt::black);
    QPen headerPen(Qt::black);

    if (!start.isValid())
    {
        return;
    }
    if (!end.isValid())
    {
        return;
    }
    if (start > end)
    {
        return;
    }

    for (int r = 0; r < model->rowCount(); r++)
    {
        QDate start = model->index(r,1).data(Qt::DisplayRole).toDate();
        QDate end = model->index(r,2).data(Qt::DisplayRole).toDate();

        if (start < end)
        {
            qreal toStart = this->start.daysTo(start);
            qreal toEnd = start.daysTo(end)+1;
            QGraphicsRectItem *taskRect = new QGraphicsRectItem(toStart*headerWidth+positionX,headerHeight*r+positionY,toEnd*headerWidth+1,headerHeight);
            taskRect->setPen(headerPen);
            taskRect->setBrush(headerBrush);
            scene->addItem(taskRect);
            positionY += 20;
        }
    }
}

QGraphicsScene *GanttGraphics::render(QStandardItemModel *model)
{
    scene->clear();
    parse(model,scene);
    addHeader(scene);
    addTasks(model,scene);
    return scene;
}

QGraphicsScene *GanttGraphics::render(QStandardItemModel *model, QGraphicsScene *scene)
{
    return render(model,scene);
}
