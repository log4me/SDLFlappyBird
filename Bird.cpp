//Bird.cpp
#include "Bird.h"
#include "GameState.h"
#include "StartState.h"
#include "GameOverState.h"
#include "World.h"
#include "InputHandler.h"
#include "StartState.h"
#include "Ground.h"
#include <iostream>
#include <cmath>
#include "SoundManager.h"
using namespace std;
Bird::Bird(const LoaderParams *params):m_position(params->getX(), params->getY()){
	m_width = params->getWidth();
	m_height = params->getHeight();
	m_textureID = params->getTextureID();
	gravity = 10.0;
	speed = 40.0;
}
void Bird::draw(){
	TextureManager::Instance()->draw(m_textureID, 
		(int)m_position.getX(), 
		(int)m_position.getY(),
		m_width, 
		m_height, 
		World::Instance()->getRenderer());
}
void Bird::update(){
	double intervalTime = 0.1;
	string curStateName = World::Instance()->getStateMachine()->getState()->getStateID();
	if(curStateName == "START"){
		if(InputHandler::Instance()->getMouseButtonState(LEFT)){
			InputHandler::Instance()->reset();
			World::Instance()->getStateMachine()->changeState(new GameState());
		}
	}else if(curStateName == "GAME"){
		double s = speed * intervalTime - 0.5 * gravity *intervalTime * intervalTime;
		speed = speed - gravity * intervalTime;
		int cur_y = m_position.getY();
		if(cur_y < s){
			m_position.setY(s - cur_y);
		}else{
			m_position.setY(cur_y - s);
		}
		if(InputHandler::Instance()->getMouseButtonState(LEFT)){
			InputHandler::Instance()->reset();
			SoundManager::Instance()->playSound("wing", 0);
			
			speed = 20.0;
		}
		if(hit()){
			SoundManager::Instance()->playSound("hit", 0);
			World::Instance()->getStateMachine()->changeState(new GameOverState());
			SoundManager::Instance()->playSound("die", 0);
		}
		if(pass()){
			SoundManager::Instance()->playSound("score", 0);
			int score;
			score ++ ;
		}
	}else{
		if(InputHandler::Instance()->getMouseButtonState(LEFT)){
			World::Instance()->getStateMachine()->changeState(new StartState());
			InputHandler::Instance()->reset();
		}
	}
}
bool Bird::pass(){
	Pipe *pipe1 = (Pipe*)World::Instance()->getObjects()["pipe1"];
	Pipe *pipe2 = (Pipe*)World::Instance()->getObjects()["pipe2"];
	return abs(pipe1->getX() + pipe1->getWidth() / 2 - m_position.getX() - m_width / 2) <= 1 || abs(pipe2->getX() + pipe2->getWidth()/2 - m_position.getX() - m_width / 2) <= 1 ;

}
bool Bird::hit(){
	Pipe *pipe1 = (Pipe*)World::Instance()->getObjects()["pipe1"];
	Pipe *pipe2 = (Pipe*)World::Instance()->getObjects()["pipe2"];
	Ground *ground = (Ground*)World::Instance()->getObjects()["ground"];
	return hit(pipe1) || hit(pipe2) || hit(ground);
}
bool Bird::hit(Pipe *pipe){
	int pipe_x = pipe->getX();
	int pipe_y = pipe->getY();
	int pipe_w = pipe->getWidth();
	int pipe_h = pipe->getHeight();
	int pipe_center_y = pipe_y + pipe_h / 2;
	if((m_position.getX()  + m_width > pipe_x) && (m_position.getX() < pipe_x + pipe_w)){
		if((m_position.getY() + m_height < pipe_center_y + pipe->getGap() / 2 )&& (m_position.getY() > pipe_center_y - pipe->getGap() / 2)){

			return false;
		}else{
			return true;
		}
	} 
	return false;
}
bool Bird::hit(Ground *ground){
	int ground_x = ground->getX();
	int ground_y = ground->getY();
	int ground_w = ground->getWidth();
	int ground_h = ground->getHeight();
	if(m_position.getY() + m_height > ground_y){
		return true;
	}
	return false;

}
void Bird::clean(){

}

Bird::~Bird(){
		
}