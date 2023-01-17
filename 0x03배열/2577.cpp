#include <iostream>
#include <string>

using namespace std;

int main(){
    int a, b, c;
    int num;
    int arr[10] = {0,};

    cin >> a>> b>> c;

    num = a * b* c;
    while(num > 0){
        arr[num%10]++;
        num /= 10;
    }

    for (auto i: arr){
        cout << i << '\n';
    }


    return 0;
}
