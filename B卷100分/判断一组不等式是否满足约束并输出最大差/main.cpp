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

// 判断一组不等式是否满足约束并输出最大差
// 给定一组不等式，判断是否成立并输出不等式的最大差(输出浮点数的整数部分)

vector<vector<string>> getArrStrForString(string str) {
    vector<vector<string>> vec;
    vector<string> vec1;
    string tmp;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ',' && tmp.length() > 0) {
            vec1.push_back(tmp);
            tmp = "";
        } else if (str[i] == ';') {
            if (tmp.length() > 0) {
                vec1.push_back(tmp);
            }
            vec.push_back(vec1);
            vec1.clear();
            tmp = "";
        } else {
            tmp += str[i];
        }
    }
    if (tmp.length() > 0) {
        vec1.push_back(tmp);
    }
    
    if (vec1.size() > 0) {
        vec.push_back(vec1);
    }
    return vec;
}

vector<double> getDoubleForArr(vector<string> arr) {
    int n = (int)arr.size();
    vector<double> vec(n);
    for (int i = 0; i < n; i++) {
        vec[i] = stod(arr[i]);
    }
    return vec;
}

bool compareWithZero(double val, string constaraint) {
    bool flag = false;
    if (constaraint == ">") {
        flag = val > 0;
    } else if (constaraint == ">=") {
        flag = val >= 0;
    } else if (constaraint == "<") {
        flag = val < 0;
    } else if (constaraint == "<=") {
        flag = val <= 0;
    } else if (constaraint == "=") {
        flag = val = 0;
    }
    return flag;
}

int main(int argc, const char * argv[]) {
   
    string str;
    getline(cin, str);
    
    vector<vector<string>> arr = getArrStrForString(str);
    
    vector<double> a1 = getDoubleForArr(arr[0]);
    vector<double> a2 = getDoubleForArr(arr[1]);
    vector<double> a3 = getDoubleForArr(arr[2]);
    vector<double> x = getDoubleForArr(arr[3]);
    vector<double> b = getDoubleForArr(arr[4]);
    vector<string> y = arr[5];
    double diff1 = a1[0] * x[0] + a1[1] * x[1] +a1[2] * x[2] + a1[3] * x[3] + a1[4] * x[4] - b[0];
    double diff2 = a2[0] * x[0] + a2[1] * x[1] +a2[2] * x[2] + a2[3] * x[3] + a2[4] * x[4] - b[1];
    double diff3 = a3[0] * x[0] + a3[1] * x[1] +a3[2] * x[2] + a3[3] * x[3] + a3[4] * x[4] - b[2];
    
    
    bool flag = compareWithZero(diff1, y[0]) && compareWithZero(diff2, y[1]) && compareWithZero(diff3, y[2]);
    int maxDiff = max(diff1, max(diff2, diff3));
    
    string res;
    if (flag == true) {
        res = "true";
    } else {
        res = "false";
    }
    res +=  " " + to_string(maxDiff);
    
    cout << res << endl;
    
    return 0;
}
