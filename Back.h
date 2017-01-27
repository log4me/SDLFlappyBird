//BackObject.h
#ifndef Back_H
#define Back_H
#include "WorldObject.h"
#include "LoaderParams.h"
#include "Vector2D.h"
class Back : public WorldObject{
public:
	Back(const LoaderParams *params);
	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual ~Back();
    virtual void reset(){
        
    }
private:
	Vector2D m_position;
	int m_width;
	int m_height;
	string m_textureID;
};
#endif