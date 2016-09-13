#include "Rect.h"

extern "C"
{

void * create()
{
return new Rect;
}

}

void Rect::paint()  {

        glRectf(startX,startY,endX,endY);
        glFlush();
                       }


void Rect::set(float a,float b,float c,float d){
        startX=a;
        startY=b;
        endX=c;
        endY=d;
                                             }

void Rect::move(float x,float y){
        startX+=x;
        startY+=y;
        endX+=x;
        endY+=y;
                                             }


bool Rect::ifFinish(float x,float y) {
        return true;
}


bool Rect::ifIn(float x,float y){
        float maxx,maxy,minx,miny;
        if (startX>endX)
        {
            maxx = startX;
            minx = endX;
        }
        else
        {
            maxx = endX;
            minx = startX;
        }
        if (startY>endY)
        {
            maxy = startY;
            miny = endY;
        }
        else
        {
            maxy = endY;
            miny = startY;
        }
        if ((x<=maxx)&&(x>=minx)&&(y<=maxy)&&(y>=miny))
        {
            return true;
        }
        else
        {
            return false;
        }

                                }

