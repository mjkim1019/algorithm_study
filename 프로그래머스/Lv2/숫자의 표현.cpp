#include <string>
#include <vector>

using namespace std;

int d[10005];

int solution(int n) {
    int answer = 0;
    
    d[0] = 0;
    for (int i=1; i<= n; i++) d[i] = d[i-1] + i;
    
    for (int i=n; i>=0; i--){
        for (int j=i-1; j >=0; j--){
            if (d[i] - d[j] < n) continue;
            else if (d[i] - d[j] == n) 
                answer++; 
            
            break;
        }
    }
    
    return answer;
}
