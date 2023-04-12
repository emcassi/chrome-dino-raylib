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
    int obstacleSpawnRate = 100;
    int obstacleSpawnTimer = 0;

    float score = 0;
private:
    bool shouldFlash = false;
    float scoreHoldTimer = 0;
    float flashRate = 3;
    float flashTimer = 0;
    float flashDuration = 0.1;
    bool whiteScore = false;
    Color scoreColor = BLACK;

    std::string scoreString = "0";
public:
    Game();
    ~Game();
    void loop();
};
#endif //DINO_GAME_H
