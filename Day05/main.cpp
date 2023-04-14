#include <cstring>
#include <iostream>
#include <new>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Inst {
  public:
    int opCode;
    int idxOffset;
    typedef struct {
        int value;
        int mode;
    } Param;
    Param params[3];
    Inst(int& idx, vector<int> &intCode) {
        int n = intCode[idx];
        opCode = n % 100;
        n /= 100;
        switch (opCode) {
        case 99:
            idxOffset = 0;
            break;
        case 3:
            idxOffset = 2;
            cout << "Case 3, setting address " << intCode[idx + 1]
                 << " to 5.\n";
            intCode[intCode[idx + 1]] = 5;
            break;
        case 4:
            idxOffset = 2;
            cout << "Case 4, value is " << intCode[intCode[idx + 1]] << endl;
            break;
            handleModes(opCode, n, idx, intCode);
        case 5:
            idxOffset = 3;
            handleModes(opCode, n, idx, intCode);
            if (params[0].value != 0) {
                idx = params[1].value;
                idxOffset = 0;
            }
            break;
        case 6:
            idxOffset = 3;
            handleModes(opCode, n, idx, intCode);
            if (params[0].value == 0) {
                idx = params[1].value;
                idxOffset = 0;
            }
            break;
        case 1:
            idxOffset = 4;
            handleModes(opCode, n, idx, intCode);
            intCode[intCode[idx + 3]] = params[0].value + params[1].value;
            break;
        case 2:
            idxOffset = 4;
            handleModes(opCode, n, idx, intCode);
            intCode[intCode[idx + 3]] = params[0].value * params[1].value;
            break;
        case 7:
            idxOffset = 4;
            handleModes(opCode, n, idx, intCode);
            intCode[intCode[idx + 3]] =
                params[0].value < params[1].value ? 1 : 0;
            break;
        case 8:
            idxOffset = 4;
            handleModes(opCode, n, idx, intCode);
            intCode[intCode[idx + 3]] =
                params[0].value == params[1].value ? 1 : 0;
            break;
        }
    }
    void handleModes(int opCode, int n, int idx, vector<int> &intCode) {
        params[0].mode = n % 10;
        params[1].mode = (n / 10) % 10;
        for (int i = 0; i < 2; i++) {
            if (params[i].mode == 0)
                params[i].value = intCode[intCode[idx + i + 1]];
            else
                params[i].value = intCode[idx + i + 1];
        }
    }
};

int main(void) {

    std::string input;
    std::vector<int> arr;

    std::cin >> input;
    std::istringstream ss(input);
    std::string token;

    while (std::getline(ss, token, ','))
        arr.push_back(std::stoi(token));

    int offset;
    int opCode = 0;
    for (int i = 0; opCode != 99 && i < arr.size(); i += offset) {
        Inst inst(i, arr);
        opCode = inst.opCode;
        offset = inst.idxOffset;
    }
}
