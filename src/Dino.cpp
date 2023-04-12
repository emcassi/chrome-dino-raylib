//
// Created by alex on 4/11/23.
//

#include "Dino.h"

Dino::Dino(raylib::Vector2 position){
    this->position = position;

    runningSprites[0] = idleSprite;
    runningSprites[1] = new raylib::Texture("../assets/images/dino1.png");
    runningSprites[2] = idleSprite;
    runningSprites[3] = new raylib::Texture("../assets/images/dino2.png");

    animTimer = animDelay;
}

void Dino::render(){
    if(alive){
        runningSprites[currentFrame]->Draw(position, 0, 1.5);
    } else {
        deadSprite.Draw(position);
    }
}

void Dino::update(float dt) {

    if(IsKeyPressed(KEY_SPACE) && onGround){
        yVel = -jumpForce;
        onGround = false;
    }

    if(!onGround)
        yVel += gravity * dt;
    position.y += yVel * dt;

    if(position.y >= groundHeight){
        position.y = groundHeight;
        onGround = true;
    }

    // Update animation
    if(animTimer <= 0){
        animTimer = animDelay;
        currentFrame++;
        if(currentFrame >= 4)
            currentFrame = 0;
    } else {
        animTimer -= dt;
    }

}