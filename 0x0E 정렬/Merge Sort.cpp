#include <iostream>
using namespace std;

int n=10;
int arr[1000001] = {15, 25, 22, 357, 16, 23, -53, 12, 46, 3};
int tmp[1000001];

// 정렬된 배열 합치기
void merge(int st, int en){
    int mid = (st+en)/2;
    
    int idx1 = st;
    int idx2 = mid;
    for (int i = st; i<en; i++){
        if (idx1 == mid) tmp[i] = arr[idx2++];
        else if (idx2 == en) tmp[i] = arr[idx1++];
        else if (arr[idx1] <= arr[idx2]) tmp[i] = arr[idx1++];
        else tmp[i] = arr[idx2++];
    }

    for (int i=st; i<en; i++) arr[i] = tmp[i];
}

// 분할 & 정렬
void merge_sort(int st, int en){
    if (st+1 == en) return; // 길이가 1
    int mid = (st+en)/2;
    merge_sort(st, mid); 
    merge_sort(mid, en); 
    merge(st, en); // arr[st:md]와 arr[mid:st]를 병합
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    merge_sort(0, n);
    for (int i=0; i<n; i++) cout << arr[i] << ' ';

    return 0;
}
