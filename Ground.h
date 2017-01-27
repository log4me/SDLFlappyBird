//GroundObject.h
#ifndef Ground_H
#define Ground_H
#include "WorldObject.h"
#include "LoaderParams.h"
#include "Vector2D.h"
class Ground : public WorldObject{
public:
	Ground(const LoaderParams *params);
	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual ~Ground();
    int getX(){
        return m_position.getX();
    }
    int getY(){
        return m_position.getY();
    }
    int getWidth(){
        return m_width;
    }
    int getHeight(){
        return m_height;
    }
    virtual void reset(){
        m_position.setX(0);
    }
private:
	Vector2D m_position;
	int m_width;
	int m_height;
	string m_textureID;
};
#endif