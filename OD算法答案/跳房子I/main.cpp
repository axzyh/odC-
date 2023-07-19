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

// 跳房子I
// 跳房子，也叫跳飞机，是一种世界性的儿童游戏。

vector<int> getArrNumsForString(string s) {
    vector<int> nums;
    string tmp;
    for (int i = 0; i < s.length(); i++) {
        if ((s[i] == ',' || s[i] == ']') && tmp.length() > 0) {
            nums.push_back(stoi(tmp));
            tmp = "";
        } else if (s[i] == '[')
            continue;
        else {
            tmp += s[i];
        }
    }
    if (tmp.length() > 0) {
        nums.push_back(stoi(tmp));
    }
    return nums;
}

string getResult(vector<int> steps, int count) {
    unordered_map<int, int> map;
    int minIdxSum = INT_MAX;
    string ans = "";
    
    for (int idx1 = 0; idx1 < steps.size(); idx1++) {
        int step1 = steps[idx1];
        int step2 = count - step1;
        if (map.count(step2)) {
            int idx2 = map[step2];
            int idSum = idx1 + idx2;
            if (idSum < minIdxSum) {
                minIdxSum = idSum;
                ans = idx1 < idx2 ? "[" + to_string(step1) + "," + to_string(step2) + "]" :"[" + to_string(step2) + "," + to_string(step1) + "]";
            }
        } else {
            map[step1] = idx1;
        }
    }
    return ans;
    
}

int main(int argc, const char * argv[]) {
    string str;
    int count;
    getline(cin, str);
    vector<int> steps = getArrNumsForString(str);
    cin >> count;
    
    cout << getResult(steps, count) << endl;
    return 0;
}
