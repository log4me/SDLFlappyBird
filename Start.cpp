//Start.cpp
#include "Start.h"
#include "InputHandler.h"
#include "GameState.h"

#include "World.h"

Start::Start(const LoaderParams *params):m_position(params->getX(), params->getY()){
	m_width = params->getWidth();
	m_height = params->getHeight();
	m_textureID = params->getTextureID();
}
void Start::draw(){
	TextureManager::Instance()->draw(m_textureID, 
		(int)m_position.getX(), 
		(int)m_position.getY(),
		m_width, 
		m_height, 
		World::Instance()->getRenderer());
}
void Start::update(){
	if(InputHandler::Instance()->getMouseButtonState(LEFT)||InputHandler::Instance()->getMouseButtonState(RIGHT)){
		World::Instance()->getStateMachine()->changeState(new GameState());
	}
}

void Start::clean(){

}

Start::~Start(){
		
}