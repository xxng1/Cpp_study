//201835656 박상웅
#include <iostream>
using namespace std;

class Point {
private:
    int x;
    int y;
public:
    Point();
    Point(int x, int y);
    Point(const Point& p);
    ~Point();
    void print() const;
    void printV(const Point& other) const;
    void printH(const Point& other) const;
    double distance(const Point& other) const;
};
Point::Point(){
    x = 0;
    y = 0;
}
Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}
Point::Point(const Point& p){
    x = p.x;
    y = p.y;
}
Point::~Point(){}
void Point::print() const {
    cout << "(" << x << ", " << y << ")" << endl;
}
void Point::printV(const Point& other) const {
    if (x < other.x) {
        cout << "오른쪽 ";
    } else if (x > other.x) {
        cout << "왼쪽 ";
    } else {
        cout << "같은 위치 ";
    }
    cout << endl;
}
void Point::printH(const Point& other) const{
    if (y < other.y) {
        cout << "위 ";
    } else if (y > other.y) {
        cout << "아래 ";
    } else {
        cout << "같은 위치 ";
    }
    cout << endl;
}

double Point::distance(const Point& other) const {
    return sqrt(pow(other.x - x, 2) + pow(other.y - y, 2));
}

int main() {
    Point p1(3, 4);
    Point p2(6, 1);

    cout << "p1의 좌표: ";
    p1.print();
    cout << "p2의 좌표: ";
    p2.print();

    cout << "p2과의 좌우 비교) p1은 ";
    p2.printV(p1);
    cout << "p2과의 상하 비교) p1은 ";
    p2.printH(p1);
    cout << "p1, p2의 거리: " << p1.distance(p2) << endl;
    return 0;
}
