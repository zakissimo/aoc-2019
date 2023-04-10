#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

bool match_part_two(int nb) {
    string str = to_string(nb);
    map<char, int> map;

    for (int i = 0; i < str.length() - 1; ++i) {
        if (str[i + 1] < str[i])
            return false;
        if (str[i + 1] == str[i]) {
            map[str[i]] = map[str[i]] == 0
                ? 2 : map[str[i]] + 1;
        }
    }

    for (int i = 0; i < map.size(); ++i)
        if (map[i] == 2)
            return true;

    return false;
}

bool match_part_one(int nb) {
    bool same_adj = false;
    string str = to_string(nb);

    for (int i = 0; i < str.length() - 1; ++i) {
        if (str[i + 1] < str[i])
            return false;
        if (str[i + 1] == str[i])
            same_adj = true;
    }
    return same_adj;
}

int main(void) {
    int start = 134564;
    int end = 585159;
    vector<int> pass;

    for (int i = start; i < end; ++i) {
        if (match_part_one(i))
            pass.push_back(i);
    };
    cout << "Part one: " << pass.size() << endl;

    pass = {};
    for (int i = start; i < end; ++i) {
        if (match_part_two(i))
            pass.push_back(i);
    };
    cout << "Part two: " << pass.size() << endl;

    return 0;
}
