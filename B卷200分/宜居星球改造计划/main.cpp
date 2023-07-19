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



// 宜居星球改造计划
// 2XXX年，人类通过对火星的大气进行宜居改造分析，使得火星已在理论上具备人类宜居的条件；

bool canCombie(set<char>set1,set<char>set2) {
    
    for (char c = 'a'; c <= 'z'; c++) {
        char uc = c - 32;
        if ((set1.count(c) || set1.count(uc)) && ((set2.count(c) || set2.count(uc)))) {
            return true;
        }
    }
    return false;
}

int getResult(vector<vector<string>>vec) {
    int need = 0;
    int row = (int)vec.size();
    int col = vec[0].size();
    queue<pair<int, int>> queue;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (vec[i][j] == "YES") {
                queue.push(make_pair(i, j));
            } else if(vec[i][j] == "NO") {
                need++;
            }
        }
    }
    if (queue.size() == 0) {
        return -1;
    }
    if (queue.size() == col * row) {
        return 0;
    }
    int day = 0;
    int offsets[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
    while (queue.size() > 0 && need != 0) {
       int size = (int)queue.size();
        for (int i = 0; i < size; i++) {
            pair<int, int>pos = queue.front();
            queue.pop();
            int x = pos.first;
            int y = pos.second;
            for (auto offset:offsets) {
                int newX = x + offset[0];
                int newY = y + offset[1];
                if (newX >= 0 && newX < row && newY >= 0 && newY < col && vec[newX][newY] == "NO") {
                    need--;
                    vec[newX][newY] = "YES";
                    queue.push(make_pair(newX, newY));
                }
            }
        }
        
        day++;
    }
    if (need != 0) {
        return -1;
    }
    
    return day;
}

int main(int argc, const char * argv[]) {
 
    string str;
    vector<vector<string>> vecs;
    string temp = "";
    while (getline(cin, str)) {
    
        if (str.empty()) { //  空行截止
            break;
        }
        temp = "";
        vector<string>vec;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] != ' ') {
                temp += str[i];
            }
            if ((str[i] == ' ' && !temp.empty()) || i == str.length() - 1) {
                vec.push_back(temp);
                temp = "";
            }
        }
        vecs.push_back(vec);
    }
    
    cout << getResult(vecs) << endl;
    
    return 0;
}
