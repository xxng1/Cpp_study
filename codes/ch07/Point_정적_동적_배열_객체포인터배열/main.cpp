#include <iostream>
using namespace std;

class Point{
private:
    int x;
    int y;
public:
    Point();
    Point(int _x, int _y);
    Point(const Point &p);
    ~Point();
    void SetX(int val);
    void SetY(int val);
    int getX();
    int getY();
    void Print();
};
Point::Point(){
    x = 0;
    y = 0;
    cout << "매개변수 없는 생성자" << endl;
}
Point::Point(int _x, int _y){
    x = _x;
    y = _y;
    cout << "매개변수 있는 생성자" << endl;
}
Point::Point(const Point &p){
    x = p.x;
    y = p.y;
    cout << "복사 생성자" << endl;
}
Point::~Point(){
cout << "소멸자" << endl;
};
void Point::SetX(int val){
    x = val;
};
void Point::SetY(int val){
    y = val;
};
int Point::getX(){
    return x;
};
int Point::getY(){
    return y;
};
void Point::Print(){
    cout << "x: " << x;
    cout << ", y: " << y << endl;
}

//client
const int MAX = 3;
int main(){
    /*
    Point pt(50, 50);
    Point* p1 = new Point(100, 100);
    Point* p2 = &pt;
    p2 -> Print();
    delete p1; p1 = NULL;
    */
    int x, y;
    cout << "1. 정적객체배열방식" << endl;
    Point A[MAX];
    for(int i=0; i<MAX; i++){
        cout << i << "번쨰 포인트 입력-정적객체배열방식(x y): ";
        cin >> x >> y;
        A[i].SetX(x);
        (A+i)->SetY(y); // A의 자료형은 Point*
    }
    cout << "결과 출력" << endl;
    for(int i=0; i<MAX; i++){
        A[i].Print(); // (A+i)->Print();
    }

    cout << "2. 동적객체배열방식" << endl;
    int num;
    cout << "몇개의 객체? " << endl;
    cin >> num;
    Point* B = new Point[num];
    for(int i=0; i<num; i++){
        cout << i << "번쨰 포인트 입력-동적객체배열방식(x y): ";
        cin >> x >> y;
        B[i].SetX(x);
        (B+i)->SetY(y); 
    }
    cout << "결과 출력" << endl;
    for(int i=0; i<num; i++){
        B[i].Print(); 
    }
    
    cout << "3. 객체포인터배열방식" << endl;
    Point* C[MAX];
    for(int i=0; i<MAX; i++){
        cout << i << "번쨰 포인트 입력-객체포인터배열방식(x y): ";
        cin >> x >> y;
        C[i] = new Point(x, y);
    }
    cout << "결과 출력" << endl;
    for(int i=0; i<MAX; i++){
        C[i]->Print(); // == (*(C+i))->Print(); == (**(C+i)).Print(); 
    }

    cout << "4. cleanup " << endl;
    // 2번 소멸
    delete[] B; B = NULL;
    // 3번 소멸
    for(int i=0; i<MAX; i++){
        delete C[i]; C[i] = NULL;
    }
    return 0;
}