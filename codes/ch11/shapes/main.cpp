#include <iostream>
using namespace std;

class Shape{ // base class
protected:
    int x, y;
public:
    Shape();
    Shape(int _x, int _y);
    Shape(const Shape &s);
    ~Shape();
    void Move(int _x, int _y);
    void Draw();
};
Shape::Shape(){
    x = 0; y = 0;
    cout << "shape w/o p" << endl;
}
Shape::Shape(int _x, int _y){
    x = _x; y = _y;
    cout << "shape w p" << endl;
}
Shape::Shape(const Shape &s){
    x = s.x; y = s.y;
    cout << "shape c c" << endl;
}
Shape::~Shape(){
    cout << "shape dc" << endl;
}
void Shape::Move(int _x, int _y){
    x = _x; y = _y;
}
void Shape::Draw(){
    cout << "[Shape position] x: "<< x << ", y: "<< y << endl;
}

class Rect : public Shape{ // inheritance
private:
    int width, height;
public:
    Rect();
    Rect(int _x, int _y, int w, int h);
    Rect(const Rect& r);
    ~Rect();
    void Draw();
    void Resize(int w, int h);
};

Rect::Rect(){
: Shape();
    {
        width = 0; height = 0;
        cout << "Rect con w/o" << endl;
    }
}
Rect::Rect(int _x, int _y, int w, int h){
:Shape(_x, _y);
    {
        width = w; height = h;
        cout << "Rect con w/o" << endl;
    }
}
Rect::Rect(const Rect& r){
:Shape(r);
    {
        width = r.width; height = r.height;
        cout << "Rect copy" << endl;
    }
}
Rect::~Rect(){
    cout << "Rect dc" << endl;
}
void Rect::Draw(){ // overriding
    cout << "[Draw position] x: "<< x << ", y: "<< y << endl;
    cout << "[size] width: "<< width << ", height: "<< height << endl;
}
void Rect::Resize(int w, int h){
    width = w; height = h;
}

class Circle : public Shape{
protected:
    int radius;
public:
    Circle();
    Circle(int _x, int _y, int r);
    Circle(const Rect& r);
    ~Circle();
    void Draw();
    void SetRadius(int r);
};

Circle::Circle(){
:Shape();
    {
        radius = 0;
        cout << "circle con w/o" << endl;
    }
}
Circle(int _x, int _y, int  r){
:Shape(_x, _y);
    {
        radius = r;
        cout << "circle con w/o" << endl;
    }
}
Circle(const Circle& r){
    :Shape(r);
    {
        width = r.width; height = r.height;
        cout << "Rect copy" << endl;
    }
}
~Circle(){
    cout << "Rect dc" << endl;
}
void Circle::Draw(){
    cout << "[Draw position] x: "<< x << ", y: "<< y << endl;
    cout << "[size] radius: "<< radius;
}
void Circle::SetRadius(int r){
    radius = r;
}






int main(){
    Shape x;
    x.Draw();
    
    Shape* A[5] = { NULL };
    A[0] = new Rect(300, 300, 100, 100);
    A[1] = new Shape();
    A[2] = new Rect(300, 300, 100, 100);
    A[3] = new Rect(300, 300, 100, 100);
    A[4] = new Rect(300, 300, 100, 100);


    return 0;
}