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



// 任务最优调度
// 给定一个正整数数组表示待系统执行的任务列表，数组的每一个元素代表一个任务，元素的值表示该任务的类型。

vector<int> getArrForString(string s) {
    vector<int> nums;
    
    string tmp;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ',') {
            nums.push_back(stoi(tmp));
            tmp = "";
        } else {
            tmp += s[i];
        }
    }
    if (tmp.length() > 0) {
        nums.push_back(stoi(tmp));
    }
    
    return nums;
}

bool compare(vector<int>a, vector<int>b){
    if (a[0] > b[0]) {
        return true;
    } else {
        return false;
    }
}

int getResult(vector<int>nums,int n) {
 
    map<int, int> map;
    for (int i:nums) {
        map[i]++;
    }
    
    vector<vector<int>>tasks;
    for (auto t: map) {
        tasks.push_back({t.second,0});
    }
    
    sort(tasks.begin(), tasks.end(),compare);
    
    int total = (int)nums.size();
    int time = 0;
    while (total > 0) {
        time++;
        bool flag = true;
        for (vector<int> &task : tasks) {
            if (flag && task[0] > 0 && task[1]==0) {
                flag = false;
                task[0]--;
                total--;
                task[1] = n;
            } else {
                if (task[1] > 0) {
                    task[1]--;
                }
            }
        }
    }
  
    return time;
}



int main(int argc, const char * argv[]) {
    
    string s1;
    int n;
    getline(cin, s1);
    
    vector<int> nums = getArrForString(s1);
    
    cin >> n;
    
  cout << getResult(nums,n) << endl;
    
    return 0;
}
