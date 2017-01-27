//GameOver.cpp
#include "GameOver.h"

#include "World.h"

GameOver::GameOver(const LoaderParams *params):m_position(params->getX(), params->getY()){
	m_width = params->getWidth();
	m_height = params->getHeight();
	m_textureID = params->getTextureID();
}
void GameOver::draw(){
	TextureManager::Instance()->draw(m_textureID, 
		(int)m_position.getX(), 
		(int)m_position.getY(),
		m_width, 
		m_height, 
		World::Instance()->getRenderer());
}
void GameOver::update(){

}

void GameOver::clean(){

}

GameOver::~GameOver(){
		
}