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

// 停车场车辆统计
// 特定大小的停车场，数组cars[]表示，其中1表示有车，0表示没车。

vector<string> getArrStrForString(string str) {
    vector<string> vec;
    string tmp;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ','&& tmp.length() > 0) {
            vec.push_back(tmp);
            tmp = "";
        } else {
            tmp += str[i];
        }
    }
    if (tmp.length() > 0) {
        vec.push_back(tmp);
    }
    return vec;
}

int getResult(vector<string> arr) {
    int ans = 0;
    int count = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == "0") {
            if (count > 0) {
                ans++;
                count = 0;
            }
        } else {
            if (count++ >= 3) {
                ans++;
                count = 0;
            }
        }
    }
    
    return ans + 1;
}

int main(int argc, const char * argv[]) {
   
    string str;
    getline(cin, str);
//    replace(str.begin(), str.end(), ',', ''\0'');
    
    vector<string> arr = getArrStrForString(str);
    
  cout << getResult(arr) << endl;
    
    return 0;
}
