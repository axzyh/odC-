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

// 比赛
// 一个有N个选手参加比赛，选手编号为1~N（3<=N<=100），有M（3<=M<=10）个评委对选手进行打分。

vector<int> getArrStrForString(string str) {
    vector<int> vec;
    string tmp;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ','&& tmp.length() > 0) {
            vec.push_back(stoi(tmp));
            tmp = "";
        } else {
            tmp += str[i];
        }
    }
    if (tmp.length() > 0) {
        vec.push_back(stoi(tmp));
    }
    return vec;
}

bool compare(int a, int b) {
    if (a > b) {
        return true;
    } else {
        return false;
    }
}

bool compare2(pair<int, pair<int, vector<int>>> a, pair<int, pair<int, vector<int>>> b) {
    
    pair<int, vector<int>> c = a.second;
    pair<int, vector<int>> d = b.second;
    if (c.first > d.first) {
        return true;
    }
    
    if (c.first == d.first) {
        for (int i = 0; i < c.second.size(); i++) {
            if (c.second[i] > d.second[i]) {
                return true;
            } else if (c.second[i] == d.second[i]) {
                continue;
            } else {
                return false;
            }
        }
    }
    
    return false;
    
    
//    if (a.first > b.first) {
//        return true;
//    } else if (a.first == b.first) {
////        for (int i = 0; i < a.second.size(); i++) {
////            if (a.second[i] > b.second[i]) {
////                return true;
////            } else if (a.second[i] == b.second[i]) {
////                continue;
////            } else {
////                return false;
////            }
////        }
//        return false;
//    } else {
//        return false;
//    }
    return false;
}



string getResult(int m, int n, vector<vector<int>> scores) {
    
    if (m < 3 || m > 10 || n < 3 || n > 100) {
        return "-1";
    }
    
    unordered_map<int, pair<int, vector<int>>> players;
    
    for (int j = 0; j < n; j++) {
        vector<int> player(m);
        int sum = 0;
        for (int i = 0; i < m; i++) {
            if (scores[i][j] > 10 || scores[i][j] < 1) {
                return "-1";
            }
            sum += scores[i][j];
            player[i] = scores[i][j];
        }
        sort(player.begin(), player.end(), compare);
        players[j + 1] = make_pair(sum, player);
        
    }
    
    vector<pair<int, pair<int, vector<int>>>> vec(players.begin(),players.end());
    sort(vec.begin(), vec.end(), compare2);
    
    
    
    string res;
    
    int count = 0;
    for (auto pa : vec) {
        if (res.length() > 0) {
            res += ",";
        }
        
        res += to_string(pa.first);
        if (count >= 2) {
            break;
        }
        count++;
        
    }

    return res;
}

int main(int argc, const char * argv[]) {
   
    string str;
    getline(cin, str);
    
    int pos = (int)str.find(',');
    int m = stoi(str.substr(0,pos));
    int n = stoi(str.substr(pos + 1, str.length()));
    
    
    string s;
    
    vector<vector<int>> scores(m);
    
    for (int i = 0; i < m; i++) {
        getline(cin, s);
        scores[i] = getArrStrForString(s);
    }
    
    cout << getResult(m,n,scores) << endl;
    
    return 0;
}
