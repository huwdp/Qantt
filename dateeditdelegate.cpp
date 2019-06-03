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

#include "dateeditdelegate.h"

#include <QDateEdit>

DateEditDelegate::DateEditDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{

}

QWidget *DateEditDelegate::createEditor(QWidget *parent,const QStyleOptionViewItem &,const QModelIndex &index) const
{
    QDateEdit *editor = new QDateEdit(parent);
    QDate date = index.model()->data(index, Qt::EditRole).toDate();
    if (date.isNull() || !date.isValid())
    {
            date = QDate::currentDate();
    }
    QDateEdit *dateEdit = static_cast<QDateEdit*>(editor);
    dateEdit->setDate(date);
    return editor;
}

void DateEditDelegate::setEditorData(QWidget *editor,const QModelIndex &index) const
{
    QDate date = index.model()->data(index, Qt::EditRole).toDate();
    if (date.isNull() || !date.isValid())
    {
            date = QDate::currentDate();
    }
    QDateEdit *dateEdit = static_cast<QDateEdit*>(editor);
    dateEdit->setDate(date);
}

void DateEditDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,const QModelIndex &index) const
{
    QDateEdit *dateEdit = static_cast<QDateEdit*>(editor);
    QDate date = dateEdit->date();
    model->setData(index, date, Qt::EditRole);
}

void DateEditDelegate::updateEditorGeometry(QWidget *editor,
    const QStyleOptionViewItem &option, const QModelIndex &index ) const
{
    editor->setGeometry(option.rect);
}
