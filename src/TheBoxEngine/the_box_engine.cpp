//
//  the_box_engine.cpp
//  TheBoxEngine
//
//  Created by Igor de Oliveira Sa on 03/10/12.
//  Copyright (c) 2012 Igor de Oliveira Sa. All rights reserved.
//

#ifdef _WIN32
#include <GL/glut.h>
#else
#include <GLUT/glut.h>
#endif

#define ILUT_USE_OPENGL
#include <IL/il.h>
#include <IL/ilu.h>
#include <IL/ilut.h>


#include "the_box_engine.h"
#include "controllers.h"

TheBoxEngine::TheBoxEngine(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH|GLUT_ALPHA);
    glutCreateWindow("Tadaaa!");
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    
    glutSpecialUpFunc(keyboardSpecialUp);
    glutSpecialFunc(keyboardSpecial);
    
    glutFullScreen();

    //devIL
    ilInit ();
    iluInit();
    ilutInit();
    ilEnable (IL_CONV_PAL);
    ilutEnable (ILUT_OPENGL_CONV);
    glEnable       (GL_TEXTURE_2D);
    ilutRenderer (ILUT_OPENGL);
    
}

void TheBoxEngine::start() {
    initialize();
    glutMainLoop();
}