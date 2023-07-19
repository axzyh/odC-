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

using namespace std;

// 跳格子游戏
// 地上共有N个格子，你需要跳完地上所有的格子，但是格子间是有强依赖关系的，跳完前一个格子后，后续的格子才会被开启，格子间的依赖关系由多组steps数组给出，steps[0]表示前一个格子，steps[1]表示steps[0]可以开启的格子:

vector<int> getArrNumsForString(string s) {
    vector<int>nums;
    string temp;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ' && temp.length() > 0) {
            nums.push_back(stoi(temp));
            temp = "";
        } else {
            temp += s[i];
        }
    }
    if (temp.length() > 0) {
        nums.push_back(stoi(temp));
    }
    return nums;
    
}

string getResult(int n, vector<vector<int>>relations) {
    vector<int> inDegree(n);
    unordered_map<int, vector<int>> next;
    for (vector<int> relation : relations) {
        int a = relation[0], b = relation[1];
        inDegree[b]++;
        next[a].push_back(b);
    }
    
    stack<int> stack;
   
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            stack.push(i);
        }
    }
    int count = 0;
    while (stack.size() > 0) {
        int a = stack.top();
        stack.pop();
        count++;
        if (next.count(a)) {
            for (int b : next[a]) {
                if (--inDegree[b] == 0) {
                    stack.push(b);
                }
            }
        }
    }
   
      return  count == n ? "yes":"no";
    
}

int main(int argc, const char * argv[]) {
   
    int n;
    string str;
    cin >> n;
    cin.ignore();
    vector<vector<int>> relations;
    while (getline(cin, str)) {
        if (str == "") {
            break;
        }
        relations.push_back(getArrNumsForString(str));
    }
    
    
//    getline(cin, tar);
    
    cout << getResult(n,relations) << endl;
    return 0;
}
