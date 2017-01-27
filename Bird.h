//BirdObject.h
#ifndef Bird_H
#define Bird_H
#include "WorldObject.h"
#include "LoaderParams.h"
#include "Vector2D.h"
#include "Pipe.h"
#include "Ground.h"
class Bird : public WorldObject{
public:
	Bird(const LoaderParams *params);
	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual ~Bird();
    bool hit();
    bool hit(Pipe *pipe);
    bool hit(Ground *ground);
    bool pass();
    virtual void reset(){
        m_position.setX(100);
        m_position.setY(250);
        speed = 20.0;
    }
private:
	Vector2D m_position;
	int m_width;
	int m_height;
	string m_textureID;
    double gravity;
    double speed;
};
#endif