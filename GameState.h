//GameState.h
#ifndef GAMESTATE_H 
#define GAMESTATE_H 
#include "WorldState.h"
class GameState : public WorldState{
public:
	virtual ~GameState();
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual string getStateID() const{return s_GameID; }

private:
	bool m_loadingComplete;
	bool m_exiting;
	vector<string> m_textureIDList;
	vector<WorldObject*> m_worldObjects;
	static const string s_GameID;	
};
#endif