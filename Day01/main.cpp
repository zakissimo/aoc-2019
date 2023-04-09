#include <iostream>

int main(void) {
    int input;
    int ans = 0;

    while(std::cin >> input) {
        do {
            input = input / 3 - 2;
            ans += input > 0 ? input : 0;
        } while (input > 0);
    }
    std::cout << &ans << std::endl;

    return 0;
}
