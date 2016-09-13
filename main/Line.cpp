#include "Line.h"
#include <iostream>

using namespace std;

extern "C"
{

void * create()
{
return new Line;
}

}

void Line::paint() {

        glBegin(GL_LINES);
        glVertex2f(startX,startY);
        glVertex2f(endX,endY);
        glEnd();
        glFlush();
                       }

void Line::set(float a,float b,float c,float d){
        startX=a;
        startY=b;
        endX=c;
        endY=d;
                                             }

void Line::move(float x,float y){
	cout<<startX<<endl;
        startX+=x;
        startY+=y;
        endX+=x;
        endY+=y;
	cout<<"DONE"<<startX<<endl;
                                             }

bool Line::ifFinish(float x,float y){
        return true;
}

bool Line::ifIn(float x,float y){
        float maxx,maxy,minx,miny;
	cout<<"test"<<endl;
	    cout<<"Startx"<<startX<<endl;
            cout<<"Starty"<<startY<<endl;
            cout<<"endx"<<endX<<endl;
            cout<<"endy"<<endY<<endl;
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
            cout<<"x"<<x<<endl;
            cout<<"y"<<y<<endl;
            cout<<"Maxx"<<maxx<<endl;
            cout<<"Maxy"<<maxy<<endl;
            cout<<"Minx"<<minx<<endl;
            cout<<"Miny"<<miny<<endl;
	    bool cd;
	    cd = (x<=maxx)&&(x>=minx)&&(y<=maxx);
	    cout<<cd<<endl;
	if ((x<=maxx)&&(x>=minx)&&(y<=maxy)&&(y>=miny))
	{
	    cout<<"IN!!"<<endl;
	    return true;
	}
	else 
	{
	    return false;
	}

                                }

