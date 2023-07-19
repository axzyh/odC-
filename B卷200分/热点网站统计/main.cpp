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

// 热点网站统计
// 企业路由器的统计页面，有一个功能需要动态统计公司访问最多的网页URL top N。请设计一个算法，可以高效动态统计Top N的页面。

bool isNum(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] < '0' || s[i] >'9') {
            return false;
        }
    }
    return true;
}

bool compare(pair<string, int>a, pair<string, int> b) {
    if (a.second > b.second) {
        return true;
    } else if (a.second == b.second) {
        if (a.first <= b.first) {
            return true;
        } else {
            return false;
        }
    }
    
    else {
        return false;
    }
}


string sortURL(vector<string> &urls, int n, map<string, int> &cache) {
    for (string url : urls) {
        cache[url]++;
    }
    
    int count = 0;
    string tmp;
    
    vector<pair<string, int>> vec(cache.begin(),cache.end());
    sort(vec.begin(), vec.end(), compare);
    for (auto m:vec) {
        if (count >= n) {
            break;
        }
        if (tmp.length() > 0) {
            tmp += ",";
        }
        count++;
        tmp += m.first;
    }
    return tmp;
}



int main(int argc, const char * argv[]) {
    vector<string> urls;
    map<string, int> cache;
    vector<string> ans;
    
    string tmp;
    while (true) {
        getline(cin, tmp);
        if (tmp == "") {
            for (string an : ans) {
                cout << an << endl;
            }
           
            break;
        }
        
        if (isNum(tmp)) {
            ans.push_back(sortURL(urls, stoi(tmp), cache));
            urls = vector<string>();
        } else {
            urls.push_back(tmp);
        }
    }
    return 0;
}
