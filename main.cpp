#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // std::sort�� ���� ����
#include "Square.h"  // Square.h�� ���������� Point.h�� �����մϴ�.

using namespace std;

//
// Point Ŭ���� ��� �Լ� ����
//

Point::Point(int px, int py) : x(px), y(py) {
    // ������ ���� (�ʱ�ȭ ����Ʈ���� ��� ó����)
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
// Square Ŭ���� ��� �Լ� ����
//

// Square ������
// Point�� �����ڸ� ȣ���ϰ�, ��� �������� �ʱ�ȭ�մϴ�.
// �䱸���׿� ���� area�� side * side�� ����մϴ�.
Square::Square(const string n, int px, int py, unsigned int s)
    : Point(px, py), side(s), name(n) {
    area = side * side; // ���� ���
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

// side�� ����Ǹ� area�� �Բ� ����Ǿ�� �մϴ�.
void Square::setSide(unsigned int s) {
    side = s;
    area = s * s; // ���� ������Ʈ
}

void Square::setArea(unsigned int a) {
    area = a;
    // ����: �䱸���׻� setArea�� side�� �����ؾ� �ϴ����� �Ҹ�Ȯ�մϴ�.
    // ���⼭�� �־��� ���Ǵ�� area ���� �����մϴ�.
    // ������ �� ���������� �����ڸ� ���� area�� �ùٸ��� �����˴ϴ�.
}

void Square::setName(string n) {
    name = n;
}

//
// ������ ���� �� �Լ�
//

// 1. ����(area) ���� ��������
bool compareByArea(const Square& a, const Square& b) {
    return a.getArea() < b.getArea();
}

// 2. �ִ� x��ǥ(x + side) ���� ��������
bool compareByMaxX(const Square& a, const Square& b) {
    int max_x_a = a.getX() + a.getSide();
    int max_x_b = b.getX() + b.getSide();
    return max_x_a < max_x_b;
}

// 3. �ִ� y��ǥ(y + side) ���� ��������
bool compareByMaxY(const Square& a, const Square& b) {
    int max_y_a = a.getY() + a.getSide();
    int max_y_b = b.getY() + b.getSide();
    return max_y_a < max_y_b;
}


//
// main �Լ�
//
int main() {
    int n;
    cin >> n;

    vector<Square> squares; // Square ��ü�� ������ vector

    // n���� Square ���� �Է¹ޱ�
    for (int i = 0; i < n; ++i) {
        string name;
        int x, y;
        unsigned int side;
        cin >> name >> x >> y >> side;
        squares.push_back(Square(name, x, y, side));
    }

    // �Է°� ��� ������ �� ��
    cout << endl;

    // 1. ���� ���� ���� �� ���
    sort(squares.begin(), squares.end(), compareByArea);
    cout << "Squares in increasing order of area" << endl;
    for (const auto& s : squares) {
        cout << s.getName() << "(" << s.getX() << ", " << s.getY()
            << ") side=" << s.getSide() << ", area=" << s.getArea() << endl;
    }

    // ��� ��Ʈ ������ �� ��
    cout << endl;

    // 2. �ִ� x��ǥ ���� ���� �� ���
    sort(squares.begin(), squares.end(), compareByMaxX);
    cout << "Squares in increasing order of max x-coordinate" << endl;
    for (const auto& s : squares) {
        // ��� ����: (max_x, ref_y)
        cout << s.getName() << "(" << (s.getX() + s.getSide()) << ", " << s.getY()
            << ") side=" << s.getSide() << ", area=" << s.getArea() << endl;
    }

    // ��� ��Ʈ ������ �� ��
    cout << endl;

    // 3. �ִ� y��ǥ ���� ���� �� ���
    sort(squares.begin(), squares.end(), compareByMaxY);
    cout << "Squares in increasing order of max y-coordinate" << endl;
    for (const auto& s : squares) {
        // ��� ����: (ref_x, max_y)
        cout << s.getName() << "(" << s.getX() << ", " << (s.getY() + s.getSide())
            << ") side=" << s.getSide() << ", area=" << s.getArea() << endl;
    }

    return 0;
}