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

#ifndef GANTTGRAPHICS_H
#define GANTTGRAPHICS_H

#include <QRect>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QStandardItemModel>
#include <QDate>
#include <QDebug>

class GanttGraphics
{
public:
    explicit GanttGraphics();
    explicit GanttGraphics(QGraphicsScene *scene);
    ~GanttGraphics();
    QGraphicsScene *render(QStandardItemModel*);
    QGraphicsScene *render(QStandardItemModel*,QGraphicsScene*);
private:
    void reset();
    void parse(QStandardItemModel*,QGraphicsScene*);
    QGraphicsScene *scene;
    QDate start;
    QDate end;
    int positionX;
    int positionY;
    int headerWidth;
    int headerHeight;
    void addHeader(QGraphicsScene *);
    void addTasks(QStandardItemModel *, QGraphicsScene *);
};

#endif // GANTTGRAPHICS_H
