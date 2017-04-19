/********************************************************************************
** Form generated from reading UI file 'parallelcoordinatesvolume.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARALLELCOORDINATESVOLUME_H
#define UI_PARALLELCOORDINATESVOLUME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ParallelCoordinatesVolumeClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QHBoxLayout *lLayout;
    QHBoxLayout *horizontalLayout;
    QWidget *parallelArea;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *l1;
    QHBoxLayout *horizontalLayout_7;
    QToolButton *addNodeFile;
    QHBoxLayout *parallelLayoutFile;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QHBoxLayout *horizontalLayout_8;
    QToolButton *addNodeColor;
    QHBoxLayout *parallelLayoutColor;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_9;
    QToolButton *addNodeAlpha;
    QHBoxLayout *parallelLayoutAlpha;
    QHBoxLayout *horizontalLayout_2;
    QWidget *ViewArea;
    QGridLayout *gridLayout_3;
    QVBoxLayout *viewStack;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ParallelCoordinatesVolumeClass)
    {
        if (ParallelCoordinatesVolumeClass->objectName().isEmpty())
            ParallelCoordinatesVolumeClass->setObjectName(QStringLiteral("ParallelCoordinatesVolumeClass"));
        ParallelCoordinatesVolumeClass->resize(960, 640);
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(12);
        ParallelCoordinatesVolumeClass->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/ParallelCoordinatesVolume/Resources/colour_line.png"), QSize(), QIcon::Normal, QIcon::Off);
        ParallelCoordinatesVolumeClass->setWindowIcon(icon);
        centralWidget = new QWidget(ParallelCoordinatesVolumeClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        lLayout = new QHBoxLayout();
        lLayout->setSpacing(6);
        lLayout->setObjectName(QStringLiteral("lLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        parallelArea = new QWidget(centralWidget);
        parallelArea->setObjectName(QStringLiteral("parallelArea"));
        gridLayout = new QGridLayout(parallelArea);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(3);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, -1, 0, -1);
        l1 = new QLabel(parallelArea);
        l1->setObjectName(QStringLiteral("l1"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setWeight(50);
        l1->setFont(font1);
        l1->setLineWidth(5);
        l1->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(l1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(1);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(-1, 1, -1, 1);
        addNodeFile = new QToolButton(parallelArea);
        addNodeFile->setObjectName(QStringLiteral("addNodeFile"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/ParallelCoordinatesVolume/Resources/add_to.png"), QSize(), QIcon::Normal, QIcon::Off);
        addNodeFile->setIcon(icon1);
        addNodeFile->setIconSize(QSize(16, 16));

        horizontalLayout_7->addWidget(addNodeFile);


        verticalLayout_4->addLayout(horizontalLayout_7);

        parallelLayoutFile = new QHBoxLayout();
        parallelLayoutFile->setSpacing(6);
        parallelLayoutFile->setObjectName(QStringLiteral("parallelLayoutFile"));

        verticalLayout_4->addLayout(parallelLayoutFile);

        verticalLayout_4->setStretch(0, 1);
        verticalLayout_4->setStretch(1, 1);
        verticalLayout_4->setStretch(2, 25);

        horizontalLayout_3->addLayout(verticalLayout_4);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(3);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(3);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label = new QLabel(parallelArea);
        label->setObjectName(QStringLiteral("label"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font2.setPointSize(10);
        label->setFont(font2);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        addNodeColor = new QToolButton(parallelArea);
        addNodeColor->setObjectName(QStringLiteral("addNodeColor"));
        addNodeColor->setIcon(icon1);

        horizontalLayout_8->addWidget(addNodeColor);


        verticalLayout_3->addLayout(horizontalLayout_8);

        parallelLayoutColor = new QHBoxLayout();
        parallelLayoutColor->setSpacing(6);
        parallelLayoutColor->setObjectName(QStringLiteral("parallelLayoutColor"));

        verticalLayout_3->addLayout(parallelLayoutColor);

        verticalLayout_3->setStretch(0, 1);
        verticalLayout_3->setStretch(1, 1);
        verticalLayout_3->setStretch(2, 25);

        verticalLayout_6->addLayout(verticalLayout_3);


        horizontalLayout_3->addLayout(verticalLayout_6);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(3);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_2 = new QLabel(parallelArea);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font3;
        font3.setPointSize(10);
        label_2->setFont(font3);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_2);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        addNodeAlpha = new QToolButton(parallelArea);
        addNodeAlpha->setObjectName(QStringLiteral("addNodeAlpha"));
        addNodeAlpha->setIcon(icon1);

        horizontalLayout_9->addWidget(addNodeAlpha);


        verticalLayout_5->addLayout(horizontalLayout_9);

        parallelLayoutAlpha = new QHBoxLayout();
        parallelLayoutAlpha->setSpacing(6);
        parallelLayoutAlpha->setObjectName(QStringLiteral("parallelLayoutAlpha"));

        verticalLayout_5->addLayout(parallelLayoutAlpha);

        verticalLayout_5->setStretch(0, 1);
        verticalLayout_5->setStretch(1, 1);
        verticalLayout_5->setStretch(2, 25);

        horizontalLayout_3->addLayout(verticalLayout_5);

        horizontalLayout_3->setStretch(0, 2);
        horizontalLayout_3->setStretch(1, 2);
        horizontalLayout_3->setStretch(2, 2);

        gridLayout->addLayout(horizontalLayout_3, 0, 0, 1, 1);


        horizontalLayout->addWidget(parallelArea);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        ViewArea = new QWidget(centralWidget);
        ViewArea->setObjectName(QStringLiteral("ViewArea"));
        gridLayout_3 = new QGridLayout(ViewArea);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        viewStack = new QVBoxLayout();
        viewStack->setSpacing(6);
        viewStack->setObjectName(QStringLiteral("viewStack"));

        gridLayout_3->addLayout(viewStack, 0, 0, 1, 1);


        horizontalLayout_2->addWidget(ViewArea);


        horizontalLayout->addLayout(horizontalLayout_2);

        horizontalLayout->setStretch(0, 16);
        horizontalLayout->setStretch(1, 6);

        lLayout->addLayout(horizontalLayout);

        lLayout->setStretch(0, 3);

        gridLayout_2->addLayout(lLayout, 0, 0, 1, 1);

        ParallelCoordinatesVolumeClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ParallelCoordinatesVolumeClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ParallelCoordinatesVolumeClass->setStatusBar(statusBar);

        retranslateUi(ParallelCoordinatesVolumeClass);

        QMetaObject::connectSlotsByName(ParallelCoordinatesVolumeClass);
    } // setupUi

    void retranslateUi(QMainWindow *ParallelCoordinatesVolumeClass)
    {
        ParallelCoordinatesVolumeClass->setWindowTitle(QApplication::translate("ParallelCoordinatesVolumeClass", "ParallelCoordinatesVolume", 0));
        l1->setText(QApplication::translate("ParallelCoordinatesVolumeClass", "\346\226\207\344\273\266", 0));
        addNodeFile->setText(QApplication::translate("ParallelCoordinatesVolumeClass", "...", 0));
        label->setText(QApplication::translate("ParallelCoordinatesVolumeClass", "\351\242\234\350\211\262", 0));
        addNodeColor->setText(QString());
        label_2->setText(QApplication::translate("ParallelCoordinatesVolumeClass", "\351\200\217\346\230\216\345\272\246", 0));
        addNodeAlpha->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ParallelCoordinatesVolumeClass: public Ui_ParallelCoordinatesVolumeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARALLELCOORDINATESVOLUME_H
