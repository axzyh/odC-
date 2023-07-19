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
#include <unordered_set>
#include <regex>

using namespace std;



// 数字游戏
// 小明玩一个游戏。

class Case {
public: int m;
    vector<int> nums;
    Case(int n, vector<int>num) {
        m = n;
        nums = num;
    }
    
};

vector<int> getNumsArrForString(string str) {
    vector<int> arr;
    string tmp;
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        if (c == ' ' && tmp.length() > 0) {
            arr.push_back(stoi(tmp));
            tmp.clear();
        } else {
            tmp += c;
        }
    }
    if (tmp.length() > 0) {
        arr.push_back(stoi(tmp));
    }
    return arr;
}

int isExist(vector<int> nums, int m) {
    set<int> remain;
    remain.insert(0);
    int sum = 0;
    for (int num : nums) {
        sum += num;
        if (remain.count(sum % m)) {
            return 1;
        } else {
            remain.insert(sum % m);
        }
    }
    return 0;
}

void getResult(vector<Case> cases) {
    for (Case ca : cases) {
        cout << isExist(ca.nums, ca.m) << endl;
    }
}



int main(int argc, const char * argv[]) {
    
    vector<Case> cases;
    string line;
    string s1;
    while (true) {
        getline(cin, line);
        if (line == "") {
            getResult(cases);
            break;
        } else {
            vector<int> tmp = getNumsArrForString(line);
            getline(cin, s1);
            vector<int> nums = getNumsArrForString(s1);
            cases.push_back(Case(tmp[1],nums));
        }
    }
//    cout <<  << endl;
    
    return 0;
}
