//
// Created by alex on 4/12/23.
//

#ifndef DINO_CACTUS_H
#define DINO_CACTUS_H
#include "Obstacle.h"

class Cactus : public Obstacle {
public:

    raylib::Rectangle textureRect;

    explicit Cactus(raylib::Vector2 position, Game* game);
    ~Cactus() override;

    void render() override;
    void update(float dt) override;
};


#endif //DINO_CACTUS_H
