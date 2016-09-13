#ifndef __POLY_H__
#define __POLY_H__

#include "Graph.h"
#include <vector>
#include "Point.h"
#include <GL/glut.h>
#include <iostream>

using namespace std;


class Poly:public Graph 
{
public:

    Poly(float a=0,float b=0,float c=0,float d=0) :
                                 Graph(a,b,c,d),startX(a),startY(b),endX(c),endY(d) {}

    void paint();
    void set(float a,float b,float c,float d);
    void move(float x,float y);
    bool ifIn(float x,float y);
    bool ifFinish(float x,float y);
    Graph* clone() const  {return new Poly(*this);}

private:

    float startX,startY,endX,endY;
    bool finishType = false;
    int currentState = 0;
    vector<Point> pointSet;
    vector<Point>::iterator iter;
    vector<Point>::iterator tmpIter;
 
};

#endif /* __POLY_H__ */
