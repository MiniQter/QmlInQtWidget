#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLayout>
#include <QQuickItem>
#include <QQuickView>
#include <QQuickWidget>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //    QQuickView *view = new QQuickView;
    //    view->setResizeMode(QQuickView::SizeRootObjectToView);
    //    QWidget *container = QWidget::createWindowContainer(view, this);
    //    centralWidget()->layout()->addWidget(container);
    //    view->setSource(QUrl("qrc:/RotatingSquare.qml"));
    //    view->show();

    QQuickWidget *view = new QQuickWidget(this);
    view->setResizeMode(QQuickWidget::SizeRootObjectToView);
    view->setSource(QUrl("qrc:/RotatingSquare.qml"));
    centralWidget()->layout()->addWidget(view);
    view->show();

    QQuickItem *item = view->rootObject();
    if (item) {
        connect(item, SIGNAL(signalFromQml()), this, SLOT(onSignalFromQml()));
        connect(this, SIGNAL(signalFromCpp()), item, SIGNAL(responseSignalFromCpp()));
        connect(this, SIGNAL(signalFromCpp()), item, SLOT(functionInQml()));
        QMetaObject::invokeMethod(item, "functionInQml", Qt::DirectConnection);
    }

    QTimer::singleShot(1000, this, SIGNAL(signalFromCpp()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onSignalFromQml()
{
    qDebug() << "response signal from qml";
}
