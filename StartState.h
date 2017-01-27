//StartState.h
#ifndef StartSTATE_H
#define StartSTATE_H
#include "WorldState.h"
class StartState : public WorldState{
public:
	virtual ~StartState();
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual string getStateID() const{return s_StartID; }

private:
	bool m_loadingComplete;
	bool m_exiting;
	vector<string> m_textureIDList;
	vector<WorldObject*> m_worldObjects;
	static const string s_StartID;	
};
#endif