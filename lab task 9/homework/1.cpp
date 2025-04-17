#include<iostream>
using namespace std;

class Shape{
	public:
		virtual float getArea()=0;
};

class Rectangle: public Shape{
	private:
		float length;
		float width;
	public:
		Rectangle(float l, float w){
			length=l;
			width=w;
		}
		
		float getArea() override{
			return length*width;
		}
};

class Triangle: public Shape{
	private:
		float base;
		float height;
	public:
		Triangle(float b, float h){
			base=b;
			height=h;
		}
		
		float getArea() override{
			return (base*height)/2;
		}
};

int main(){
	Rectangle r(1.2,5.0);
	Triangle t(6,4);
	
	cout<<"Area of Rectangle: "<<r.getArea()<<endl;
	cout<<"Area of Triangle: "<<t.getArea()<<endl;
	
	return 0;
}
