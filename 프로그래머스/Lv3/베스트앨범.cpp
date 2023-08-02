#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

bool play_cmp(pair<int, int> &a, pair<int, int> &b){
    if (a.X == b.X) return a.Y < b.Y;
    return a.X > b.X;
}

bool cnt_cmp(pair<string, int> &a, pair<string, int> &b){
    if (a.Y != b.Y) return a.Y > b.Y;
    return true;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    map<string, int> cnt_map;
    map<string, vector<pair<int, int>>> genres_v; // {장르, {재생 횟수, 고유번호}}
    for (int i=0; i<genres.size(); i++){
        string g = genres[i];
        int p = plays[i];
        cnt_map[g] += p;
        genres_v[g].push_back({p, i});
    }
    
    vector<pair<string, int>> cnt_v(cnt_map.begin(), cnt_map.end());
    sort(cnt_v.begin(), cnt_v.end(), cnt_cmp);
    
    for (auto &e: genres_v){
        auto &v = e.second;
        sort(v.begin(), v.end(), play_cmp);
    }
    
    for (int i=0; i<cnt_v.size(); i++){
        string genre = cnt_v[i].X;
        auto v = genres_v[genre];
        for (int i=0; i<2 && i<v.size(); i++){
            answer.push_back(v[i].Y);
            //cout << genre << ": " << v[i].first << ' ' << v[i].second <<'\n';
        }
    }
    
    return answer;
}
