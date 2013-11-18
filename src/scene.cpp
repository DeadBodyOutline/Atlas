#include <QList>
#include <QRectF>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

#include "scene.h"

Scene::Scene()
{
    setBackgroundBrush(QPixmap("../images/transparency.png"));
}

Scene::~Scene(){
}
