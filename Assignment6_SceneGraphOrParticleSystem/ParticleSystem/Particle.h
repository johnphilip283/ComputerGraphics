#pragma once

#include <QtCore>
#include <QtGui>
#include "Renderable.h"

class Particle {
    protected:
        Renderable* renderable;
        QVector3D velocity;
        QColor color;
        QMatrix4x4 transform;
        float timeToLive_;
    public:
        Particle(Renderable* ren, QMatrix4x4 transform, const QVector3D& velocity, const QColor& color, float ttl);
        void update(unsigned int msSinceLastUpdate);
        void draw(const QMatrix4x4& projection, const QMatrix4x4& view);
        virtual ~Particle();
};