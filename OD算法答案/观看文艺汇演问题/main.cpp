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

// 观看文艺汇演问题
// 为了庆祝中国共产党成立100周年，某公园将举行多场文艺表演，很多演出都是同时进行，一个人只能同时观看一场演出，且不能迟到早退，由于演出分布在不同的演出场地，所以连续观看的演出最少有15分钟的时间间隔，

vector<int> getArrNumsForString(string s) {
    vector<int> nums;
    string tmp;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ',' && tmp.length() > 0) {
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
    if (a[1] < b[1]) {
        return true;
    } else {
        return false;
    }
    
}


int getResult(int n, vector<vector<int>> ranges) {

    sort(ranges.begin(), ranges.end(),compare);
    int t = ranges[0][1];
    int ans = 1;
    for (int i = 1; i < ranges.size(); i++) {
        int l = ranges[i][0];
        int r = ranges[i][1];
        if (l - t >= 15) {
            ans++;
            t = r;
        }
    }
    

    return ans;
    
}

int main(int argc, const char * argv[]) {
   
    int n;
    cin >> n;
    vector<vector<int>> ranges(n,vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> ranges[i][0] >> ranges[i][1];
        ranges[i][1] += ranges[i][0];
    }
    
    
    cout << getResult(n, ranges) << endl;
    return 0;
}
