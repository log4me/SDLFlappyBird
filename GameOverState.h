//GameOverState.h
#ifndef GAMEOVERTATE_H
#define GAMEOVERTATE_H
#include "WorldState.h"
class GameOverState : public WorldState{
public:
	virtual ~GameOverState();
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual string getStateID() const{return s_GameOverID; }

private:
	bool m_loadingComplete;
	bool m_exiting;
	vector<string> m_textureIDList;
	vector<WorldObject*> m_worldObjects;
	static const string s_GameOverID;	
};
#endif