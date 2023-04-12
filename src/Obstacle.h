//
// Created by alex on 4/12/23.
//

#ifndef DINO_OBSTACLE_H
#define DINO_OBSTACLE_H
#include "Vector2.hpp"
#include "Texture.hpp"
#include "Rectangle.hpp"
#include "BoundingBox.hpp"
#include "Game.h"

class Obstacle {
protected:
    Game* game;
    raylib::Vector2 position;
    raylib::Vector2 size;
    float scale;

    raylib::Texture* texture;

    float speed;

public:

    virtual void update(float dt);
    virtual void render() = 0;

    raylib::Vector2 getPosition();
    raylib::Vector2 getSize();
    raylib::Vector2 getSpeed();

    void setSpeed(float speed);
};

#endif //DINO_OBSTACLE_H
