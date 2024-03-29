#include <iostream>
using namespace std;

int heap[100005] = {0};
int sz = 0; // heap에 들어있는 원소의 수

void push(int x)
{
    heap[++sz] = x;
    int pos = sz;
    while (pos != 1){
        int parent = pos/2;
        if (heap[parent] <= heap[pos]) break;
        swap(heap[parent], heap[pos]);
        pos = parent;
    }
}

int top()
{
    return heap[1];
}

void pop()
{
    heap[1] = heap[sz--];
    int pos = 1;
    while (pos*2 <= sz){ // 리프노드인지 체크해줘야함! 안그러면 Runtime error
        int l_child = pos*2; 
        int r_child = pos*2+1; // 오른쪽 자식 없을 수도 있음
        int min_child = l_child;
        if (r_child <= sz && heap[r_child] < heap[l_child]){
            min_child = r_child;
        }
        swap(heap[min_child], heap[pos]);
        pos = min_child;
    }
}

void test()
{
    push(10);
    push(2);
    push(5);
    push(9);               // {10, 2, 5, 9}
    cout << top() << '\n'; // 2
    pop();                 // {10, 5, 9}
    pop();                 // {10, 9}
    cout << top() << '\n'; // 9
    push(5);
    push(15);              // {10, 9, 5, 15}
    cout << top() << '\n'; // 5
    pop();                 // {10, 9, 15}
    cout << top() << '\n'; // 9
}

int main()
{
    test();
}
