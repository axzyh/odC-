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

// 找终点
// 给定一个正整数数组，设为nums，最大为100个成员，求从第一个成员开始，正好走到数组最后一个成员，所使用的最少步骤数。

vector<int> getArrNumsForString(string str) {
    vector<int> vec;
    string tmp;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' '&& tmp.length() > 0) {
            vec.push_back(stoi(tmp));
            tmp = "";
        } else {
            tmp += str[i];
        }
    }
    if (tmp.length() > 0) {
        vec.push_back(stoi(tmp));
    }
    return vec;
}

int loop(vector<int> arr, int i, int count) {
    int j = i + arr[i];
    if (j == arr.size() - 1) {
        return count;
    } else if (j <= arr.size() - 1) {
        count++;
        return loop(arr, j, count);
    } else {
        return -1;
    }
}

int getResult(string str) {
    vector<int> arr = getArrNumsForString(str);
    vector<int> res;
    for (int i = 1; i <= arr.size()/2; i++) {
        int result = loop(arr, i, 2);
        if (result > 0) {
            res.push_back(result);
        }
    }
    
    sort(res.begin(), res.end());
    
    return res[0];
}

int main(int argc, const char * argv[]) {
    string str;
    getline(cin,str);
    cout << getResult(str) << endl;
    
    return 0;
}
