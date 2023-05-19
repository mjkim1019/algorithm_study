#include <bits/stdc++.h>

using namespace std;


vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer(2);
    
    int mxcnt = 0;
    int mxsum = 0;
    
    vector<int> discounts = {10, 20, 30, 40};
    for (int tmp=0; tmp<(1 << 2*emoticons.size()); tmp++){
        vector<int> userMoney(users.size());
        fill(userMoney.begin(), userMoney.end(), 0);
        
        int brute = tmp;
        for (int k=0; k<emoticons.size(); k++){
            int dis = discounts[brute%4];
            brute /= 4;  
            
            int price = emoticons[k]*(100-dis)*0.01;
            
            for (int i=0; i<users.size(); i++){
                if (users[i][0] <= dis) {
                    userMoney[i] += price;
                }
            }
        }
        
        
        int cnt = 0;
        int sum = 0;
        for (int i=0; i<users.size(); i++){
            if (userMoney[i] >= users[i][1]) cnt++;
            else sum += userMoney[i];
        }
       
        if (cnt > mxcnt) {
            mxcnt = cnt;
            mxsum = sum;
        } else if (cnt == mxcnt) {
            mxsum = max(mxsum, sum);
        }
    }
    
    answer[0] = mxcnt;
    answer[1] = mxsum;
    
    return answer;
}
