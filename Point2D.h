#pragma once
#include <iostream>

class Point2D {
private:
    //friend class Prey;
    //friend Predator;
    //friend class Arena;
    //friend ostream& operator<<(ostream&, const Arena&);
    //friend bool check(const Prey& prey, const Predator& predator);
    //friend bool check1(const Prey& prey, const Predator& predator);
    int x;
    int y;
public:

    // �����������
    Point2D(int x = 0, int y = 0) : x(x), y(y) {  }

    // ���������� ��������� ������
    friend std::ostream& operator<<(std::ostream& out, const Point2D& point) {
        out << "(" << point.x << ", " << point.y << ")";
        return out;
    }
    int getX() { return x; }
    int getY() { return y; }


    void setPoint(int x, int y) {
        this->x = x;
        this->y = y;
    }
    bool operator==(const Point2D& point) {
        if (x == point.x && y == point.y) return 1;
        else return 0;
    }
    // ���������� ��������� ������
    friend std::ostream& operator<<(std::ostream& out, const Point2D& point) {
        out << "(" << point.x << ", " << point.y << ")";
        return out;
    }
};