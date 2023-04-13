//
// Created by alex on 4/12/23.
//

#include "Obstacle.h"
#include <iostream>

Obstacle::~Obstacle() {
    delete game;
    delete texture;
}

void Obstacle::update(float dt) {

    if(game->dino->isAlive()) {
        position.x -= speed * dt;

        if (position.x < -size.x) {
            game->obstacles.erase(game->obstacles.begin());
        }

        raylib::Rectangle rect = raylib::Rectangle(position.x, position.y, size.x, size.y);
        raylib::Rectangle playerRect = raylib::Rectangle(game->dino->getPosition().x + 10 * game->dino->getScale(), game->dino->getPosition().y,
                                                         32, game->dino->getSize().y);

        if (rect.CheckCollision(playerRect)) {
            std::cout << "Collision!" << std::endl;
            game->dino->setAlive(false);
        }
    }
}

raylib::Vector2 Obstacle::getPosition(){
    return position;
}

raylib::Vector2 Obstacle::getSize(){
    return size;
}

raylib::Vector2 Obstacle::getSpeed(){
    return size;
}

void Obstacle::setSpeed(float speed){
    this->speed = speed;
}


