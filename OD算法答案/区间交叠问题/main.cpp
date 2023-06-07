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

// 区间交叠问题
// 给定坐标轴上的一组线段，线段的起点和终点均为整数并且长度不小于1，请你从中找到最少数量的线段，这些线段可以覆盖柱所有线段。

bool compare(pair<int, int>a, pair<int, int>b) {
    if (a.first < b.first) {
        return true;
    }
    return false;
}

int getResult(vector<pair<int, int>>vec) {
    sort(vec.begin(), vec.end(), compare);
    stack<pair<int, int>> st;
    st.push(vec[0]);
    
    for (int i = 1; i < vec.size(); i++) {
        pair<int, int> range = vec[i];
        while (true) {
            if (st.size() == 0) {
                st.push(range);
                break;
            }
            pair<int, int> top = st.top();
            int s0 = top.first;
            int e0 = top.second;
            int s1 = range.first;
            int e1 = range.second;
            if (s1 <= s0) {
                if (e1 <= s0) {
                    break;
                } else if(e1 < e0) {
                    break;
                } else {
                    st.pop();
                }
            }else if (s1 < e0) {
                if (e1 <= e0) {
                    break;
                } else {
                    st.push(make_pair(e0, e1));
                    break;
                }
            } else {
                st.push(range);
                break;
            }
        }
    }
    
    return (int)st.size();
    
}


int main(int argc, const char * argv[]) {
    int n;
    
    cin >> n;
    vector<pair<int, int>> vec(n);
    string str;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        getline(cin, str);
        int pos = (int)str.find(',');
        vec[i].first = stoi(str.substr(0,pos));
        vec[i].second = stoi(str.substr(pos+1,str.length()));
       
    }
  cout <<  getResult(vec) << endl;
    
    return 0;
}
