//
// Created by alex on 4/12/23.
//

#ifndef DINO_GAME_H
#define DINO_GAME_H
#include "Dino.h"
#include <vector>

class Ground;
class Obstacle;

class Game {
public:
    raylib::Window *window;
    Dino *dino;
    Ground *ground1;
    Ground *ground2;
    std::vector<Obstacle*>* obstacles;
    int obstacleCount = 0;
    int obstacleSpawnRate = 100;
    int obstacleSpawnTimer = 0;

    Game();
    ~Game();
    void loop();
};
#endif //DINO_GAME_H
