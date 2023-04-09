#include <iostream>
#include <sstream>
#include <vector>
#include <string>

typedef struct {
    int x;
    int y;
} Point;

using namespace std;

bool points_cross(Point p1, Point p2) {
    return (p1.x == p2.x && p1.y == p2.y);
}

vector<Point> translate(vector<string>input) {
    Point p =  { 0, 0 };
    vector<Point> out;

    for (const auto& e : input) {
        if (e[0] == 'R')
            p.x += stoi(e.substr(1));
        else if (e[0] == 'D')
            p.y += stoi(e.substr(1));
        else if (e[0] == 'L')
            p.x -= stoi(e.substr(1));
        else if (e[0] == 'U')
            p.y -= stoi(e.substr(1));
        out.push_back(p);
    }
    return out;
}

vector<string> split(string input, char d) {
    string element;
    vector<string> out;
    istringstream ss(input);

    while (getline(ss, element, d))
        out.push_back(element);

    return out;
}

int main(void) {

    string raw_wire_one;
    cin >> raw_wire_one;
    string raw_wire_two;
    cin >> raw_wire_two;

    vector<Point>wire_one = translate(split(raw_wire_one, ','));
    vector<Point>wire_two = translate(split(raw_wire_two, ','));

    int delta = INT32_MAX;
    for (const auto& p_one : wire_one)
        for (const auto& p_two : wire_two)
            if (points_cross(p_one, p_two))
                delta = abs(p_one.x) + abs(p_one.y) < delta
                    ? abs(p_one.x) + abs(p_one.y)
                    : delta;

    cout << delta << endl;
    return 0;
}
