#ifndef RECT_H
#define RECT_H

#include "Point.h"

class Rect {
private:
    Point topLeft, bottomRight;    
public:
    Rect();
    Rect(int x1, int y1, int x2, int y2);
    Rect(const Point& topLeft, const Point& bottomRight);
    ~Rect();
    void SetTopLeft(const Point& pt);
    void SetBottomRight(const Point& pt);
    Point GetTopLeft() const;
    Point GetBottomRight() const;
    void Print() const;
};

#endif