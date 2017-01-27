//Startbject.h
#ifndef START_H
#define START_H
#include "WorldObject.h"
#include "LoaderParams.h"
#include "Vector2D.h"
class Start : public WorldObject{
public:
	Start(const LoaderParams *params);
	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual ~Start();
    virtual void reset(){
        
    }
private:
	Vector2D m_position;
	int m_width;
	int m_height;
	string m_textureID;
};
#endif