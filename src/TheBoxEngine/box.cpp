//
//  box.cpp
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


#include "box.h"
#include <inttypes.h>
#include <iostream>

//--------------------------------------------------------------------------------
SimpleBox::SimpleBox(b2World &world,
        float x,
        float y,
        float w,
        float h,
        float density,
        float friction,
        b2BodyType body_type,
                     float r, float g, float b) : world(world) {
        
    this->w = w;
    this->h = h;
    this->r = r;
    this->g = g;
    this->b = b;
    
    b2BodyDef bodyDef;
    bodyDef.type = body_type;
    bodyDef.position.Set(x+(w/2), y+(h/2));
    bodyDef.fixedRotation = true;
    
    body = world.CreateBody(&bodyDef);
    
    b2PolygonShape box;
    box.SetAsBox(w/2, h/2);
    
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &box;
    fixtureDef.density = density;
    fixtureDef.friction = friction;
    
    body->CreateFixture(&fixtureDef);
}

ScenarioBox::ScenarioBox(b2World &world,
                         float x,
                         float y,
                         float w,
                         float h,
                         float density,
                         float friction,
                         b2BodyType body_type,
                         float r, float g, float b) : SimpleBox(world,x,y,w,h,density,friction,body_type,r,g,b) {
}

void ScenarioBox::Paint() {
    glBegin(GL_POLYGON);
    glColor3f(r, g, b);
    
    glVertex2f(body->GetPosition().x-(w/2), body->GetPosition().y-(h/2));
    glVertex2f(body->GetPosition().x+(w/2), body->GetPosition().y-(h/2));
    glVertex2f(body->GetPosition().x+(w/2), body->GetPosition().y+(h/2));
    glVertex2f(body->GetPosition().x-(w/2), body->GetPosition().y+(h/2));
    
    glEnd();
}


//--------------------------------------------------------------------------------
Player::Player(b2World &world,
                    float x,
                    float y,
                    float w,
                    float h,
                    float density,
                    float friction,
                    b2BodyType body_type,
               float r, float g, float b) : SimpleBox(world,x,y,w,h,density,friction,body_type,r,g,b) {
    
    
    //add foot sensor fixture

    b2PolygonShape footShape;
    footShape.SetAsBox(w/4, h/4, b2Vec2(0,-h/3), 0);
    
    b2FixtureDef footFixtureDef;
    footFixtureDef.shape = &footShape;
    footFixtureDef.isSensor = true;
    
    b2Fixture* footSensorFixture = body->CreateFixture(&footFixtureDef);
    footSensorFixture->SetUserData( (void*)1 );
    
    move_state = MoveState::MS_STOP;
}

void Player::SetMoveState(MoveState move_state) {
    this->move_state = move_state;
}

void Player::Jump() {
    
    if ( is_on_the_ground ) {
        b2Vec2 vel = body->GetLinearVelocity();
        vel.y = 30;
        body->SetLinearVelocity(vel);
    }
}

void Player::BeginContact(b2Contact* contact) {
    
    long long sig1 = reinterpret_cast<long long> (contact->GetFixtureA()->GetUserData());
    int fixtureUserData = static_cast<int>(sig1);
    
    if ( fixtureUserData == 1 )
        this->is_on_the_ground = true;

    sig1 = reinterpret_cast<long long> (contact->GetFixtureB()->GetUserData());
    fixtureUserData = static_cast<int>(sig1);
    
    if ( fixtureUserData == 1 )
        this->is_on_the_ground = true ;
    
    //this->is_on_the_ground = true;
    if (this->is_on_the_ground)
        std::cout << "floor, x: " << this->body->GetPosition().x << " y: "<< this->body->GetPosition().y << std::endl;

}

void Player::EndContact(b2Contact* contact) {
    
    long long sig1 = reinterpret_cast<long long> (contact->GetFixtureA()->GetUserData());
    int fixtureUserData = static_cast<int>(sig1);
    
    
    if ( fixtureUserData == 1 )
        this->is_on_the_ground = false;
    
    sig1 = reinterpret_cast<long long> (contact->GetFixtureB()->GetUserData());
    fixtureUserData = static_cast<int>(sig1);
    
    if ( fixtureUserData == 1 )
        this->is_on_the_ground = false;
    
    //this->is_on_the_ground = false;
    if (!this->is_on_the_ground)
        std::cout << "air,   x: " << this->body->GetPosition().x << " y: "<< this->body->GetPosition().y << std::endl;
}


void Player::Paint() {
    
    
    glBegin(GL_POLYGON);
    glColor3f(r, g, b);
    
    b2Vec2 vel = body->GetLinearVelocity();
    switch ( move_state )
    {
        case MS_LEFT:  vel.x = b2Max( vel.x - 0.1f, -20.0f ); break;
        case MS_STOP:  vel.x *=  0.987; break;
        case MS_RIGHT: vel.x = b2Min( vel.x + 0.1f,  20.0f ); break;
    }

    body->SetLinearVelocity( vel );
    
    glVertex2f(body->GetPosition().x-(w/2), body->GetPosition().y-(h/2));
    glVertex2f(body->GetPosition().x+(w/2), body->GetPosition().y-(h/2));
    glVertex2f(body->GetPosition().x+(w/2), body->GetPosition().y+(h/2));
    glVertex2f(body->GetPosition().x-(w/2), body->GetPosition().y+(h/2));
    
    glEnd();
}
