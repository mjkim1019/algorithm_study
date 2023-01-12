#include <iostream>

using namespace std;

int seq[10001];

bool func2(int arr[], int N) {
    for (auto i: arr) {
        if (seq[100-i] > 0) return true;
        else seq[i] = 1;
    }

    return false;
}
