#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int alphabet[26];

struct CharFrequency{
    char ch;
    int frequency;
    int order;
    
    CharFrequency(char c, int f, int o) : ch(c), frequency(f), order(o) {}

    bool operator<(const CharFrequency & other) const {
        if (frequency != other.frequency){
            return frequency < other.frequency;
        } else {
            return order > other.order;
        }
    }
};

int main(){
    int N;
    cin >> N;

    priority_queue<CharFrequency> PQ;

    for (int i=0; i<N; i++){
        string str;
        cin >> str;
        if (str == "enqueue"){
            char c; cin >> c;
            alphabet[c-'A']++;
            PQ.push(CharFrequency(c, alphabet[c-'A'], i));
        } else if (str == "dequeue"){
            
            if (!PQ.empty()) {
                cout << PQ.top().ch << '\n';
                alphabet[PQ.top().ch]--;
                PQ.pop();
            }
        }
    }
    
    return 0;
}
