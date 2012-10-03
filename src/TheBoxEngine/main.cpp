//
//  main.cpp
//  OpenGLTest
//
//  Created by Igor de Oliveira Sa on 28/09/12.
//  Copyright (c) 2012 Igor de Oliveira Sa. All rights reserved.
//

/* Use the following line on a Windows machine:
 #include <GL/glut.h>
 */
/* This line is for Max OSX  */

#include <GLUT/glut.h>
#include "controllers.h"

int main(int argc, char **argv) {

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

    
    // testando commit via xcode (apagar depois)
}



