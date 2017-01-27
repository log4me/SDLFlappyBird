//Ground.cpp
#include "Ground.h"

#include "World.h"

#include <iostream>
using namespace std;
Ground::Ground(const LoaderParams *params):m_position(params->getX(), params->getY()){
	m_width = params->getWidth();
	m_height = params->getHeight();
	m_position.setY(500 - m_height - 20);
	m_textureID = params->getTextureID();
}
void Ground::draw(){
	TextureManager::Instance()->draw(m_textureID, 
		(int)m_position.getX(), 
		(int)m_position.getY(),
		m_width, 
		m_height, 
		World::Instance()->getRenderer());
}
void Ground::update(){
	if(World::Instance()->getStateMachine()->getState()->getStateID() == "GAME"){
		int x = m_position.getX();
		x -= 2;
		if(x <= -(m_width - 358)){
			x = 0;
		}
		m_position.setX(x);
	}
}

void Ground::clean(){

}

Ground::~Ground(){
		
}