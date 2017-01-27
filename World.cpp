#include "World.h"
#include "InputHandler.h"
#include "Bird.h"
#include "Pipe.h"
#include "Start.h"
#include "gameOver.h"
#include "Ground.h"
#include "Back.h"
#include "StartState.h"
#include "SoundManager.h"
#include <map>
#include <iostream>
using std::cerr;
using std::endl;
using std::cout;
World* World::s_pInstance = NULL;
bool World::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen){
	// attemp to initialize SDL
	m_bRunning = false;
	int flags = 0;
	if(fullscreen){
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if(0 == SDL_Init(SDL_INIT_EVERYTHING)){
		cerr << "SDL init success" << endl;
		//init the window	
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if(0 != m_pWindow){
			//window init success
			cerr << "window creation success" << endl;
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
			if(0 != m_pRenderer){
				//renderer init success
				cerr << "renderer creation success" << endl;
				SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
			}else{
				cerr << "renderer init fail" << endl;
				return false;
			}
		}else{
			cerr << "window init fail" << endl;
			return false;//window init fail
		}
	}else{
		cerr << "SDL init fail" << endl;
		return false;
	}
	if(!TextureManager::Instance()->load("assets/images/start.png","start", m_pRenderer)){
		return false;
	}
	num = "";
	if(!TextureManager::Instance()->load("assets/images/gameover.png", "gameover", m_pRenderer)){
		return false;
	}
	if(!TextureManager::Instance()->load("assets/images/bg_day.png", "bg_day", m_pRenderer)){
		return false;
	}
	if(!TextureManager::Instance()->load("assets/images/blue1.png", "bird", m_pRenderer)){
		return false;
	}
	if(!TextureManager::Instance()->load("assets/images/pipe.png", "pipe", m_pRenderer)){
		return false;
	}
	if(!TextureManager::Instance()->load("assets/images/ground.png", "ground", m_pRenderer)){
		return false;
	}
	int start_x = 0;
	int start_y = 0;
	int start_width;
	int start_height;
	SDL_QueryTexture(TextureManager::Instance()->getTexture("start"), NULL, NULL, &start_width, &start_height);
	int bg_day_x = 0;
	int bg_day_y = 0;
	int bg_day_width = 0;
	int bg_day_height = 0;
	SDL_QueryTexture(TextureManager::Instance()->getTexture("bg_day"), NULL, NULL, &bg_day_width, &bg_day_height);
	int blue_x = 100;
	int blue_y = 250;
	int blue_width = 0;
	int blue_height = 0;
	SDL_QueryTexture(TextureManager::Instance()->getTexture("bird"), NULL, NULL, &blue_width, &blue_height);
	int pipe_x = 320;
	int pipe_y = 0;
	int pipe_width = 0;
	int pipe_height = 0;
	SDL_QueryTexture(TextureManager::Instance()->getTexture("pipe"), NULL, NULL, &pipe_width, &pipe_height);
	int gameover_x = 0;
	int gameover_y = 0;
	int gameover_width = 0;
	int gameover_height = 0;
	SDL_QueryTexture(TextureManager::Instance()->getTexture("gameover"), NULL, NULL, &gameover_width, &gameover_height);
	int ground_x = 0;
	int ground_y = 0;
	int ground_width = 0;
	int ground_height = 0;
	SDL_QueryTexture(TextureManager::Instance()->getTexture("ground"), NULL, NULL, &ground_width, &ground_height);
	m_worldObjects["bird"] = new Bird(new LoaderParams(blue_x, blue_y, blue_width, blue_height, "bird"));
	m_worldObjects["pipe1"] = new Pipe(new LoaderParams(pipe_x, pipe_y, pipe_width, pipe_height, "pipe"));
	m_worldObjects["pipe2"] = new Pipe(new LoaderParams(pipe_x + 180, pipe_y, pipe_width, pipe_height, "pipe"));
	m_worldObjects["start"] = new Start(new LoaderParams(start_x, start_y, start_width, start_height, "start"));
	m_worldObjects["bg_day"] = new Back(new LoaderParams(bg_day_x, bg_day_y, bg_day_width, bg_day_height, "bg_day"));
	m_worldObjects["gameover"] = new Start(new LoaderParams(gameover_x, gameover_y, gameover_width, gameover_height, "gameover"));
	m_worldObjects["ground"] = new Ground(new LoaderParams(ground_x, ground_y, ground_width, ground_height, "ground"));
	m_pStateMachine = new StateMachine();
	m_pStateMachine->pushState(new StartState());
	SoundManager::Instance()->load("assets/music/wing.wav", "wing", SOUND_SFX);
    SoundManager::Instance()->load("assets/music/score.wav", "score", SOUND_SFX);
	SoundManager::Instance()->load("assets/music/die.wav", "die", SOUND_SFX);
    SoundManager::Instance()->load("assets/music/hit.wav", "hit", SOUND_SFX);
	cerr << "init success" << endl;
	m_bRunning = true;//start the main loop
	return true;
}
void World::render(){
	SDL_RenderClear(m_pRenderer);//clear the renderer
	m_pStateMachine->render();
	SDL_RenderPresent(m_pRenderer);//draw to the screen
}
void World::clean(){
	cout << "cleaning World" << endl;
	m_worldObjects.clear();
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}
void World::update(){
	m_pStateMachine->update();
}
void World::draw(){
}
void World::handleEvents(){
	InputHandler::Instance()->update();
}
