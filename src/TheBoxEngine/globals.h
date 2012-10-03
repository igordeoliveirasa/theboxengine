//
//  globals.h
//  OpenGLTest
//
//  Created by Igor de Oliveira Sa on 02/10/12.
//  Copyright (c) 2012 Igor de Oliveira Sa. All rights reserved.
//

#ifndef OpenGLTest_globals_h
#define OpenGLTest_globals_h

#include "box.h"
#include <vector>

// VARIAVEIS GLOBAIS -------------------

int screen_w, screen_h;


b2Vec2 gravity(0,-10);
b2World world(gravity);
std::vector<SimpleBox*> boxes;
Player *player = new Player(world,32*5,32*15,32,32,1,0,b2_dynamicBody,0,0,0);


float32 timeStep = 1.0f / 60.0f;
int32 velocityIterations = 6;
int32 positionIterations = 2;
//--------------------------------------
// Definicoes de 1 tela: 45 x 28 bloco, usarei 450 * 56



#endif
