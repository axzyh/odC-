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
//#include <algorithm>
#include <queue>
#include <unordered_set>
//#include <iterator>

using namespace std;

// 不开心的小朋友
// 游乐场里增加了一批摇摇车，非常受小朋友欢迎，但是每辆摇摇车同时只能有一个小朋友使用，如果没有空余的摇摇车，需要排队等候，或者直接离开，最后没有玩上的小朋友会非常不开心。
//

vector<string> getNumsArrForString(string str) {
    vector<string> arr;
    string tmp;
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        if (c == ' ' && tmp.length() > 0) {
            arr.push_back(tmp);
            tmp = "";
        } else {
            tmp += c;
        }
    }
    if (tmp.length() > 0) {
        arr.push_back(tmp);
    }
    return arr;
}

int getResult(int n, vector<string> arr) {
    int ans = 0;
    unordered_set<string> playing;
    vector<string> waiting;
    for (string ar : arr) {
        if (playing.count(ar)) {
            playing.erase(ar);
            if (waiting.size() > 0) {
                playing.insert(playing.end(),*waiting.begin());
                waiting.erase(waiting.begin());
            }
            continue;
        }
       
        vector<string>::iterator it = find(waiting.begin(),waiting.end(),ar);
        if (it != waiting.end()) {
            ans++;
            waiting.erase(it);
            continue;
        }
        if (playing.size() < n) {
            playing.insert(playing.end(),ar);
        } else {
            waiting.push_back(ar);
        }
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    string str;
    cin.ignore();
    getline(cin, str);
    vector<string> arr = getNumsArrForString(str);
   cout << getResult(n, arr) << endl;
    
    
    return 0;
}
