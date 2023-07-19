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



// 告警抑制
//告警抑制，是指高优先级告警抑制低优先级告警的规则。高优先级告警产生后，低优先级告警不再产生。请根据原始告警列表和告警抑制关系，给出实际产生的告警列表。
bool comPareSet(set<string> set1, set<string>set2) {
    if (!set1.size() || !set2.size()) {
        return true;
    }
    
    for (auto i : set1) {
        if (set2.count(i)) {
            return false;
        }
    }
    return true;
}


string getResult(vector<string>vec,map<string, set<string>>map1) {
    set<string> ss(vec.begin(),vec.end());
    string ans ;
    for (auto i : vec) {
        if (!map1.count(i)|| (comPareSet(map1[i],ss))) {
            if (ans.length() > 0) {
                ans += " ";
            }
            
            ans += i;
        }
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    int a;
    cin >> a;
    string target;
    cin.ignore();
    map<string, set<string>> map1;
    for (int i = 0; i < a; i++) {
        string str;
        string tem1;
        for (int j = 0; j < 2; j++) {
            cin >> str;
            set<string> temp;
            if (j == 0) {
                tem1 = str;
            } else {
                if (map1.count(str)) {
                    temp = map1[str];
                }
                temp.insert(tem1);
                map1[str] = temp;
            }
           
        }
    }
    
    cin.ignore();
    getline(cin, target);
    string temp2;
    vector<string>b;
    for (int j = 0; j < target.length(); j++) {
        if (target[j] == ' ' && !temp2.empty()) {
            b.push_back(temp2);
            temp2 = "";
        } else {
            temp2 += target[j];
        }
        if (j == target.length() - 1) {
            b.push_back(temp2);
            temp2 = "";
        }
    }
    
    cout << getResult(b,map1) << endl;
    
    return 0;
}
