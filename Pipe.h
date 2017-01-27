//PipeObject.h
#ifndef Pipe_H
#define Pipe_H
#include "WorldObject.h"
#include "LoaderParams.h"
#include "Vector2D.h"
#include <cstdlib>
class Pipe : public WorldObject{
public:
	Pipe(const LoaderParams *params);
	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual ~Pipe();
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
    int getGap(){
        return gap;
    }
    virtual void reset(){
        m_position.setX(x_back);
    }
private:
    int gap;
    int id;
    int x_back;
	Vector2D m_position;
	int m_width;
	int m_height;
	string m_textureID;
};
#endif