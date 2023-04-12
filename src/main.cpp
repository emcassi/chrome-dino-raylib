#include <iostream>
#include "Window.hpp"
#include "raylib.h"
#include "Game.h"
#include "Ground.h"
#include "Cactus.h"

Game::Game(){
    window = new raylib::Window(1280, 720, "Dino");
    dino = new Dino(Vector2(150, 460));
    ground1 = new Ground(Vector2(0, dino->getPosition().y + dino->getSize().y - 12), this);
    ground2 = new Ground(Vector2(ground1->getPosition().x + ground1->getSize().x, ground1->getPosition().y), this);

    obstacles = new std::vector<Obstacle*>();

    obstacleSpawnTimer = obstacleSpawnRate;

    window->SetTargetFPS(60);
}

Game::~Game() {
    delete window;
    delete dino;
    delete ground1;
    delete ground2;

    for(auto &obstacle : *obstacles){
        delete obstacle;
    }

    delete obstacles;
}

void Game::loop(){

    while(!window->ShouldClose()){

        float dt = GetFrameTime();
        dino->update(dt);
        ground1->update(dt);
        ground2->update(dt);

        if(ground1->getPosition().x <= -ground1->getSize().x){
            ground1->setPosition(Vector2(ground2->getPosition().x + ground2->getSize().x, ground1->getPosition().y));
        } else if(ground2->getPosition().x <= -ground2->getSize().x){
            ground2->setPosition(Vector2(ground1->getPosition().x + ground1->getSize().x - 50, ground2->getPosition().y));
        }

        if(dino->isAlive()) {
            if (obstacleSpawnTimer <= 0) {
                auto cactus = new Cactus(raylib::Vector2(1280, ground1->getPosition().y - 25), this);
                obstacles->push_back(cactus);
                obstacleSpawnTimer = obstacleSpawnRate;
            } else {
                obstacleSpawnTimer -= dt;
            }
        }

        for(auto &obstacle : *obstacles){
            obstacle->update(dt);
        }

        window->BeginDrawing();
        window->ClearBackground(RAYWHITE);
        dino->render();
        ground1->render();
        ground2->render();

        for(auto &obstacle : *obstacles){
            obstacle->render();
        }

        window->EndDrawing();
    }

    window->Close();
}

int main() {

    Game* game = new Game();
    game->loop();

    delete game;

    return 0;
}
