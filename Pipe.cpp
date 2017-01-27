//Pipe.cpp
#include "Pipe.h"

#include "World.h"

Pipe::Pipe(const LoaderParams *params):m_position(params->getX(), params->getY()){
	m_width = params->getWidth();
	m_height = params->getHeight();
	m_textureID = params->getTextureID();
	m_position.setY(rand() % 140 + 140 - m_height / 2 - getGap() / 2);
	gap = 109;
	x_back = params->getX();
}
void Pipe::draw(){
	TextureManager::Instance()->draw(m_textureID, 
		(int)m_position.getX(), 
		(int)m_position.getY(),
		m_width, 
		m_height, 
		World::Instance()->getRenderer());
}
void Pipe::update(){
	if(World::Instance()->getStateMachine()->getState()->getStateID() == "GAME"){
		int x = m_position.getX();
		x -= 2;
		int y = m_position.getY();
		if(x <= -m_width){
			x = 325;
			y = rand() % 140 + 140 - m_height / 2 - getGap() / 2;
		}
		m_position.setX(x);
		m_position.setY(y);
	}
	
}

void Pipe::clean(){

}

Pipe::~Pipe(){
		
}