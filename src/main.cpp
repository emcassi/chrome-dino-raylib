#include <iostream>
#include "Window.hpp"
#include "raylib.h"
#include "Dino.h"

int main() {


    raylib::Window window(1280, 720, "Dino");

    Dino* dino = new Dino(Vector2(150, 460));

    while(!window.ShouldClose()){

        dino->update(GetFrameTime());

        window.BeginDrawing();
        window.ClearBackground(RAYWHITE);
        dino->render();
        window.EndDrawing();
    }

    window.Close();

    return 0;
}
