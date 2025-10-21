#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // std::sort를 위해 포함
#include "Square.h"  // Square.h는 내부적으로 Point.h를 포함합니다.

using namespace std;

//
// Point 클래스 멤버 함수 구현
//

Point::Point(int px, int py) : x(px), y(py) {
    // 생성자 본문 (초기화 리스트에서 모두 처리됨)
}

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

void Point::setX(int px) {
    x = px;
}

void Point::setY(int py) {
    y = py;
}

//
// Square 클래스 멤버 함수 구현
//

// Square 생성자
// Point의 생성자를 호출하고, 멤버 변수들을 초기화합니다.
// 요구사항에 따라 area는 side * side로 계산합니다.
Square::Square(const string n, int px, int py, unsigned int s)
    : Point(px, py), side(s), name(n) {
    area = side * side; // 면적 계산
}

unsigned int Square::getSide() const {
    return side;
}

unsigned int Square::getArea() const {
    return area;
}

string Square::getName() const {
    return name;
}

// side가 변경되면 area도 함께 변경되어야 합니다.
void Square::setSide(unsigned int s) {
    side = s;
    area = s * s; // 면적 업데이트
}

void Square::setArea(unsigned int a) {
    area = a;
    // 참고: 요구사항상 setArea가 side를 변경해야 하는지는 불명확합니다.
    // 여기서는 주어진 정의대로 area 값만 변경합니다.
    // 어차피 이 문제에서는 생성자를 통해 area가 올바르게 설정됩니다.
}

void Square::setName(string n) {
    name = n;
}

//
// 정렬을 위한 비교 함수
//

// 1. 면적(area) 기준 오름차순
bool compareByArea(const Square& a, const Square& b) {
    return a.getArea() < b.getArea();
}

// 2. 최대 x좌표(x + side) 기준 오름차순
bool compareByMaxX(const Square& a, const Square& b) {
    int max_x_a = a.getX() + a.getSide();
    int max_x_b = b.getX() + b.getSide();
    return max_x_a < max_x_b;
}

// 3. 최대 y좌표(y + side) 기준 오름차순
bool compareByMaxY(const Square& a, const Square& b) {
    int max_y_a = a.getY() + a.getSide();
    int max_y_b = b.getY() + b.getSide();
    return max_y_a < max_y_b;
}


//
// main 함수
//
int main() {
    int n;
    cin >> n;

    vector<Square> squares; // Square 객체를 저장할 vector

    // n개의 Square 정보 입력받기
    for (int i = 0; i < n; ++i) {
        string name;
        int x, y;
        unsigned int side;
        cin >> name >> x >> y >> side;
        squares.push_back(Square(name, x, y, side));
    }

    // 입력과 출력 사이의 빈 줄
    cout << endl;

    // 1. 면적 기준 정렬 및 출력
    sort(squares.begin(), squares.end(), compareByArea);
    cout << "Squares in increasing order of area" << endl;
    for (const auto& s : squares) {
        cout << s.getName() << "(" << s.getX() << ", " << s.getY()
            << ") side=" << s.getSide() << ", area=" << s.getArea() << endl;
    }

    // 출력 세트 사이의 빈 줄
    cout << endl;

    // 2. 최대 x좌표 기준 정렬 및 출력
    sort(squares.begin(), squares.end(), compareByMaxX);
    cout << "Squares in increasing order of max x-coordinate" << endl;
    for (const auto& s : squares) {
        // 출력 형식: (max_x, ref_y)
        cout << s.getName() << "(" << (s.getX() + s.getSide()) << ", " << s.getY()
            << ") side=" << s.getSide() << ", area=" << s.getArea() << endl;
    }

    // 출력 세트 사이의 빈 줄
    cout << endl;

    // 3. 최대 y좌표 기준 정렬 및 출력
    sort(squares.begin(), squares.end(), compareByMaxY);
    cout << "Squares in increasing order of max y-coordinate" << endl;
    for (const auto& s : squares) {
        // 출력 형식: (ref_x, max_y)
        cout << s.getName() << "(" << s.getX() << ", " << (s.getY() + s.getSide())
            << ") side=" << s.getSide() << ", area=" << s.getArea() << endl;
    }

    return 0;
}