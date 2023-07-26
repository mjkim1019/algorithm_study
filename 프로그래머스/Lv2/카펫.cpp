#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    int area = brown + yellow;
    for (int n=3; n<= area/n; n++){
        if (area % n != 0) continue;
        int m = area /n;
        if ((n-2)*(m-2) == yellow) return {m, n};
    }
}
