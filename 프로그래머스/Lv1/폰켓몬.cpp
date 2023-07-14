#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> nums)
{
  // 1) vector 중복 제거 방법
    int N = nums.size();
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    if (nums.size() >= N/2) return N/2;
    else return nums.size();
  
  // 2) set 중복 제거 방법
    unordered_set<int> s(nums.begin(), nums.end());
    return min(nums.size()/2, s.size());
    
}
