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

#include "the_box_engine.h"

int main(int argc, char **argv) {
    TheBoxEngine the_box_engine(argc, argv);
    the_box_engine.start();
}


