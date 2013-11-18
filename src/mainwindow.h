#ifndef __MAINWINDOW_H__
#define __MAINWINDOW_H__

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPixmap>
#include <QGraphicsPixmapItem>

#include "scene.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void openDialog();

private:
    void addImage(const QString fileName);

    QGraphicsView *m_view;
    Scene *m_scene;
    QGraphicsPixmapItem *m_item;
    QPixmap *m_pixmap;
};

#endif // __MAINWINDOW_H__
