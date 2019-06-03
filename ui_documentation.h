/********************************************************************************
** Form generated from reading UI file 'documentation.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOCUMENTATION_H
#define UI_DOCUMENTATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Documentation
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *closePushButton;

    void setupUi(QDialog *Documentation)
    {
        if (Documentation->objectName().isEmpty())
            Documentation->setObjectName(QString::fromUtf8("Documentation"));
        Documentation->setWindowModality(Qt::WindowModal);
        Documentation->resize(400, 300);
        verticalLayout = new QVBoxLayout(Documentation);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(Documentation);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        textEdit = new QTextEdit(Documentation);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setReadOnly(true);

        verticalLayout->addWidget(textEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        closePushButton = new QPushButton(Documentation);
        closePushButton->setObjectName(QString::fromUtf8("closePushButton"));

        horizontalLayout->addWidget(closePushButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Documentation);

        QMetaObject::connectSlotsByName(Documentation);
    } // setupUi

    void retranslateUi(QDialog *Documentation)
    {
        Documentation->setWindowTitle(QApplication::translate("Documentation", "Documentation", nullptr));
        label->setText(QApplication::translate("Documentation", "<html><head/><body><p><span style=\" font-size:22pt; font-weight:600;\">Documentation</span></p></body></html>", nullptr));
        textEdit->setHtml(QApplication::translate("Documentation", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Noto Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:12pt; font-weight:600;\">Qantt</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">Qantt is a project management tool used to create and edit Gantt Charts.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; fo"
                        "nt-size:8pt; font-weight:600;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:12pt; font-weight:600;\">User Documentation</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Add task - Press the add item menu item button.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Remove task - Select a task and then press remove item button.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Move task up or down - Select a task and press either Move task up or Move task down.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">New Gantt Chart - Press New button.</p"
                        ">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Open existing Gantt chart - Press Open button, select file and open file.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Save Gantt chart - Press save, name file and press save. </p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Export Gantt as image - Press the export button, select file type and then press the save button.</p></body></html>", nullptr));
        closePushButton->setText(QApplication::translate("Documentation", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Documentation: public Ui_Documentation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCUMENTATION_H
