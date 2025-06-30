#include "vector.h"
#include <cassert>
#include <iostream>

int main() {
    vector<int> vec1(100);
    assert(vec1.size() == 100);
    vec1.pop_back();
    assert(vec1.size() == 99);
    vec1.push_back(1);
    assert(vec1.size() == 100);
    for (int i = 0; i < vec1.size(); i++) {
        std::cout << vec1[i] << std::endl;
    }
    assert(vec1[99] == 1);
}
