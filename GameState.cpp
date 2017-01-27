//GameState.cpp
#include "GameState.h"
#include "World.h"
#include "InputHandler.h"
#include "iostream"

const string GameState::s_GameID = "GAME";

GameState::~GameState(){}

void GameState::update(){
	int len = m_worldObjects.size();
	for(int i = 0; i < len; i++){
		m_worldObjects[i]->update();
	}
}

void GameState::render(){
	int len = m_worldObjects.size();
	for(int i = 0; i < len; i++){
		m_worldObjects[i]->draw();
	}
}

bool GameState::onEnter(){
	m_worldObjects.push_back(World::Instance()->getObjects()["bg_day"]);
	m_worldObjects.push_back(World::Instance()->getObjects()["pipe1"]);
	m_worldObjects.push_back(World::Instance()->getObjects()["pipe2"]);
	m_worldObjects.push_back(World::Instance()->getObjects()["bird"]);
	m_worldObjects.push_back(World::Instance()->getObjects()["ground"]);
	for(int i = 0 ; i < m_worldObjects.size() ; i++)
		m_worldObjects[i]->reset();
	m_loadingComplete = true;
	return true;
}

bool GameState::onExit(){
	return true;
}
