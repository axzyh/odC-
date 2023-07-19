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
#include <unordered_set>
#include <regex>

using namespace std;



// 拔河比赛
// 公司最近准备进行拔河比赛，需要在全部员工中进行挑选。

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.first > b.first) {
        return true;
    } else if (a.first == b.first) {
        if (a.second > b.second) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

void getResult(vector<pair<int, int>> employees) {
    sort(employees.begin(), employees.end(), compare);
    for (int i = 0; i < 10; i++) {
        cout << employees[i].first << " " << employees[i].second << endl;
    }
    
   
    
}



int main(int argc, const char * argv[]) {
  
    string str;
    vector<pair<int, int>> employees;
    while (true) {
        getline(cin, str);
        if (str.length() == 0) {
            break;
        }
        int pos = str.find(" ");
        string s1 = str.substr(0, pos);
        string s2 = str.substr(pos + 1, str.length());
        employees.push_back(make_pair(stoi(s1), stoi(s2)));
        
    }
   
   getResult(employees);
   
    
    return 0;
}
