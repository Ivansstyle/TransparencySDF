/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionCompile;
    QWidget *centralwidget;
    QWidget *SceneWidget;
    QGridLayout *m_sceneLayout;
    QSpacerItem *horizontalSpacer_2;
    QWidget *NodeEditorWidget;
    QGridLayout *m_nodeEditorLayout;
    QSpacerItem *horizontalSpacer;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1440, 720);
        actionCompile = new QAction(MainWindow);
        actionCompile->setObjectName(QString::fromUtf8("actionCompile"));
        actionCompile->setCheckable(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        SceneWidget = new QWidget(centralwidget);
        SceneWidget->setObjectName(QString::fromUtf8("SceneWidget"));
        SceneWidget->setGeometry(QRect(720, 0, 720, 720));
        m_sceneLayout = new QGridLayout(SceneWidget);
        m_sceneLayout->setObjectName(QString::fromUtf8("m_sceneLayout"));
        m_sceneLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        m_sceneLayout->addItem(horizontalSpacer_2, 0, 0, 1, 1);

        NodeEditorWidget = new QWidget(centralwidget);
        NodeEditorWidget->setObjectName(QString::fromUtf8("NodeEditorWidget"));
        NodeEditorWidget->setGeometry(QRect(0, 0, 720, 720));
        m_nodeEditorLayout = new QGridLayout(NodeEditorWidget);
        m_nodeEditorLayout->setObjectName(QString::fromUtf8("m_nodeEditorLayout"));
        m_nodeEditorLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        m_nodeEditorLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setMovable(false);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actionCompile);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionCompile->setText(QApplication::translate("MainWindow", "Compile", nullptr));
#ifndef QT_NO_TOOLTIP
        actionCompile->setToolTip(QApplication::translate("MainWindow", "Compile (Shift + B)", nullptr));
#endif // QT_NO_TOOLTIP
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
