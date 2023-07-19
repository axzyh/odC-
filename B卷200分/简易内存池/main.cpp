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



// 简易内存池
// 请实现一个简易内存池,根据请求命令完成内存分配和释放。

bool hansIntersection(vector<int>&range1,vector<int>range2) {
    int s1 = range1[0];
    int e1 = range1[1];
    int s2 = range2[0];
    int e2 = range2[1];
    if (s1 == s2) {
        return true;
    } else if (s1 < s2) {
        return e1 >=s2;
    } else {
        return e2 >= s1;
    }
}

void getResult(int n,vector<vector<string>>cmds) {
    vector<vector<int>> used;
    used.push_back({100,101});
    for (vector<string> cmd : cmds) {
        string key = cmd[0];
        string val = cmd[1];
        
        if (key == "REQUEST") {
            int size = stoi(val);
            int start = 0;
            bool flag = true;
            for (int i = 0; i < used.size(); i++) {
                int end = start + size - 1;
                vector<int> range = {start,end};
                if (!hansIntersection(used[i], range)) {
                    used.push_back(range);
                    sort(used.begin(), used.end());
                    flag = false;
                    cout << start << endl;
                    break;
                } else {
                    start = used[i][1]+1;
                }
            }
            if (flag) {
                cout << "error" << endl;
            }
        } else {
            int addr = stoi(val);
            bool flag = true;
            for (int i = 0; i < used.size(); i++) {
                if (used[i][0] == addr) {
                    used.erase(used.begin() + i);
                    flag = false;
                    break;
                }
            }
            if (flag) {
                cout << "error" << endl;
            }
        }
        
    }
   

}



int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    cin.ignore();
    vector<vector<string>> cmds;
//    for (int i = 0; i < n; i++) {
//        cmds[i]
//    }
    vector<string> vec;
    vec.push_back("REQUEST");
    vec.push_back("10");
    vector<string> vec1;
    vec1.push_back("REQUEST");
    vec1.push_back("20");
    vector<string> vec2;
    vec2.push_back(" RELEASE");
    vec2.push_back("0");
    vector<string> vec3;
    vec3.push_back("REQUEST");
    vec3.push_back("20");
    vector<string> vec4;
    vec4.push_back("REQUEST");
    vec4.push_back("10");
    cmds.push_back(vec);
    cmds.push_back(vec1);
    cmds.push_back(vec2);
    cmds.push_back(vec3);
    cmds.push_back(vec4);
    
    getResult(n, cmds);
    
    return 0;
}
