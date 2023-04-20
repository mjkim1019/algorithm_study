#include <iostream>
using namespace std;

int n = 8;
int arr[8] = {6, -8, 1, 12, 8, 3, 7, -7};

void quick_sort(int st, int en)
{
    if (st +1 == en) return;
    int pivot = arr[st];
    int l = st + 1;
    int r = en - 1;
    while (true)
    {
        while (l <= r && pivot >= arr[l]) l++;
        while (l <= r && pivot < arr[r]) r--;
        if (l > r) break;
        swap(arr[l], arr[r]);
    }
    swap(arr[st], arr[r]);
    quick_sort(st, r);
    quick_sort(r+1, en);
}

int main()
{

    quick_sort(0, n);

    return 0;
}
