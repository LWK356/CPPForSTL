#include <iostream>
#include "myVector.h"
#include <algorithm>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    myVector<int> vi;
    vi.push_back(2);
    vi.push_back(4);
    vi.push_back(1);
    vi.push_back(3);
    vi.push_back(5);

    for (int i = 0; i < 5; ++i) {
        std::cout << vi[i];
    }
    sort(vi.begin(), vi.end());
    for (int i = 0; i < 5; ++i) {
        std::cout << vi[i];
    }
    return 0;
}