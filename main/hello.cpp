#include <GL/glut.h>
#include <iostream>
#include <vector>
using namespace std;

float startx,starty;



class Graph {
public:
    Graph(float a,float b,float c,float d) :
                                  startX(a),startY(b),endX(c),endY(d) {}

    virtual void paint() const {}
    virtual void set(float a,float b,float c,float d) {}
    virtual Graph* clone() const  {return new Graph(*this);}
private:
    float startX,startY,endX,endY;    
};

class Line:public Graph {
public:
    Line(float a=0,float b=0,float c=0,float d=0) : 
                                 Graph(a,b,c,d),startX(a),startY(b),endX(c),endY(d) {}

    void paint() const {

        glBegin(GL_LINES);
        glVertex2f(startX,startY);
        glVertex2f(endX,endY);
        glEnd();
        glFlush();
                       }

    void set(float a,float b,float c,float d){
        startX=a;
        startY=b;
        endX=c;
        endY=d;     
                                             }
              

    Graph* clone() const  {return new Line(*this);}
private:
    float startX,startY,endX,endY;
};

class Rect:public Graph {
public:
    Rect(float a=0,float b=0,float c=0,float d=0) :
                                 Graph(a,b,c,d),startX(a),startY(b),endX(c),endY(d) {}

    void paint() const {

        glRectf(startX,startY,endX,endY);
        glFlush();
                       }

    void set(float a,float b,float c,float d){
        startX=a;
        startY=b;
        endX=c;
        endY=d;
                                             }


    Graph* clone() const  {return new Rect(*this);}
private:
    float startX,startY,endX,endY;
};


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
Graph *tmp = new Line();

void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
    glVertex2f(0, 0);
    glVertex2f(0, 0.5);
    glEnd();
    glFlush();
}

void newDisplay(float x,float y,float xt,float yt)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
    for(iter=graphItem.begin(); iter!=graphItem.end(); ++iter){
        (*iter)->paint();
    }
    tmp->set(x,y,xt,yt);
    GraphItem item(*tmp);
    item->paint();
}

void newDisplayUp(float x,float y,float xt,float yt)
{
    tmp->set(x,y,xt,yt);
    GraphItem item(*tmp);
    graphItem.push_back(item);
    for(iter=graphItem.begin(); iter!=graphItem.end(); ++iter){
        (*iter)->paint();
    }
}

void keyPress(int key,int x,int y){
  switch(key){
    case GLUT_KEY_F1:
	delete tmp;
	tmp = NULL;
	tmp = new Line();
	break;
    case GLUT_KEY_F2:
        delete tmp;
	tmp = NULL;
	tmp = new Rect();
	break;
             }

}

void mouseMove(int x,int y)
{
    newDisplay(startx,starty,x/200.0-1,-(y/200.0 - 1));
}

void mouse(int button, int state, int x, int y)
{
    cout  <<"Mouse Down "<<x<<" "<<y<<'\n'<<  endl;
    if (state == GLUT_DOWN)
        {
	    startx = x/200.0 - 1;
	    starty = -(y/200.0 - 1);
	}
    else if (state == GLUT_UP)
	{
	    newDisplayUp(startx,starty,x/200.0-1,-(y/200.0 - 1));
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
