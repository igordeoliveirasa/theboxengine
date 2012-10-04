//
//  box.h
//  OpenGLTest
//
//  Created by Igor de Oliveira Sa on 02/10/12.
//  Copyright (c) 2012 Igor de Oliveira Sa. All rights reserved.
//

#ifndef OpenGLTest_box_h
#define OpenGLTest_box_h


#define TEXTURE_ID_NULL -1

#include <Box2D/Box2D.h>


//--------------------------------------------------------------------------------
class SimpleBox : public b2ContactListener {
public:

    float w, h, r, g, b;
    b2Body* body;
    b2World &world;
    
    unsigned int texture_id = TEXTURE_ID_NULL;
    
    SimpleBox(b2World &world,
        float x,
        float y,
        float w,
        float h,
        float density,
        float friction,
        b2BodyType body_type,
        char* texture_file_path = NULL,
        float r=1, float g=0, float b=0);
    
    virtual void BeginContact(b2Contact* contact) = 0;
    virtual void EndContact(b2Contact* contact) = 0;
    virtual void Paint() = 0;
};


class ScenarioBox : public SimpleBox {
    
public:
    
    ScenarioBox(b2World &world,
           float x,
           float y,
           float w,
           float h,
           float density,
           float friction,
           b2BodyType body_type,
           char* texture_file_path = NULL,
           float r=1, float g=0, float b=0);
    
    void BeginContact(b2Contact* contact){}
    void EndContact(b2Contact* contact){}

    void Paint();
};


//--------------------------------------------------------------------------------
class Player : public SimpleBox {

public:
    
    enum MoveState {
        MS_STOP,
        MS_LEFT,
        MS_RIGHT,
    };

    float acceleration = 0;
    MoveState move_state;
    bool is_on_the_ground = false;

    Player(b2World &world,
           float x,
           float y,
           float w,
           float h,
           float density,
           float friction,
           b2BodyType body_type,
           char* texture_file_path = NULL,
           float r=1, float g=0, float b=0);
    
    void SetMoveState(MoveState move_state);
    void Jump();
    
    void BeginContact(b2Contact* contact);
    void EndContact(b2Contact* contact);
    
    void Paint();
};
#endif
