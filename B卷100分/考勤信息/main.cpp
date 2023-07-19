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

// 考勤信息
// 公司用一个字符串来表示员工的出勤信息

vector<string> getArrStrForString(string str) {
    vector<string> vec;
    string tmp;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' '&& tmp.length() > 0) {
            vec.push_back(tmp);
            tmp = "";
        } else {
            tmp += str[i];
        }
    }
    if (tmp.length() > 0) {
        vec.push_back(tmp);
    }
    return vec;
}

string isAward(vector<string> record) {
    int absent = 0;
    int present = 0;
    string pre ="";
    
    for (int i = 0; i < record.size(); i++) {
        string cur = record[i];
        if (cur == "absent") {
            if (++absent > 1) {
                return "false";
            }
        } else if (cur == "late" || cur == "leveearly") {
            if (pre == "late" || pre == "leveearly") {
                return "false";
            }
        } else if (cur == "present"){
            present++;
        }
        pre = cur;
        if ( i >= 6) {
            if (present < 4) {
                return "false";
            }
            if (record[i - 6] == "present") {
                present--;
            }
        }
    }
    
    return "true";
}

void getResult(int n, vector<vector<string>> records) {
  
    for (int i = 0; i < n; i++) {
        cout << isAward(records[i]) << endl;
    }
}

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    cin.ignore();
    string s;
    vector<vector<string>> records(n);
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        vector<string> record = getArrStrForString(s);
        records[i] = record;
    }
     getResult(n, records);
    
    return 0;
}
