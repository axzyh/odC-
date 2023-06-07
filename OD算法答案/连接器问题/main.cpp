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

using namespace std;

// 连接器问题
// 有一组区间[a0，b0]，[a1，b1]，…（a，b表示起点，终点），区间有可能重叠、相邻，重叠或相邻则可以合并为更大的区间；

bool compareTest19(pair<int, int>a, pair<int, int>b) {
    if (a.first <= b.first) {
        return true;
    } else {
        return false;
    }
}

static bool compare19(int a, int b) {
    if (a > b) {
        return true;
    } else {
        return false;
    }
}

int getResult(vector<pair<int, int>> ranges,vector<int> s2) {
    sort(ranges.begin(), ranges.end(), compareTest19);
    vector<pair<int, int>> vp;
    vp.push_back(ranges[0]);
    
    vector<int>vec;
    for (int i = 0; i < ranges.size(); i++) {
        pair<int, int> last = vp.back();
        int s1 = last.first;
        int e1 = last.second;
        pair<int, int> range = ranges[i];
        int s2 = range.first;
        int e2 = range.second;
        if (s2 <= e1) {
            vp.pop_back();
            vp.push_back(make_pair(s1, max(e1, e2)));
        } else {
            vec.push_back(s2 - e1);
            vp.push_back(range);
        }
    }
    
    sort(vec.begin(), vec.end(),compare19);
    sort(s2.begin(), s2.end(),compare19);
    while (s2.size() > 0 && vec.size() > 0) {
        int c = s2.back();
        s2.pop_back();
        if (c >= vec[vec.size() - 1]) {
            vec.pop_back();
        }
    }
    return (int)vec.size() + 1;
}

int main(int argc, const char * argv[]) {
    string s1,s2;
    getline(cin, s1);
    getline(cin, s2);
    vector<pair<int, int>> vp;
    vector<int> res;
    
    string temp;
    bool isAdd = false;
    int a,b;
    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] == '[') {
            isAdd = true;
        } else if (s1[i] == ']') {
            isAdd = false;
            b = stoi(temp);
            vp.push_back(make_pair(a, b));
            temp = "";
        }
        if (isAdd == true && (isnumber(s1[i])) ) {
            temp += s1[i];
        }
        if (s1[i] == ',') {
            if (temp.length() > 0) {
                a = stoi(temp);
                temp = "";
            }
        }
    }
    
    for (int i = 0; i < s2.length(); i++) {
        if (s2[i] == ',' || s2[i] == ']') {
            
            if (temp.length() > 0) {
                res.push_back(stoi(temp));
            }
            temp = "";
        } else if (isnumber(s2[i])) {
            temp += s2[i];
        }
    }
    
    cout << getResult(vp, res) <<endl;
    
    return 0;
}
