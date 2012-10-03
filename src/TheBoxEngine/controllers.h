//
//  controllers.h
//  OpenGLTest
//
//  Created by Igor de Oliveira Sa on 02/10/12.
//  Copyright (c) 2012 Igor de Oliveira Sa. All rights reserved.
//

#ifndef OpenGLTest_controllers_h
#define OpenGLTest_controllers_h

void display();
void idle();
void reshape(int w, int h);

void keyboard(unsigned char key, int x, int y);
void keyboardSpecial(int key, int x, int y);
void keyboardSpecialUp(int key, int x, int y);

void initialize();

#endif
