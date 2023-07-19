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



// 比赛的冠亚季军
// 有N（3 ≤ N < 10000）个运动员，他们的id为0到N-1,他们的实力由一组整数表示。他们之间进行比赛，需要决出冠亚军。比赛的规则是0号和1号比赛，2号和3号比赛，以此类推，每一轮，相邻的运动员进行比赛，获胜的进入下一轮；实力值大的获胜，实力值相等的情况，id小的情况下获胜；轮空的直接进入下一轮。

class Sport{
public:  int id;
    long strength;
public:  Sport(int idx, long strengths) {
        id = idx;
        strength = strengths;
    }
};

vector<long> getArrForString(string str) {
    vector<long> arr;
    string tmp;
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        if (c == ' ' && tmp.length() > 0) {
            arr.push_back(stol(tmp));
            tmp = "";
        } else {
            tmp += c;
        }
    }
    if (tmp.length() > 0) {
        arr.push_back(stol(tmp));
    }
    return arr;
}


void promote(vector<Sport> sports, vector<vector<Sport>> &ans) {
    vector<Sport> win;
    vector<Sport> fail;
    for (int i = 1; i < sports.size(); i += 2) {
        Sport major = sports[i];
        Sport minor = sports[i - 1];
        if (major.strength > minor.strength) {
            win.push_back(major);
            fail.push_back(minor);
        } else {
            win.push_back(minor);
            fail.push_back(major);
        }
    }
    
    if (sports.size() % 2 != 0) {
        win.push_back(sports[sports.size() - 1]);
    }
    
    ans.insert(ans.begin(), fail);
    ans.insert(ans.begin(), win);
    while (ans.size() > 3) {
        ans.pop_back();
    }
    
}

bool compare(Sport a, Sport b) {
    if (a.strength > b.strength) {
        return true;
    } else if (a.strength == b.strength) {
        if (a.id < b.id) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}


string getResult(vector<long> nums) {
    vector<vector<Sport>> ans;
    vector<Sport> sports;
    for (int i = 0; i < nums.size(); i++) {
        sports.push_back(Sport(i, nums[i]));
    }
    
    promote(sports, ans);
    while (ans.front().size() > 1) {
        vector<Sport> tmp = ans.front();
        ans.erase(ans.begin());
        promote(tmp, ans);
        
    }
    
    // 冠军
    int first = ans[0][0].id;
    
    // 亚军
    int second = ans[1][0].id;
    
    sort(ans[2].begin(), ans[2].end(), compare);
    
    int third = ans[2][0].id;
  
    return to_string(first) + " " + to_string(second) + " " + to_string(third);
}



int main(int argc, const char * argv[]) {
  
    string str;
    getline(cin, str);
    vector<long> nums = getArrForString(str);
    cout << getResult(nums) << endl;
   
    
    return 0;
}
