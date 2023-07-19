//
//  main.cpp
//  ODTest3
//
//  Created by YuChao on 2023/6/1.
//

#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <regex>


using namespace std;

// 数大雁
// 一群大雁往南飞，给定一个字符串记录地面上的游客听到的大雁叫声，请给出叫声最少由几只大雁发出。

long getResult(string quack) {
//    vector<int> q;
    queue<int>q;
    int u = 0, a = 0, c = 0;
    vector<vector<int>> ranges;
    for (int i = 0; i < quack.length(); i++) {
        switch (quack[i]) {
            case 'q':
                q.push(i);
                break;
            case 'u':
                if (u + 1 <= q.size()) {
                    u++;
                }
                break;
            case 'a':
                if (a + 1 <= u) {
                    a++;
                }
                break;
            case 'c':
                if (c + 1 <= a) {
                    c++;
                }
                break;
            case 'k':
                if (c >= 1) {
                    ranges.push_back({q.front(),i});
                    q.pop();
                    u--;
                    a--;
                    c--;
                }
                break;
                
            default:
                return -1;
        }
    }
    
    int ans = 1;
    for (int i = 0; i < ranges.size(); i++) {
        int count = 1;
        for (int j = i + 1; j < ranges.size(); j++) {
            if (ranges[i][1] >= ranges[j][0]) {
                count++;
            } else {
                break;
            }
        }
        ans = max(ans, count);
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    
    string quack;
    getline(cin, quack);
   
    cout << getResult(quack) << endl;
    
    return 0;
}
