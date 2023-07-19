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

// 计算误码率
// 误码率是最常用的数据通信传输质量指标。它可以理解为“在多少位数据中出现一位差错”。
//

class ZipStr {
public:  int num;
    char c;
public:  ZipStr(int n, char s) {
        num = n;
        c = s;
    }
};


vector<ZipStr> getZipStrLink(string s) {
    vector<ZipStr> arr;
    string num;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (c >= '0' && c <= '9') {
            num += c;
        } else {
            arr.push_back(ZipStr(stoi(num),c));
            num.clear();
        }
    }
    return arr;
}

string getResult(string s1, string s2) {
    vector<ZipStr> link1 = getZipStrLink(s1);
    vector<ZipStr> link2 = getZipStrLink(s2);
    int diff = 0;
    int same = 0;
    while (link1.size() > 0) {
        ZipStr zipstr1 = link1.front();
        ZipStr zipstr2 = link2.front();
        link1.erase(link1.begin());
        link2.erase(link2.begin());
        
        int compareCount = min(zipstr1.num, zipstr2.num);
        if (zipstr1.c != zipstr2.c) {
            diff += compareCount;
        } else {
            same += compareCount;
        }
        
        if (zipstr1.num > compareCount) {
            zipstr1.num -= compareCount;
            link1.insert(link1.begin(), zipstr1);
            continue;
        }
        if (zipstr2.num > compareCount) {
            zipstr2.num -= compareCount;
            link2.insert(link2.begin(), zipstr2);
            continue;
        }
    }
    return to_string(diff) + "/" + to_string(same + diff);
   
}

int main(int argc, const char * argv[]) {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    
   cout << getResult(s1,s2) << endl;
    
    
    return 0;
}
