#ifndef __GRAPH_H__
#define __GRAPH_H__

class Graph {
public:
    Graph(float a,float b,float c,float d) :
                                  startX(a),startY(b),endX(c),endY(d) {}
    virtual void paint() {}
    virtual void set(float a,float b,float c,float d) {}
    virtual void move(float x,float y) {}
    virtual bool ifIn(float x,float y) {}
    virtual bool ifFinish(float x,float y) {}
    virtual Graph* clone() const  {return new Graph(*this);}
private:
    float startX,startY,endX,endY;
};


#endif /* __GRAPH_H__ */
