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

// 约瑟夫问题
// 输入一个由随机数组成的数列（数列中每个数均是大于 0 的整数，长度已知），和初始计数值 m。

vector<int> getArrNumsForString(string str) {
    vector<int> vec;
    string tmp;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ','&& tmp.length() > 0) {
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

string getResult(vector<int> intput_arr, int len, int m) {
   
    vector<int> output_arr;
    queue<int> dq;
    for (int num: intput_arr) {
        dq.push(num);
    }
    
    int i = 1;
    while (len > 0 && dq.size() > 0) {
        int out = dq.front();
        dq.pop();
        if (i == m) {
            output_arr.push_back(out);
            m = out;
            i = 1;
            len--;
        } else {
            dq.push(out);
            i++;
        }
    }
    
    string ans;
    for (int num : output_arr) {
        if (ans.length() > 0) {
            ans += ",";
        }
        ans += to_string(num);
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    
    string str;
    getline(cin, str);
    vector<int> intput_arr = getArrNumsForString(str);
    
    int len, m;
    cin >> len >> m;
    
    cout << getResult(intput_arr,len,m) << endl;
    
    return 0;
}
