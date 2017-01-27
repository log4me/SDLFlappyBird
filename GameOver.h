//GameOver.h
#ifndef GAMEOVER_H
#define GAMEOVER_H
#include "WorldObject.h"
#include "LoaderParams.h"
#include "Vector2D.h"
class GameOver : public WorldObject{
public:
	GameOver(const LoaderParams *params);
	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual ~GameOver();
    virtual void reset(){
        
    }
private:
	Vector2D m_position;
	int m_width;
	int m_height;
	string m_textureID;
};
#endif