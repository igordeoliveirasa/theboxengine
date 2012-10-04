//
//  controllers.cpp
//  OpenGLTest
//
//  Created by Igor de Oliveira Sa on 02/10/12.
//  Copyright (c) 2012 Igor de Oliveira Sa. All rights reserved.
//

#ifdef _WIN32
#include <GL/glut.h>
#else
#include <GLUT/glut.h>
#endif



#include "controllers.h"
#include "globals.h"

void initialize() {
    // terreno
    player = new Player(world,32*5,32*15,32,32,1,0,b2_dynamicBody, "/Users/igor/Development/theboxengine/res/images/frog.gif");
    
    //floor
    boxes.push_back(new ScenarioBox(world, 32*0, 32*0, 32*1000, 32, 0, 0, b2_staticBody, NULL, 0.5, 0.7, 0));
    
    //7 degraus
    boxes.push_back(new ScenarioBox(world, 32*30+32*0, 32*1, 32*25-32*0, 32, 0, 0, b2_staticBody, NULL, 0.5, 0.7, 0));
    boxes.push_back(new ScenarioBox(world, 32*30+32*1, 32*2, 32*25-32*1, 32, 0, 0, b2_staticBody, NULL, 0.5, 0.7, 0));
    boxes.push_back(new ScenarioBox(world, 32*30+32*2, 32*3, 32*25-32*2, 32, 0, 0, b2_staticBody, NULL, 0.5, 0.7, 0));
    boxes.push_back(new ScenarioBox(world, 32*30+32*3, 32*4, 32*25-32*3, 32, 0, 0, b2_staticBody, NULL, 0.5, 0.7, 0));
    boxes.push_back(new ScenarioBox(world, 32*30+32*4, 32*5, 32*25-32*4, 32, 0, 0, b2_staticBody, NULL, 0.5, 0.7, 0));
    
    boxes.push_back(player);
    
    world.SetContactListener(player);
}

//--------------------------------------------------------------------------------
void display() {
    
    world.Step(timeStep, velocityIterations, positionIterations);
    
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    // camera
    b2Vec2 pos = player->body->GetPosition();
    if (pos.x >= screen_w/3) {
        float y = 0;
        
        if (pos.y >= screen_h/3) {
            y = pos.y-screen_h/3;
        }
        
        glTranslatef(-pos.x+(screen_w/3), -y, 0);
    }
    
    for (int i=0; i<boxes.size(); i++) {
        boxes[i]->Paint();
    }
    
    //player->Paint();
    
    glutSwapBuffers();
}

void idle() {
    glutPostRedisplay();
}

void reshape(int w, int h) {
    screen_w = w;
    screen_h = h;
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, screen_w, 0, screen_h);
    
    glMatrixMode(GL_MODELVIEW);
	glViewport(0, 0, screen_w, screen_h);
}


//--------------------------------------------------------------------------------
void keyboard(unsigned char key, int x, int y) {
    if (key == ' '){
        //std::cout << player->body->GetPosition().y << std::endl;
        player->Jump();
    }
}

void keyboardSpecial(int key, int x, int y) {
    if (key == 100) {
        player->SetMoveState(Player::MoveState::MS_LEFT);
    }
    if (key == 102) {
        player->SetMoveState(Player::MoveState::MS_RIGHT);
    }
}

void keyboardSpecialUp(int key, int x, int y) {
    if (key == 100) {
        player->SetMoveState(Player::MoveState::MS_STOP);
    }
    if (key == 102) {
        player->SetMoveState(Player::MoveState::MS_STOP);
    }
}