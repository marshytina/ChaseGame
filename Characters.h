#pragma once
#include <iostream>
#include "Point2D.h"

class Character {

private:

    std::string name;        // ��� ���������
    Point2D location;   // ������� ��������� ���������
    bool npc;           // ������� NPC

public:

    Character(const std::string& name, const Point2D& location, bool npcFlag = 0);

    void moveTo(Point2D point);

    //0 - ����� 1 - ������ 2 - ���� 3 - ����� 4 - �����-����� 
    //5 - �����-������ 6 - ����-������ 7 - ����-�����
    void moveTo(int direction, int steps);

    Point2D getLocation();

    bool isNPC();

    virtual void autoMove() = 0;

    std::string getName() { return name; }
};

class Prey : public Character {

private:

    const int maxRange = 1;

public:

    Prey(const std::string& name, const Point2D& location, bool npcFlag = 0);

    int askDirection();

    void autoMove() override;



};

class Predator : public Character {
private:

    const int maxRange = 5;

public:
    Predator(const std::string& name, const Point2D& location, bool npcFlag = 0)
        : Character(name, location, npcFlag) {   }

    int askRange() {

        do {
            int range;
            std::cout << "�� �������? (1-5) \n";
            std::cin >> range;

            if (range >= 1 && range <= maxRange) {
                return range;
            }
            else std::cout << "������������ ����, �������� ��� ��� \n";

        } while (true);
    }

    int askDirection() {
        do {

            int direction(0);
            std::cout << "���� ����?\n";
            std::cout << "0 - �����, 1 - ������, 2 - ����, 3 - �����,\n";
            std::cin >> direction;

            if (direction <= 3 && direction >= 0) {
                return direction;
            }
            else std::cout << "������������ ����, �������� ��� ��� \n";

        } while (true);

    }

    void autoMove() override {

        int direction = 0;
        int range = 0;

        if (isNPC()) {
            direction = rand() % 4;
            range = rand() % 5 + 1;
        }
        else {
            direction = askDirection();
            range = askRange();
        }

        moveTo(direction, range);
    }

};