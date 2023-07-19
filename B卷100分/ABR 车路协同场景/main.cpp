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

// ABR 车路协同场景
// 数轴×有两个点的序列 A={A1， A2, …, Am}和 B={B1, B2, ..., Bn}， Ai 和 Bj 均为正整数， A、 B 已经从小到大排好序， A、 B 均肯定不为空，

bool isNumber(char c){
    if (c >= '0' && c<= '9') {
        return true;
    }
    return false;
}

vector<int> getArrStringForStr(string s) {
    vector<int> vec;
    string tmp;
  
    for (int i = 0; i < s.length(); i++) {
        if (tmp.length() > 0 && s[i] == ',') {
            vec.push_back(stoi(tmp));
            tmp = "";
            
        } else if (isNumber(s[i])) {
            tmp += s[i];
        }
    }
    if (tmp.length() > 0) {
        vec.push_back(stoi(tmp));
        tmp = "";
    }

   
    return vec;
}

string getResult(vector<int> A, vector<int> B, int R) {
    vector<string> ans;
    int start = 0;
    for (int a : A) {
        bool isFind = false;
        for (int j = 0; j < B.size(); j++) {
            int b = B[j];
            if (b >= a && B[start] < a) {
                start = j;
            }
            if (a + R == b) {
                ans.push_back("(" + to_string(a) + "," + to_string(b) + ")");
                isFind = true;
                break;
            }
        }
        if (!isFind && B[start] >= a) {
            ans.push_back("(" + to_string(a) + "," + to_string(B[start]) + ")");
        }
    }
    string res;
    for (string an : ans) {
        res += an;
    }
    
    return res;
}

int main(int argc, const char * argv[]) {
    string s;
    getline(cin, s);
    
    int a1 = (int)s.find("A=");
    int b1 = (int)s.find("B=");
    int r1 = (int)s.find("R=");
    string s1 = s.substr(a1+ 2,b1 - a1 - 2);
    string s2 = s.substr(b1+ 2,r1 - b1 - 2);
    string s3 = s.substr(r1 + 2, (int)s.length());
    
    vector<int> A = getArrStringForStr(s1);
    vector<int> B = getArrStringForStr(s2);
    int R = stoi(s3);
    
    
    cout << getResult(A, B, R) << endl;
    
    return 0;
}
