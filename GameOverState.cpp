//GameOverState.cpp
#include "GameOverState.h"
#include "World.h"
#include "InputHandler.h"
#include "iostream"

const string GameOverState::s_GameOverID = "GAMEOVER";

GameOverState::~GameOverState(){}

void GameOverState::update(){
	int len = m_worldObjects.size();
	for(int i = 0; i < len; i++){
		m_worldObjects[i]->update();
	}
}

void GameOverState::render(){
	int len = m_worldObjects.size();
	for(int i = 0; i < len; i++){
		m_worldObjects[i]->draw();
}
}
bool GameOverState::onEnter(){
	m_worldObjects.push_back(World::Instance()->getObjects()["bg_day"]);
	m_worldObjects.push_back(World::Instance()->getObjects()["bird"]);
	m_worldObjects.push_back(World::Instance()->getObjects()["pipe1"]);
	m_worldObjects.push_back(World::Instance()->getObjects()["pipe2"]);
	m_worldObjects.push_back(World::Instance()->getObjects()["gameover"]);
	m_worldObjects.push_back(World::Instance()->getObjects()["ground"]);
	m_loadingComplete = true;
	return true;
}

bool GameOverState::onExit(){
	return true;
}