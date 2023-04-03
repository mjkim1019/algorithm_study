/*
1. 함수의 정의
입력 횟수만큼 "재귀함수가 뭔가요" ~ "~물었어." 출력해주는 함수
void func(int n)

2. base condition
if (n == 0) { 재귀함수는~ 답변 출력; return; }

3. 재귀식
1번 출력할 수 있다
k번 출력할 수 있으면, k+1번도 출력할 수 있다.
*/

#include <iostream>
#include <string>
using namespace std;

string str[5] = {"\"재귀함수가 뭔가요?\"",
                 "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.",
                 "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.", 
                 "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"",
                 "라고 답변하였지."};
int N;

void _bar(int n){
    for (int i=0; i<n; i++)
        cout << "____";
}

void func(int n)
{
    _bar(n);
    cout << str[0] << '\n';
    
    if (n == N) {
        _bar(n);
        cout << "\"재귀함수는 자기 자신을 호출하는 함수라네\"" << '\n';
    } else {
        _bar(n);
        cout << str[1] << '\n';
        _bar(n);
        cout << str[2] << '\n';
        _bar(n);
        cout << str[3] << '\n';
        
        func(n+1);
    }
    _bar(n);
    cout << str[4] << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
    func(0);

    return 0;
}
