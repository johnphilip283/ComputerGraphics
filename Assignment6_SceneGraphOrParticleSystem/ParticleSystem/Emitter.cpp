#include "Emitter.h"

#include "Renderable.h"

Emitter::Emitter(const QVector3D& position, const QVector3D& orientation, Renderable* particleModel) {
    this->location_ = position;
    this->orientation_ = orientation;
    this->particleModel_ = particleModel;
}

void Emitter::update(unsigned int msSinceLastFrame) {
    for (auto particle: particles) {
        particle->update(msSinceLastFrame);
    }
}

Particle* Emitter::emitParticle() {
    QVector3D velocity(0.0, 1.0, 0.0);
    QColor color(255, 255, 255);

    QMatrix4x4 transform;
    transform.setToIdentity();
    transform.translate(location_);

    float lifetime = 2.5;

    return new Particle(particleModel_, transform, velocity, color, lifetime);
}

void Emitter::draw(const QMatrix4x4& projection, const QMatrix4x4& view) {
    
    particles.push_back(emitParticle());

    for (auto particle: particles) {
        particle->draw(projection, view);
    }
}
