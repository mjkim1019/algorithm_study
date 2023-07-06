#include <string>
#include <vector>

using namespace std;

int cnt_binary(int n){
    int cnt = 0;
    while (n > 1){
        if (n%2 == 1) cnt++;
        n /= 2;
    }
    if (n == 1) cnt++;
    return cnt;
}

int solution(int n) {
    int nxt = n;
    int one = cnt_binary(n);
    
    while (true){
        nxt++;
        if (cnt_binary(nxt) == one) return nxt;
    }
    
    return -1;
}
