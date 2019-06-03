#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableView>
#include <QStandardItem>
#include <QMenuBar>
#include <QMessageBox>
#include <QFileDialog>

#include "fileio.h"
#include "ganttgraphics.h"
#include "about.h"
#include "documentation.h"
#include "spinboxdelegate.h"
#include "dateeditdelegate.h"
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

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    double version;
    Ui::MainWindow *ui;
    Documentation *documentation;
    About *about;
    SpinBoxDelegate *spinBoxDelegate;
    DateEditDelegate *dateEditDelegate;

    QStringList headerType;

    QAction *newAction;
    QAction *openAction;
    QAction *saveAction;
    QAction *exportAction;
    QAction *exitAction;

    QAction *viewTableAction;
    QAction *viewChartAction;

    QAction *addTaskAction;
    QAction *removeTaskAction;
    QAction *moveTaskUpAction;
    QAction *moveTaskDownAction;
    QAction *documentationAction;
    QAction *aboutAction;
    QAction *licenseAction;


    QStandardItemModel *mainStandardModel;
    QString fileName;
    QFileDialog dialog;
    FileIO fileIO;
    GanttGraphics chart;

    void addTableColumns();
    void setupActions();
    void setupNavigation();
    void setupTable();
    void generateGraphics();

private slots:
    void reset();
    void newFile();             // Wipes the data in the structure (loadData & GenerateGraphics)
    void openFile();            // Opens the data into a structure
    void saveFile();            // Saves the contents of the structure
    void exportFile();
    void generateGraphics(QModelIndex,QModelIndex);    // Generates the graphics

    void addTask();
    void removeTasks();
    void moveTasksUp();
    void moveTasksDown();

    void openDocumentationWindow();
    void openLicenseDialog();
    void openAboutDialog();
    void exitApplication();

    void viewTable();
    void viewChart();

};

#endif // MAINWINDOW_H
