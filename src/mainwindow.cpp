#include <QGraphicsView>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QFileDialog>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QWidget(parent)
{
    resize(1024, 768);

    m_scene = new Scene();
    m_view = new QGraphicsView(this);

    // buttons
    QHBoxLayout *buttonsLayout = new QHBoxLayout();
    buttonsLayout->setContentsMargins(10, 10, 10, 10);

    QPushButton *openImage = new QPushButton("Open");
    connect(openImage, SIGNAL(released()), this, SLOT(openDialog()));
    buttonsLayout->addWidget(openImage);

    // main scene
    QVBoxLayout *mainViewLayout = new QVBoxLayout(this);
    mainViewLayout->setContentsMargins(0, 0, 0, 0);
    mainViewLayout->addLayout(buttonsLayout);
    mainViewLayout->addWidget(m_view);

    m_view->setScene(m_scene);
}

MainWindow::~MainWindow()
{
}

void MainWindow::openDialog()
{
    QString filter = "Images (*.png *.jpg)";

    // TODO use method to get a list of files
    QString fileName = QFileDialog::getOpenFileName(this, "Open File", QDir::homePath(), filter);

    if (fileName != QString())
        m_scene->addPixmap(QPixmap(fileName));
}
