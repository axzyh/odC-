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

// VLAN资源池
// VLAN是一种对局域网设备进行逻辑划分的技术，为了标识不同的VLAN，引入VLAN ID(1-4094之间的整数)的概念。

vector<string> getArrStringForString(string s) {
    vector<string> arr;
    string tmp;
    for (int i = 0; i < s.length(); i++) {
        if (tmp.length() > 0 && s[i] == ',') {
            arr.push_back(tmp);
            tmp = "";
        } else {
            tmp += s[i];
        }
    }
    if (tmp.length() > 0) {
        arr.push_back(tmp);
    }
    
    return arr;
}

vector<pair<int, int>> getArrNumForVec (vector<string> vec) {
    vector<pair<int, int>> nums;
    for (auto str : vec) {
        int pos = (int)str.find('-');
        if (pos > 0) {
            int f = stoi(str.substr(0,pos));
            int s = stoi(str.substr(pos + 1,str.length() - 1));
            nums.push_back(make_pair(f, s));
        } else {
            int f = stoi(str);
            nums.push_back(make_pair(f, f));
        }
    }
    return nums;
}

string getResult(vector<pair<int, int>>vlanList, int remove) {
    
    sort(vlanList.begin(), vlanList.end());
    
    for (int i = 0; i < vlanList.size(); i++) {
        pair<int, int> vlan = vlanList[i];
        int from = vlan.first;
        if (from != vlan.second) {
            int to = vlan.second;
            if (remove < from || remove > to) {
                continue;
            }
            
            vlanList.erase(vlanList.begin() + i);
            if (remove == from) {
                vlanList.push_back(make_pair(remove + 1, to));
            } else if (remove == to) {
                vlanList.push_back(make_pair(from, remove - 1));
            } else {
                vlanList.push_back(make_pair(remove + 1, to));
                vlanList.push_back(make_pair(from, remove - 1));
            }
            break;
            
        } else if (from == remove) {
            vlanList.erase(vlanList.begin() + i);
            break;
        }
    }
    
    string ans;
    sort(vlanList.begin(), vlanList.end());
    for (pair<int, int> p : vlanList) {
        if (ans.length() > 0) {
            ans += ",";
        }
        if (p.first == p.second) {
            ans += to_string(p.first);
        } else {
            ans += to_string(p.first) + "-" + to_string(p.second);
        }
    }
    
    return ans;
}


int main(int argc, const char * argv[]) {
    
    string str;
    getline(cin, str);
    vector<string> arr = getArrStringForString(str);
    vector<pair<int, int>> vlanList = getArrNumForVec(arr);
    int remove;
    cin >> remove;
//    vector<string> arr = getar
    
    cout << getResult(vlanList,remove) << endl;
    
    return 0;
}
