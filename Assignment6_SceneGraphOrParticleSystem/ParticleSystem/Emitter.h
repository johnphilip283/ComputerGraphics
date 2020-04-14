#pragma once

#include <QtCore>
#include <QtGui>

#include "Particle.h"

class Emitter {
    protected:
        QVector<Particle*> particles;
        QVector3D location_;
        QVector3D orientation_;
        Renderable* particleModel_;
    public:
        Emitter(const QVector3D& position, const QVector3D& orientation, Renderable* particleModel);
        void update(unsigned int msSinceLastFrame);
        void draw(const QMatrix4x4& projection,const QMatrix4x4& view);
        Particle* emitParticle();
};