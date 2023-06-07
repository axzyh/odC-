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



// 组装新的数组
// 给你一个整数M和数组N，N中的元素为连续整数，要求根据N中的元素组装成新的数组R，组装规则：R中元素总和加起来等于M
vector<int> getArrForString(string s) {
    vector<int> res;
    string temp;
    for (int i = 0; i < s.length(); i++) {
        if (temp.length() > 0 && s[i] == ' ') {
            res.push_back(stoi(temp));
            temp = "";
        } else {
            temp += s[i];
        }
    }
    if (temp.length() > 0) {
        res.push_back(stoi(temp));
    }
    return res;
}

int dfs(vector<int>arr,int index,int sum,int min, int m,int count) {
    if (sum > m) {
        return count;
    }
    if (sum == m || (m - sum < min && m - sum > 0)) {
        return count +1;
    }
    for (int i = index; i < arr.size(); i++) {
        count = dfs(arr, i, sum + arr[i], min, m, count);
    }
    return count;
}

int getResult(vector<int> arr,int m) {
    
    vector<int> newArr;
    for (int i =0; i < arr.size(); i++) {
        if (arr[i] <= m) {
            newArr.push_back(arr[i]);
        }
    }
    return dfs(newArr, 0, 0, arr[0], m, 0);
}

int main(int argc, const char * argv[]) {
    string str;
    int m;
    getline(cin, str);
    cin >> m;
    vector<int> res = getArrForString(str);
    cout << getResult(res,m) << endl;
    
    return 0;
}
