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

// 过滤组合字符串
// 每个数字关联多个字母，关联关系如下：

vector<string> strArr = {"abc","def","ghi","jkl","mno","pqr","st","uv","wx","yz"};


bool include(vector<char> path, string k) {
    
    string res = string(path.begin(),path.end());
    
    sort(res.begin(), res.end());
    int pos = (int)res.find(k);
    return pos >= 0;
    
}

void dfs(vector<string>arr,int index, vector<char> &path, vector<string> &res,string k) {
    if (index == arr.size()) {
        if (!include(path, k)) {
            string ans = string(path.begin(),path.end());
            res.push_back(ans);
        }
        return;
    }
    
    for (int i = 0; i < arr[index].length(); i++) {
        path.push_back(arr[index][i]);
        dfs(arr, index + 1, path, res, k);
        path.pop_back();
    }
}

string getResult(vector<int> arr, string k) {
    vector<string> newArr;
    for (int val : arr) {
        newArr.push_back(strArr[val]);
    }
    vector<char> cArr(k.begin(),k.end());
    sort(cArr.begin(), cArr.end());
    k = string(cArr.begin(),cArr.end());
    vector<string> res;
    
    vector<char> path;
    dfs(newArr, 0, path, res, k);
    string ans;
    for (string str : res) {
        ans += str;
        ans += ",";
    }
    
    
    return ans;
}



int main(int argc, const char * argv[]) {
    string str,k;
    
    cin >> str >> k;
    vector<int> arr(str.length());
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        arr[i] = c - '0';
    }
    cout << getResult(arr,k) << endl;
//
    return 0;
}




