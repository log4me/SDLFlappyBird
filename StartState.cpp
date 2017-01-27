//StartState.cpp
#include "StartState.h"
#include "World.h"
#include "InputHandler.h"
#include "iostream"
using namespace std;

const string StartState::s_StartID = "START";

StartState::~StartState(){}

void StartState::update(){
	int len = m_worldObjects.size();
	for(int i = 0; i < len; i++){
		m_worldObjects[i]->update();
	}
}

void StartState::render(){
	int len = m_worldObjects.size();
	for(int i = 0; i < len; i++){
		m_worldObjects[i]->draw();
	}
}

bool StartState::onEnter(){
	m_worldObjects.push_back(World::Instance()->getObjects()["bg_day"]);
	m_worldObjects.push_back(World::Instance()->getObjects()["start"]);
	m_worldObjects.push_back(World::Instance()->getObjects()["bird"]);
	m_worldObjects.push_back(World::Instance()->getObjects()["ground"]);
	m_loadingComplete = true;
	return true;
}

bool StartState::onExit(){
	return true;
}