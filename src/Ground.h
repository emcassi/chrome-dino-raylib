//
// Created by alex on 4/12/23.
//

#ifndef DINO_GROUND_H
#define DINO_GROUND_H
#include "Vector2.hpp"
#include "Texture.hpp"
#include "Game.h"

class Ground {
private:
    Game* game;
    float scale = 2;
    Vector2 position{};
    Vector2 size = Vector2(640*scale, 6*scale);
    float speed = 500;
    raylib::Texture texture = raylib::Texture("../assets/images/ground_half.png");
public:
    Ground(Vector2 position, Game* game);

    void update(float dt);
    void render();

    void setPosition(Vector2 position);

    float getScale();
    Vector2 getPosition();
    Vector2 getSize();

};


#endif //DINO_GROUND_H
