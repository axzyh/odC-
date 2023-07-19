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

// 计算数组中心位置
// 给你一个整数数组nums，请计算数组的中心位置，数组的中心位置是数组的一个下标，其左侧所有元素相乘的积等于右侧所有元素相乘的积。数组第一个元素的左侧积为1，最后一个元素的右侧积为1。
/*
 2 5 3 6 5 6
*/

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


int getResult(vector<int> arr) {
    // 数量级问题
    long long fact = 1;
//    int dd = 1;
    for (int num : arr) {
        fact *= num;
    }
    long long left = 1;
    long long right = fact / arr[0];
    if (left == right) {
        return 0;
    }
    
    for (int i = 1; i < arr.size(); i++) {
        left *= arr[i - 1];
        right /= arr[i];
        if (left == right) {
            return i;
        }
    }
    
    return -1;

}



int main(int argc, const char * argv[]) {
    string str;
    getline(cin, str);
    
    vector<int> arr = getArrStringForS(str);
  
    cout << getResult(arr) << endl;
//
    return 0;
}




