#include "Poly.h"
#include <iostream>
#include <vector>
using namespace std;

extern "C"
{

void * create()
{
return new Poly;
}

}



void Poly::paint() {
	if (finishType){
	    bool tmpId=true;
	    float tmpX,firstX,tx,ty;
	    float tmpY,firstY;
	    int q = -1;
	    tmpIter = pointSet.begin() ;
	    for (tmpIter=pointSet.begin();tmpIter!=pointSet.end();++tmpIter){
		iter = tmpIter;
	    }
	    tmpIter = pointSet.begin() ;
	    for (tmpIter=pointSet.begin();tmpIter!=pointSet.end();++tmpIter){
		if (q==-1){
		    firstX = (*tmpIter).getX();
		    firstY = (*tmpIter).getY();
		    tx = firstX;
		    ty = firstY;
		    tmpX = (*iter).getX();
		    tmpY = (*iter).getY();
		    glBegin(GL_LINES);
        	    glVertex2f(tx,ty);
        	    glVertex2f(tmpX,tmpY);
        	    glEnd();
        	    glFlush();
		    cout<<"Paint:"<<tx<<endl;
		    q+=1;
			}
		else {
		    tmpX = (*tmpIter).getX();
		    tmpY = (*tmpIter).getY();
		    glBegin(GL_LINES);
        	    glVertex2f(tx,ty);
        	    glVertex2f(tmpX,tmpY);
        	    glEnd();
        	    glFlush();
		    tx = tmpX;
		    ty = tmpY;
		    cout<<"Paint"<<tx<<endl;
		    q+=1;
			}
									}
	
			}
	else{
	int asas = pointSet.size();
	cout<<"Else"<<asas<<endl;
        glBegin(GL_LINES);
        glVertex2f(startX,startY);
        glVertex2f(endX,endY);
        glEnd();
        glFlush();}
                       }

void Poly::set(float a,float b,float c,float d){
        if (currentState==0)
	{
	    Point tmpa(a,b);
	    pointSet.push_back(tmpa);
	    iter = pointSet.begin();
	    currentState+=1;
	    cout<<"First Set!"<<endl;
	}
        startX=a;
        startY=b;
        endX=c;
        endY=d;
                                             }

void Poly::move(float x,float y){
	startX += x;
	startY += y;
	finishType = true;
	for (tmpIter=pointSet.begin();tmpIter!=pointSet.end();++tmpIter){
	    (*tmpIter).addX(x);
	    (*tmpIter).addY(y);
	    float tmpqq = pointSet.size();
	    cout<<"Q MOve "<<tmpqq<<endl;
	    }
                                }
	

bool Poly::ifFinish(float x,float y){
	if (finishType){goto ca;}
	int i=1;
	float a1,b1,c1,d1;
	currentState+=1;
	Point tmpa(x,y);
	pointSet.push_back(tmpa);
	cout<<"add in "<<x<<" "<<y<<endl;
	tmpIter =  pointSet.begin(); 
	for (tmpIter; tmpIter!=pointSet.end() ; ++tmpIter)
	{
	    if (currentState==i){iter=tmpIter;}
	    i+=1;    
	}
	tmpIter=pointSet.begin();
	a1 = (*iter).getX();
	b1 = (*iter).getY();
	c1 = (*tmpIter).getX();
	d1 = (*tmpIter).getY();
	a1 = a1 - c1;
	b1 = b1 - d1;
	if ((a1<0.05)&&(a1>-0.05)&&(b1<0.05)&&(b1>-0.05)){
	finishType = true;
	cout<<currentState<<" Finish!"<<endl;
	for (tmpIter=pointSet.begin();tmpIter!=pointSet.end();++tmpIter){
	    float tsa = (*tmpIter).getX();
	    float tsb = (*tmpIter).getY();
	    cout<<"x-"<<tsa<<" y-"<<tsb<<endl;
	    }
	ca:return true;
						}
	cout<<currentState<<" Not Finish!"<<a1<<" "<<b1<<endl;
        fs:return false;
}

bool Poly::ifIn(float x,float y){
	return true;
                                }

