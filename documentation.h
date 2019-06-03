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

#ifndef DOCUMENTATION_H
#define DOCUMENTATION_H

#include <QDialog>

namespace Ui {
class Documentation;
}

class Documentation : public QDialog
{
    Q_OBJECT
    
public:
    explicit Documentation(QWidget *parent = 0);
    ~Documentation();
    
private:
    Ui::Documentation *ui;
};

#endif // DOCUMENTATION_H
