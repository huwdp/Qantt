/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_About
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *closePushButton;

    void setupUi(QDialog *About)
    {
        if (About->objectName().isEmpty())
            About->setObjectName(QString::fromUtf8("About"));
        About->resize(400, 300);
        verticalLayout = new QVBoxLayout(About);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(About);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        verticalSpacer_2 = new QSpacerItem(20, 83, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        label_2 = new QLabel(About);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setWordWrap(true);

        verticalLayout->addWidget(label_2);

        verticalSpacer = new QSpacerItem(20, 83, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        closePushButton = new QPushButton(About);
        closePushButton->setObjectName(QString::fromUtf8("closePushButton"));

        horizontalLayout->addWidget(closePushButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(About);

        QMetaObject::connectSlotsByName(About);
    } // setupUi

    void retranslateUi(QDialog *About)
    {
        About->setWindowTitle(QApplication::translate("About", "About", nullptr));
#ifndef QT_NO_WHATSTHIS
        About->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        label->setText(QApplication::translate("About", "<html><head/><body><p align=\"center\"><span style=\" font-size:22pt; font-weight:600;\">Qantt</span></p></body></html>", nullptr));
        label_2->setText(QApplication::translate("About", "Quantt, an Gantt Chart editor. Licensed under GPL3 license.", nullptr));
        closePushButton->setText(QApplication::translate("About", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class About: public Ui_About {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
