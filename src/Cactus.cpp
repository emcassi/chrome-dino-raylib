//
// Created by alex on 4/12/23.
//

#include "Cactus.h"
#include <random>
#include <iostream>

Cactus::Cactus(raylib::Vector2 position, Game* game) {
    this->position = position;
    this->speed = 500;
    this->size = raylib::Vector2(17, 35);
    this->texture = new raylib::Texture("../assets/images/cacti.png");
    this->game = game;
    std::srand(time(nullptr));
    int texX = rand() % 6;
    textureRect = raylib::Rectangle(texX * 17, 0, 17, 35);
}

Cactus::~Cactus() {
    delete texture;
}

void Cactus::render() {
    texture->Draw(textureRect, position);
}

void Cactus::update(float dt){
    Obstacle::update(dt);
}
