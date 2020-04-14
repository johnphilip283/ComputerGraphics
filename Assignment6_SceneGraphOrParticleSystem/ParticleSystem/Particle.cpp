#include "Particle.h"

Particle::Particle(Renderable* ren, QMatrix4x4 transform, const QVector3D& velocity, const QColor& color, float ttl) {
    this->renderable = ren;
    this->transform = transform;
    this->velocity = velocity;
    this->color = color;
    this->timeToLive_ = ttl;
}

void Particle::update(unsigned int msSinceLastUpdate) {
    timeToLive_ -= (float) msSinceLastUpdate / 1000.0;
    transform.translate(velocity);
    velocity *= 0.95;
}

void Particle::draw(const QMatrix4x4& projection, const QMatrix4x4& view) {
    if (timeToLive_ < 0) {
        return;
    }
    renderable->draw(view, projection);
}

Particle::~Particle() {}