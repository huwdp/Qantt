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

#include "fileio.h"

FileIO::FileIO(QObject *parent) :
    QObject(parent)
{
    version = 0.0001;
    headerType.append(QString(tr("Description")));
    headerType.append(QString(tr("Start")));
    headerType.append(QString(tr("End")));
    headerType.append(QString(tr("Progress")));
    headerType.append(QString(tr("Resources")));
    headerType.append(QString(tr("Owner")));
}

FileIO::~FileIO()
{

}

QStandardItemModel *FileIO::openFile(QString fileName, QStandardItemModel *model)
{
    QFile file(fileName);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QXmlStreamReader reader(&file);

    if (!file.isReadable())
    {
        message.setText("Could not read file");
        message.exec();
        return model;
    }

    model->clear();

    // Create header details!
    for (int i = 0;i < headerType.count();i++)
    {
        model->setHorizontalHeaderItem(i, new QStandardItem(headerType.at(i)));
    }

    // Loop through XML text
    int row = 0;
    while (!reader.atEnd())
    {
        if (reader.isStartElement())
        {
            // Check version of the GanttChart version.
            if (reader.name() == "ganttchart")
            {
                double version = reader.attributes().value("version").toDouble();
                if (version < this->version)
                {
                     message.setText("Gantt Chart file is less than the current version.");
                     message.exec();
                     //return maybe?
                }
            }
            if (reader.name() == "task")
            {
                QStandardItemModel *container = new QStandardItemModel(1,headerType.count());

                // Loop through each header type
                for (int column=0;column<headerType.count();column++)
                {
                    QString header = headerType[column].toLower();
                    QString input = reader.attributes().value(header).toString();
                    //if (header == "start" || header == "end")
                    //    input = QDate::fromString(input,"yyyy-MM-dd").toString("dd/MM/yyyy");

                    QStandardItem *item = new QStandardItem(input);
                    container->insertRow(1);
                    model->setItem(row,column,item);
                }
                row++;
            }
            reader.readNext();
        }
        else
        {
            reader.readNext();
        }
    }
    return model;
}

bool FileIO::saveFile(QString fileName, QStandardItemModel *model)
{
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly))
    {
        message.setText("Could not write to file.");
        message.exec();
        return false;
    }

    QXmlStreamWriter writer(&file);
    writer.setAutoFormatting(true);
    writer.writeStartDocument();
    writer.writeStartElement("ganttchart");
    writer.writeAttribute("version", QString::number(this->version));

    for (int r = 0; r < model->rowCount(); r++)
    {
        writer.writeStartElement("task");
        for (int j = 0;j < headerType.count();j++)
        {
            writer.writeAttribute(headerType.at(j).toLower(),
                                  model->index(r,j).data(Qt::DisplayRole).toString());
        }
        writer.writeEndElement();
    }
    writer.writeEndElement();
    writer.writeEndDocument();
    return true;
}

bool FileIO::exportFile(QString fileName, QGraphicsScene *scene)
{
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly))
    {
        message.setText("Could not write to file.");
        message.exec();
        return false;
    }

    QImage image(scene->sceneRect().size().toSize(), QImage::Format_ARGB32);
    image.fill(Qt::transparent);
    QPainter painter(&image);
    scene->render(&painter);
    image.save(&file);
    return true;
}
