//
// Created by alex on 4/12/23.
//

#include "Ground.h"

Ground::Ground(Vector2 position, Game* game) : position(position), game(game) {}

void Ground::update(float dt){
    if(game->dino->isAlive())
        position.x -= speed * dt;
}

void Ground::render(){
    texture.Draw(position, 0, scale);
}

void Ground::setPosition(Vector2 position){
    this->position = position;
}

float Ground::getScale(){
    return scale;
}

Vector2 Ground::getPosition(){
    return position;
}

Vector2 Ground::getSize(){
    return size;
}
