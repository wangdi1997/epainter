#ifndef __RECT_H__
#define __RECT_H__

#include "Graph.h"
#include <GL/glut.h>

#include <iostream>



class Rect:public Graph
{
public:

    Rect(float a=0,float b=0,float c=0,float d=0) :
                                 Graph(a,b,c,d),startX(a),startY(b),endX(c),endY(d) {}

     void paint() ;

     void move(float x,float y);
  
     bool ifIn(float x,float y);

     bool ifFinish(float x,float y);

     void set(float a,float b,float c,float d);

    Graph* clone() const  {return new Rect(*this);}

private:

    float startX,startY,endX,endY;
};

#endif /* __RECT_H__ */

