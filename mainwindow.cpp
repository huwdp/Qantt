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

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    version = 0.0002;

    // Initialise objects
    about = new About();
    documentation = new Documentation();

    spinBoxDelegate = new SpinBoxDelegate();
    dateEditDelegate = new DateEditDelegate();

    addTableColumns();
    setupActions();
    setupNavigation();
    setupTable();

    // Connect after the table is setup
    connect(ui->mainTableView->selectionModel(),SIGNAL(currentChanged(QModelIndex,QModelIndex)),this,SLOT(generateGraphics(QModelIndex,QModelIndex)));
    generateGraphics();
}

MainWindow::~MainWindow()
{
    delete mainStandardModel;
    delete about;
    delete documentation;

    delete newAction;
    delete openAction;
    delete saveAction;
    delete exportAction;
    delete exitAction;
    delete addTaskAction;
    delete removeTaskAction;
    delete moveTaskUpAction;
    delete moveTaskDownAction;
    delete documentationAction;
    delete aboutAction;
    delete licenseAction;

    delete ui;
}

void MainWindow::setupActions()
{
    // File menu
    newAction = new QAction(QString(tr("&New")), this);
    openAction = new QAction(QString(tr("&Open")), this);
    saveAction = new QAction(QString(tr("&Save")), this);
    exportAction = new QAction(QString(tr("Export")), this);
    exitAction = new QAction(QString(tr("&Exit")), this);

    // View menu
    viewTableAction = new QAction(QString(tr("Table")), this);
    viewTableAction->setCheckable(true);
    viewTableAction->setChecked(true);
    viewChartAction = new QAction(QString(tr("Chart")), this);
    viewChartAction->setCheckable(true);
    viewChartAction->setChecked(true);

    // Tasks menu
    addTaskAction = new QAction(QString(tr("&Add task")), this);
    removeTaskAction = new QAction(QString(tr("&Remove task")), this);
    moveTaskUpAction = new QAction(QString(tr("Move task up")), this);
    moveTaskDownAction = new QAction(QString(tr("Move task down")), this);

    // Help menu
    documentationAction = new QAction(QString(tr("&Documentation")), this);
    aboutAction = new QAction(QString(tr("&About")), this);
    licenseAction = new QAction(QString(tr("&License")), this);

    connect(newAction, SIGNAL(triggered()), this, SLOT(newFile()));
    connect(openAction, SIGNAL(triggered()), this, SLOT(openFile()));
    connect(aboutAction, SIGNAL(triggered()), this, SLOT(openAboutDialog()));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(exitApplication()));
    connect(documentationAction,SIGNAL(triggered()), this, SLOT(openDocumentationWindow()));
    connect(addTaskAction,SIGNAL(triggered()),this,SLOT(addTask()));
    connect(removeTaskAction,SIGNAL(triggered()),this,SLOT(removeTasks()));
    connect(saveAction,SIGNAL(triggered()),this,SLOT(saveFile()));
    connect(viewTableAction, SIGNAL(triggered()),this,SLOT(viewTable()));
    connect(viewChartAction, SIGNAL(triggered()),this,SLOT(viewChart()));
    connect(moveTaskUpAction, SIGNAL(triggered()),this,SLOT(moveTasksUp()));
    connect(moveTaskDownAction, SIGNAL(triggered()),this,SLOT(moveTasksDown()));
    connect(exportAction,SIGNAL(triggered()),this,SLOT(exportFile()));
    connect(licenseAction, SIGNAL(triggered(bool)), SLOT(openLicenseDialog()));
}

void MainWindow::setupNavigation()
{
    QMenu *menu;
    menu = ui->menuBar->addMenu(tr("&File"));
    menu->addAction(newAction);
    menu->addSeparator();
    menu->addAction(openAction);
    menu->addAction(saveAction);
    menu->addAction(exportAction);
    menu->addSeparator();
    menu->addAction(exitAction);

    menu = ui->menuBar->addMenu(tr("&View"));
    menu->addAction(viewTableAction);
    menu->addAction(viewChartAction);

    menu = ui->menuBar->addMenu(tr("&Tasks"));
    menu->addAction(addTaskAction);
    menu->addAction(removeTaskAction);
    menu->addSeparator();
    menu->addAction(moveTaskUpAction);
    menu->addAction(moveTaskDownAction);

    menu = ui->menuBar->addMenu(tr("&Help"));
    menu->addAction(documentationAction);
    menu->addAction(licenseAction);
    menu->addSeparator();
    menu->addAction(aboutAction);

    ui->mainToolBar->addAction(addTaskAction);
    ui->mainToolBar->addAction(removeTaskAction);
    ui->mainToolBar->addAction(moveTaskUpAction);
    ui->mainToolBar->addAction(moveTaskDownAction);
    ui->mainToolBar->addSeparator();
    ui->mainToolBar->addAction(exitAction);
    ui->mainToolBar->addAction(newAction);
    ui->mainToolBar->addAction(openAction);
    ui->mainToolBar->addAction(saveAction);
    ui->mainToolBar->addAction(exportAction);
    ui->mainToolBar->addSeparator();
    ui->mainToolBar->addAction(exitAction);
}

void MainWindow::setupTable()
{
    // Setup structure for listView
    mainStandardModel = new QStandardItemModel(10,headerType.count());

    for (int i = 0;i < headerType.count();i++)
    {
        mainStandardModel->setHorizontalHeaderItem(i, new QStandardItem(headerType.at(i)));
    }
    for (int i = 0;i < headerType.count();i++)
    {
        mainStandardModel->setHorizontalHeaderItem(i, new QStandardItem(headerType.at(i)));
    }
    ui->mainTableView->setModel(mainStandardModel);
    ui->mainTableView->setItemDelegateForColumn(1,dateEditDelegate);
    ui->mainTableView->setItemDelegateForColumn(2,dateEditDelegate);
    ui->mainTableView->setItemDelegateForColumn(3,spinBoxDelegate);
    ui->mainTableView->show();
}

void MainWindow::addTableColumns()
{
    headerType.append(QString(tr("Description")));
    headerType.append(QString(tr("Start")));
    headerType.append(QString(tr("End")));
    headerType.append(QString(tr("Progress")));
    headerType.append(QString(tr("Resources")));
    headerType.append(QString(tr("Owner")));
}

void MainWindow::reset()
{
    mainStandardModel->clear();
    setupTable();
    ui->graphicsView->scene()->clear();
}

void MainWindow::newFile()
{
    reset();
}

void MainWindow::openFile()
{
    dialog.setNameFilter(tr("Gantt Chart Files (*.gcp)"));
    dialog.setAcceptMode(QFileDialog::AcceptOpen);

    QString fileName = dialog.getOpenFileName(this);
    if (!fileName.isEmpty())
    {
        fileIO.openFile(fileName,mainStandardModel);
    }

    ui->mainTableView->show();
    this->setFocus();
    generateGraphics();
}

void MainWindow::saveFile()
{
    dialog.setNameFilter(tr("Gantt Chart Files (*.gcp)"));
    dialog.setAcceptMode(QFileDialog::AcceptSave);
    QString fileName = dialog.getSaveFileName(this);
    if (!fileName.isEmpty())
    {
        fileIO.saveFile(fileName,mainStandardModel);
    }
    this->setFocus();
}

void MainWindow::exportFile()
{
    dialog.setNameFilter(tr("Gantt Chart Files (*.png)"));
    dialog.setAcceptMode(QFileDialog::AcceptSave);
    QString fileName = dialog.getSaveFileName(this);
    if (!fileName.isEmpty())
    {
        fileIO.exportFile(fileName, ui->graphicsView->scene());
    }
}

void MainWindow::generateGraphics()
{
    ui->graphicsView->setScene(chart.render(mainStandardModel));
    ui->graphicsView->show();
}

void MainWindow::generateGraphics(QModelIndex,QModelIndex)
{
    ui->graphicsView->setScene(chart.render(mainStandardModel));
}

void MainWindow::addTask()
{
    if (ui->mainTableView->model()->rowCount() < 1)
    {
        mainStandardModel->appendRow(new QStandardItem());
        ui->mainTableView->setModel(mainStandardModel);
    }
    else
    {
        ui->mainTableView->model()->insertRow(1);
    }
}

void MainWindow::removeTasks()
{
    QModelIndexList indexes = ui->mainTableView->selectionModel()->selectedIndexes();
    QList<QModelIndex>::iterator it;
    for (it = indexes.begin(); it != indexes.end(); it++)
    {
        ui->mainTableView->model()->removeRow((*it).row());
    }
}

void MainWindow::moveTasksUp()
{
    QModelIndexList indexes = ui->mainTableView->selectionModel()->selectedIndexes();
    QList<QModelIndex>::iterator it;
    for (it = indexes.begin(); it != indexes.end(); it++)
    {
        if ((*it).row() > 0)
        {
            QList<QStandardItem*> current = mainStandardModel->takeRow((*it).row());
            mainStandardModel->insertRow((*it).row()-1,current);
        }
    }
}

void MainWindow::moveTasksDown()
{
    QModelIndexList indexes = ui->mainTableView->selectionModel()->selectedIndexes();
    QList<QModelIndex>::iterator it;
    for (it = indexes.begin(); it != indexes.end(); it++)
    {
        if ((*it).row()+1 < ui->mainTableView->children().count())
        {
            QList<QStandardItem*> current = mainStandardModel->takeRow((*it).row());
            mainStandardModel->insertRow((*it).row()+1,current);
        }
    }
}

void MainWindow::openDocumentationWindow()
{
    documentation->exec();
}

void MainWindow::openLicenseDialog()
{
    QMessageBox msgBox;
    msgBox.setText("Software licensed under GPL3 license.");
    msgBox.exec();
}

void MainWindow::openAboutDialog()
{
    about->exec();
}

void MainWindow::exitApplication()
{
    QMessageBox message;
    message.setText(tr("Are you sure you want to quit?"));
    message.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    if (message.exec() == QMessageBox::Yes)
    {
        this->close();
    }
}

void MainWindow::viewTable()
{
    ui->mainTableView->setVisible(!ui->mainTableView->isVisible());
}

void MainWindow::viewChart()
{
    ui->graphicsView->setVisible(!ui->graphicsView->isVisible());
}

