#ifndef __MAINWINDOW_H__
#define __MAINWINDOW_H__

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>

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
    QGraphicsView *m_view;
    Scene *m_scene;
};

#endif // __MAINWINDOW_H__
