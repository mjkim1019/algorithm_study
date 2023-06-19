#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    unordered_map<string, int> m;
    
    for (int i=0; i<name.size(); i++){
        m[name[i]] = yearning[i];
    }
    
    for (auto v: photo){
        int sum = 0;
        for (string s: v){
            sum += m[s];
        }
        answer.push_back(sum);
    }
    
    return answer;
}
