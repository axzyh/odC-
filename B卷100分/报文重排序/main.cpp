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
#include <regex>

using namespace std;



// 报文重排序
// 对报文进行重传和重排序是常用的可靠性机制，重传缓中区内有一定数量的子报文，每个子报文在原始报文中的顺序已知，现在需要恢复出原始报文。
bool compare(pair<string, int> a, pair<string, int> b) {
    if (a.second < b.second) {
        return true;
    }
    return false;
}

pair<string, int> getPairForStr (string str){
    int pos = -1;
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        if (isnumber(c)) {
            pos = i;
            break;
        }
    }
    string frist = str.substr(0, pos);
    string second = str.substr(pos, str.length());
    
    return make_pair(frist, stoi(second));
}

string getResult(int n,vector<string> arr) {
    vector<pair<string, int>> ans;

    for (string str : arr) {
        ans.push_back(getPairForStr(str));
    }
    
    sort(ans.begin(), ans.end(), compare);
    
    string res;
    for (pair<string, int> an : ans) {
        if (res.length() > 0) {
            res += " ";
        }
        res += an.first;
    }
    
    return res;
}

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    string str;
    vector<string> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << getResult(n,arr) << endl;
    return 0;
}
