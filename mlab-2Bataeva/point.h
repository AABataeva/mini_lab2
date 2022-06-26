#ifndef POINT_H
#define POINT_H
#include <QPainter>

class Point{
public:
    Point();
    Point(int x=0, int y=0, int size=3, int width=1);
    int getX() const;
    void setX(int newX);

    int getY() const;
    void setY(int newY);

    int getSize() const;
    void setSize(int newSize);

    int getWidth() const;
    void setWidth(int newWidth);

    void draw(QPainter *painter);

    float distance2(const QPoint &point);

    bool getPressed() const;
    void setPressed(bool newPressed);

private:
    int x, y, size, width;
    bool pressed;

};

#endif // POINT_H
