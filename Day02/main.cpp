#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>

#define dorito for (;;)
#define stop break

int main(void) {

    std::string input;
    std::vector<int> arr;
    while(std::cin >> input) {
        dorito {
            arr.push_back(std::stoi(input));
            if (input.find(",") == std::string::npos)
                stop;
            input = input.substr(input.find(",") + 1);
        }
    }

    int ans = 0;
    int target = 19690720;
    std::vector<int> arr_cp;

    for (int noun = 0; noun < 100; noun++) {
        for (int verb = 0; verb < 100; verb++) {
            arr_cp = arr;
            arr_cp[1] = noun;
            arr_cp[2] = verb;
            for (int i = 0; arr_cp[i] != 99; i+=4) {
                if (arr_cp[i + 1] < arr_cp.size()
                    && arr_cp[i + 2] < arr_cp.size()
                    && arr_cp[i + 3] < arr_cp.size()) {
                    if (arr_cp[i] == 1)
                        arr_cp[arr_cp[i + 3]] = arr_cp[arr_cp[i + 1]] + arr_cp[arr_cp[i + 2]];
                    if (arr_cp[i] == 2)
                        arr_cp[arr_cp[i + 3]] = arr_cp[arr_cp[i + 1]] * arr_cp[arr_cp[i + 2]];
                }
            }
            ans = 100 * noun + verb;
            if (arr_cp[0] == target)
                std::cout << ans << std::endl;
        }
    }
}
