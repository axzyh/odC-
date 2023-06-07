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



// 代码编辑器
// 某公司为了更高效的编写代码，邀请你开发一款代码编辑器程序。

string getResult(vector<vector<string>> sVec,string s) {
    int curIdx = 0;
    for (auto command:sVec) {
        if (command[0] == "FORWARD") {
            curIdx += stoi(command[1]);
            curIdx = min(curIdx, (int)s.length());
        } else if (command[0] == "BACKWARD") {
            curIdx -= stoi(command[1]);
            curIdx = max(curIdx, 0);
            
        } else if (command[0] == "SEARCH-FORWARD") {
            string str = s.substr(0,curIdx);
            int pos = (int)str.find(command[1]);
            if (pos != -1) {
                curIdx = pos;
            }
            
        } else if (command[0] == "SEARCH-BACKWARD") {
            string str = s.substr(curIdx,s.length());
            int pos = (int)str.find(command[1]);
            if (pos != -1) {
                curIdx = pos;
            }
            
        } else if (command[0] == "INSERT") {
            s.insert(curIdx, command[1]);
            curIdx += int(command[1].length());
            
        }
        else if (command[0] == "REPLACE") {
            s.replace(curIdx, curIdx + command[1].length(), command[1]);
            
        } else if (command[0] == "DELETE") {
            s.erase(curIdx, curIdx + command[1].length());
        }
    }
    return s;
}

int main(int argc, const char * argv[]) {
    int k;
    string s;
    cin >> k;
    cin.ignore();
    getline(cin, s);
    vector<vector<string>> sVec(k,vector<string>(2));
    
    for (int i = 0; i < k; i++) {
        cin >> sVec[i][0];
        cin >> sVec[i][1];
    }
    cout << getResult(sVec, s) << endl;
    
    return 0;
}
