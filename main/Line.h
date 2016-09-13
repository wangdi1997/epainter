#ifndef __LINE_H__
#define __LINE_H__

#include "Graph.h"
#include <GL/glut.h>
#include <iostream>


class Line:public Graph 
{
public:

    Line(float a=0,float b=0,float c=0,float d=0) :
                                 Graph(a,b,c,d),startX(a),startY(b),endX(c),endY(d) {}

    void paint();
    void set(float a,float b,float c,float d);
    void move(float x,float y);
    bool ifIn(float x,float y);
    bool ifFinish(float x,float y);
    Graph* clone() const  {return new Line(*this);}

private:

    float startX,startY,endX,endY;
};

#endif /* __LINE_H__ */
