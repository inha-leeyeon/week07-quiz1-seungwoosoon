#ifndef SQUARE_H
#define SQUARE_H

#include "Point.h"
#include <string>

// 헤더 파일에서는 using namespace std;를 피하는 것이 좋습니다.
// std::string으로 명시합니다.
class Square : public Point {
public:
    Square(const std::string, int, int, unsigned int = 0);
    unsigned int getSide() const;
    unsigned int getArea() const;
    std::string getName() const;
    void setSide(unsigned int);
    void setArea(unsigned int);
    void setName(std::string);
private:
    unsigned int side;
    unsigned int area{ 0 };
    std::string name;
};

#endif // SQUARE_H