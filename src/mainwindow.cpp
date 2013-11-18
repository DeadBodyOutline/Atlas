#include <QGraphicsView>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QFileDialog>
#include <QPainter>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QWidget(parent)
{
    resize(1024, 768);

    m_scene = new Scene();
    m_view = new QGraphicsView(this);
    m_pixmap = new QPixmap(800, 800); // XXX we need to change it as the used adds new images
    m_pixmap->fill(Qt::transparent);
    m_item = m_scene->addPixmap(*m_pixmap);

    // buttons
    QHBoxLayout *buttonsLayout = new QHBoxLayout();
    buttonsLayout->setContentsMargins(10, 10, 10, 10);

    QPushButton *openImage = new QPushButton("Add image(s)");
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
    QStringList files = QFileDialog::getOpenFileNames(this, "Add image(s)", QDir::homePath(), filter);

    foreach (QString fileName, files)
        addImage(fileName);
}

// TODO really thinking on create a custom scene with all related functions
void MainWindow::addImage(const QString fileName)
{
    QPixmap *pixmap = new QPixmap(fileName);

    QPainter p(m_pixmap);
        p.drawPixmap(0, 0, *pixmap); // XXX save positions to add new images
    p.end();

    m_item->setPixmap(*m_pixmap);
}
