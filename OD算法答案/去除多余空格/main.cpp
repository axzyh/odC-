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



// 去除多余空格
// 去除文本多余空格，但不去除配对单引号之间的多余空格。给出关键词的起始和结束下标，去除多余空格后刷新关键词的起始和结束下标。

vector<vector<int>>getVecForS2(string s) {
    vector<vector<int>> vec;
    vector<int> v1;
    string temp;
    for (int i = 0; i < s.length(); i++) {
        if (temp.length() > 0 && s[i] == ' ') {
            v1.push_back(stoi(temp));
            temp = "";
        } else if (s[i] == ',') {
            v1.push_back(stoi(temp));
            temp = "";
            vec.push_back(v1);
            v1 = vector<int>();
        } else {
            temp += s[i];
        }
    }
    if (temp.length() > 0) {
        v1.push_back(stoi(temp));
        temp = "";
        vec.push_back(v1);
        v1 = vector<int>();
    }
    
    return vec;
}

void getResult(string str,vector<vector<int>> ranges) {
    bool quotaStart = false;
    vector<int> needDel;
    
    vector<string> sArr;
    for (int i = 0; i < str.length(); i++) {
        string s = "";
        s.append(1,str[i]);
        sArr.push_back(s);
    }
   
    for (int i = 0; i < str.length(); i++) {
        if (i > 0 && sArr[i] == " " && sArr[i - 1] == " " && !quotaStart) {
            needDel.push_back(i);
        }
        if (sArr[i] == "'") {
            quotaStart = !quotaStart;
        }
    }
    
    for (int j = (int)needDel.size() - 1; j >=0; j--) {
        int del = needDel[j];
        sArr[del] = "";
        sArr.erase(sArr.begin()+del);
        for (int i = 0; i < ranges.size(); i++) {
            int start = ranges[i][0];
            if (del < start) {
                ranges[i][0]--;
                ranges[i][1]--;
            }
        }
    }
    string temp;
    for (string s : sArr) {
        temp +=s;
    }
    cout << temp << endl;
    
    string sb;
    
    for (vector<int> an : ranges) {
        string st = "[";
        st += to_string(an[0]);
        st += ",";
        st += to_string(an[1]);
        st += "]";
        sb += st;
    }
    cout << sb << endl;
    
}

int main(int argc, const char * argv[]) {
    
    string s1,s2;
    vector<vector<int>> ranges;
    getline(cin, s1);
    getline(cin, s2);
    ranges = getVecForS2(s2);
    
    getResult(s1, ranges);
    
    return 0;
}
