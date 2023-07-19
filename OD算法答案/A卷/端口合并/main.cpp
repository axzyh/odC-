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

// 端口合并
// 有M个端口组(1<=M<=10)，
/*
 3
 2,3,1
 4,3,2
 5
*/


vector<int> getArrStringForS(string str) {
    vector<int> arr;
    string tmp;
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        if (c == ',' && tmp.length() > 0) {
            arr.push_back(stoi(tmp));
            tmp = "";
        } else {
            tmp += c;
        }
    }
    if (tmp.length() > 0) {
        arr.push_back(stoi(tmp));
    }
    return arr;
}



bool canUnion(vector<int> a, vector<int> b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int same = 0;
    int i = 0;
    int j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] == b[j]) {
            same++;
            i++;
            j++;
            if (same >= 2) {
                return true;
            }
        } else if(a[i] > b[j]){
            j++;
        } else {
            i++;
        }
    }
    return false;
}

string getResult(vector<vector<int>> ports) {
    bool isFlag = false;
    
    while (true) {
        for (int i = (int)ports.size() - 1; i >= 0; i--) {
            isFlag = false;
            for (int j = i - 1; j >= 0; j--) {
                if (canUnion(ports[i], ports[j])) {
                    ports[j].insert(ports[j].end(), ports[i].begin(),ports[i].end());
                    ports.erase(ports.begin() + i);
                    isFlag = true;
                    break;
                }
            }
            if (isFlag) {
                continue;
            }
        }
        break;
    }
    
    string out = "[";
    for (vector<int> port : ports) {
        string res = "[";
        for (int v : set<int>(port.begin(),port.end())) {
            if (res.length() > 1) {
                res += ",";
            }
            res += to_string(v);
        }
        res += "]";
        if (out.length() > 1) {
            out += ",";
        }
        out += res;
        
    }
    
    out += "]";
    return out;

}



int main(int argc, const char * argv[]) {
    int m;
    cin >> m;
    
    if (m > 10 || m < 1) {
        cout << "[[]]" << endl;
        return 0;
    }
    
    
    vector<vector<int>> ports;
    cin.ignore();
    string str;
    for (int i = 0; i < m; i++) {
        getline(cin, str);
        vector<int> tmp = getArrStringForS(str);
        int n = (int)tmp.size();
        if (n < 1 || n > 100) {
            cout << "[[]]" << endl;
            return 0;
        }
        ports.push_back(tmp);
    }
  
    cout << getResult(ports) << endl;
//
    return 0;
}




