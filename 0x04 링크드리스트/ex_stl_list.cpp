int main(){
  list<int> L = {1,2}; // 1 2
  list<int>::iterator t = L.begin(); // t는 1을 가리키는 중
  L.push_front(10); // 10 1 2
  cout << *t << '\n'; // t가 가리키는 값 = 1 출력
  L.push_back(5); // 10 1 2 5
  L.insert(t, 6); // 10 6 1 2 5, t가 가리키는 곳에 6 삽입
  t++; // t는 이제 2 가리킴
  t = L.erase(t); // t가 가리키는 값 제거, 10 6 1 5
                  // 제거된 원소 다음 원소 5의 위치 retturn
                  // t가 가리키는 곳 5
  cout << *t << '\n'; // 5
  for (auto i: L) cout << i << ' ';
  cout << '\n';
}
