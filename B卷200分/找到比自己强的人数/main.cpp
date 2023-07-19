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

// 找到比自己强的人数
// 给定数组[[2,1],[3 2]]，每组表示师徒关系，第一个元素是第二个元素的老师，数字代表排名，现在找出比自己强的徒弟。

vector<pair<int, int>> getArrForString(string s) {
    string tmp;
    vector<pair<int, int>> arr;
    int left = 0, right = 0;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (tmp.length() > 0 &&(c == ',' || c == ']')) {
            if (left > 0) {
                right = stoi(tmp);
                tmp = "";
                arr.push_back(make_pair(left, right));
                left = 0;
                right = 0;
            } else {
                left = stoi(tmp);
                tmp ="";
            }
        } else {
            if (isnumber(c)) {
                tmp += c;
            }
        }
    }
    return arr;
}

/// 取出比自己高的
/// @param f 当前的师傅，初始时为源头祖师
/// @param src 源头祖师
/// @param highC 比源头祖师排名高的徒弟的排名集合
/// @param fa fa对象的属性时师傅排名，属性值时一个数组，里面元素是直接徒弟的排名
/// @return 比源头祖师排名高的徒弟个数，即highC.size()
int getHighc(int f, int src, set<int> &highC, map<int, vector<int>> fa) {
    if (f == 1) {
        return 0;
    }
    
    for (int c :fa[f]) {
        bool flag = true;
        if (c < src) {
            if (highC.count(c) != 1) {
                highC.insert(c);
            } else {
                flag = false;
            }
        } else if (c == src) {
            return 0;
        }
        if (flag) {
            getHighc(c, src, highC, fa);
        }
    }
    return (int)highC.size();
    
}

string getResult(vector<pair<int, int>> relations) {
    map<int, vector<int>> fa;
    for (pair<int, int> relation : relations) {
        int f = relation.first;
        int c = relation.second;
        if (!fa.count(c)) {
            fa[c] = vector<int>();
        }
        fa[f].push_back(c);
        
    }
    vector<pair<int, int>>ans;
   
    for (auto f: fa) {
        set<int> HighC = set<int>();
        ans.push_back(make_pair(f.first, getHighc(f.first, f.first, HighC, fa)));
    }
    sort(ans.begin(), ans.end());
    string str = "[";
    for (pair<int, int> an: ans) {
        if (str.length() > 1) {
            str += ",";
        }
        str += to_string(an.second);
    }
    str += "]";
    
    return str;
    
}

int main(int argc, const char * argv[]) {
    string str;
    getline(cin, str);
    vector<pair<int, int>> relations = getArrForString(str);
    
    cout << getResult(relations) << endl;
    return 0;
}
