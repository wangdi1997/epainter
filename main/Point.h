#include <iostream>
using namespace std;

class Point
{
public:
	Point(float a,float b):
				x(a),y(b){};
	float getX() {return x;}
	float getY() {return y;}
	void addX(float a) { x = x + a;cout<<"addit"<<x<<endl; }
	void addY(float b) { y = y + b; }
private:
	float x,y;
				
};
