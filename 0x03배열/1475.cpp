#include <iostream>
#include <string>

using namespace std;

int main(){
    int num;
    cin >> num;

    int arr[10] = {0,};

    while(num > 0){
        arr[num%10]++;
        num /= 10;
    }

    int ans = -1;
    for (int i=0; i< 10; i++){
        if (i == 6 || i == 9) continue;
        ans = max(ans, arr[i]);
    }

    ans = max(ans, (arr[6] + arr[9]+1)/2);

    cout << ans;

    return 0;
}
