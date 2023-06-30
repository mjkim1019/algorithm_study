#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> reports, int k)
{
    vector<int> answer;
    
    unordered_map<string, unordered_set<string>> result_name;
    unordered_map<string, int> result_cnt;
    unordered_map<string, int> result;
    
    for (string & id: id_list) result[id] = 0;
    
    sort(reports.begin(), reports.end());
    reports.erase(unique(reports.begin(), reports.end()), reports.end());
    for (string &str: reports){
        stringstream ss(str);
        vector<string> report(2);
        ss >> report[0] >> report[1];
        //cout << report[0] <<" -> " << report[1] << "\n";
        
        result_name[report[1]].insert(report[0]);
        result_cnt[report[1]] += 1;
    }
    
    for (string & id: id_list){
        //cout << id << ": " << result_cnt[id]<< '\n';
        if (result_cnt[id] < k) continue;
        
        // 신고횟수 result[id] >= k
        for (string name: result_name[id]){
            result[name] += 1;
        }
    }
    for (string &id: id_list){
        answer.push_back(result[id]);
    }

    return answer;
}
