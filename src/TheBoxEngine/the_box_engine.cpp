//
//  the_box_engine.cpp
//  TheBoxEngine
//
//  Created by Igor de Oliveira Sa on 03/10/12.
//  Copyright (c) 2012 Igor de Oliveira Sa. All rights reserved.
//

#include "the_box_engine.h"
#include <GLUT/glut.h>
#include "controllers.h"

TheBoxEngine::TheBoxEngine() {}

void TheBoxEngine::start(int argc, char** argv) {
    initialize();
    
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH);
    glutCreateWindow("Tadaaa!");
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    
    glutSpecialUpFunc(keyboardSpecialUp);
    glutSpecialFunc(keyboardSpecial);
    
    glutFullScreen();
    glutMainLoop();
}