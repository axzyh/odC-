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
#include <iomanip>


using namespace std;

// 最多颜色的车辆
// 在一个狭小的路口，每秒只能通过一辆车，假设车辆的颜色只有 3 种，找出 N 秒内经过的最多颜色的车辆数量。

vector<int> getArrStringForS(string str) {
    vector<int> arr;
    string tmp;
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        if (c == ' ' && tmp.length() > 0) {
            arr.push_back(stoi(tmp));
            tmp = "";
        } else {
            tmp += c;
        }
    }
    if (tmp.length() > 0) {
        arr.push_back(stoi(tmp));
    }
    return arr;
}



int getResult(vector<int> arr,int n) {
    unordered_map<int, int> count;
  
    int l = 0;
    int r = l + n;
    int maxLen = 0;
    for (int i = l; i < min(r,(int)arr.size()); i++) {
        int c = arr[i];
        count[c]++;
        maxLen = max(maxLen, count[c]);
    }
    
    while (r < arr.size()) {
        int add = arr[r++];
        int remove = arr[l++];
        count[add]++;
        count[remove]--;
        maxLen = max(maxLen, count[add]);
    }
    
    
  
    return maxLen;
}



int main(int argc, const char * argv[]) {
    string str;
    getline(cin, str);
    vector<int> arr = getArrStringForS(str);
    int n;
    cin >> n;
    
    cout << getResult(arr,n) << endl;
//
    return 0;
}




