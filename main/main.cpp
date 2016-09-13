#include <GL/glut.h>
#include <iostream>
#include <vector>
#include <dlfcn.h>
#include "Graph.h"

using namespace std;

float startx,starty;
int ifFirst=0;
class GraphItem {
public:
    GraphItem():p(0){}
    GraphItem(const Graph &item):p(item.clone()){}
    const Graph *operator->() const {return p;}
    const Graph &operator*() const {return *p;}
private:
    Graph *p;

};

vector<GraphItem> graphItem;
vector<GraphItem>::iterator iter;
vector<GraphItem>::iterator iter2;
vector<GraphItem>::iterator iterTmp;

Graph *tmp ;
Graph *tmp2;
float startx2,starty2;
bool moveType;
bool getType = false;
int mykey;
bool finish = true;

void gIsearch(float x,float y)
{
getType = false;
for(iter=graphItem.begin(); iter!=graphItem.end(); ++iter){
       bool tmpBool = (*iter)->ifIn(x,y);
       if (tmpBool)
        {
	    iterTmp = iter;
	    cout<<"gIsearch get target"<<endl;
	    getType = true;
            return;
        }
    }
return;
}

void gIchange(float x,float y)//what you input should be delta
{
 if (getType)
    {
	(*iterTmp)->move(x,y);
    }
}

void doCommand(int command,float x,float y)
{

typedef Graph* create_g(int key);
void * handle = dlopen("./libkey.so", RTLD_LAZY);
create_g * create_graph = (create_g *)dlsym(handle, "keyDown");

switch(command){
    case 1:  //move1
	gIsearch(x,y);
	break;
    case 2:  //move2
	glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_LINES);
	gIchange(x,y);
	for(iter=graphItem.begin(); iter!=graphItem.end(); ++iter){
        (*iter)->paint();
                                                                  }
	break;
    case 3:  //draw1
        if (!finish)
	{
	cout<<"On click"<<endl;
	goto bk;
	}
	tmp = create_graph(mykey);
	startx = x;
	starty = y;
	break;
    case 4:  //draw2
	if (!finish)
	{
	cout<<"On Move"<<endl;
	goto bk;
	}
	glClear(GL_COLOR_BUFFER_BIT);
        glFlush();

	for(iter=graphItem.begin(); iter!=graphItem.end(); ++iter){
        (*iter)->paint();
                                                                  }
	tmp->set(startx,starty,x,y);
	tmp->paint();

	break;
    case 5:  //draw3
	if (!finish)
	{
	finish = tmp->ifFinish(x,y);
	if (finish) {tmp->paint();}
	glClear(GL_COLOR_BUFFER_BIT);
        glFlush();
	for(iter=graphItem.begin(); iter!=graphItem.end(); ++iter){
        (*iter)->paint();
	cout<<"Finish Up"<<endl;
	}
	if (finish){
	GraphItem item(*tmp);
        graphItem.push_back(item);
	cout<<"Save1"<<endl;
	}
	glClear(GL_COLOR_BUFFER_BIT);
        glFlush();
	for(iter=graphItem.begin(); iter!=graphItem.end(); ++iter){
        (*iter)->paint();
                                                                  }
	glBegin(GL_LINES);
        glVertex2f(0,0);
        glVertex2f(0,0);
        glEnd();
        glFlush();
	goto bk;
	}
	glClear(GL_COLOR_BUFFER_BIT);
        glFlush();

	for(iter=graphItem.begin(); iter!=graphItem.end(); ++iter){
        (*iter)->paint();
                                                                  }
	tmp->set(startx,starty,x,y);
	tmp->paint();
        finish = tmp->ifFinish(x,y);
	if (finish){
	GraphItem item(*tmp);
        graphItem.push_back(item);
	cout<<"Save2"<<endl;
	}
	bk:break;
               }
}

void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
    glVertex2f(0, 0);
    glVertex2f(0, 0.5);
    glEnd();
    glFlush();
}


void keyPress(int key,int x,int y){
    mykey = key;
}

void mouseMove(int x,int y)
{
	float tmpx,tmpy;
	tmpx = x/200.0-1;
	tmpy = -(y/200.0 - 1);
	tmpx = -startx + tmpx;
	tmpy = -starty + tmpy;
	if (mykey==GLUT_KEY_F3)
        {
	    cout<<"Ready to command "<<tmpx<<" "<<tmpy<<endl;
            doCommand(2,tmpx,tmpy);
            return;
        }
	doCommand(4,x/200.0-1,-(y/200.0 - 1));
}

void mouse(int button, int state, int x, int y)
{
     if (state==GLUT_DOWN)
	{
            startx = x/200.0 - 1;
            starty = -(y/200.0 - 1);
	    cout  <<"Mouse Down "<<startx<<" "<<starty<<'\n'<<  endl;
	    if (mykey==GLUT_KEY_F3)
            {
	    doCommand(1,startx,starty);
            return;
            }
	    doCommand(3,startx,starty);
	    
        }
    else if (state == GLUT_UP)
        {
	    if (mykey==GLUT_KEY_F3)
            {
            return;
            }
	    doCommand(5,x/200.0-1,-y/200.0+1);
            cout <<"Display"<<startx<<" "<<starty<<" "<<x/200.0-1<<" "<<-y/200.0 + 1<<" "<< endl;
        }
}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(400, 400);
    glutCreateWindow("OpenGL Painter");
    glutDisplayFunc(&myDisplay);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMove);
    glutSpecialFunc(keyPress);
    glutMainLoop();

    return 0;
}
                 
