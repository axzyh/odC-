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

// 导师请吃火锅
// 入职后，导师会请你吃饭，你选择了火锅。

vector<int> getArrForString(string s) {
    string tmp;
    vector<int> arr;
    
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (tmp.length() > 0&& c == ' ' ) {
            arr.push_back(stoi(tmp));
            tmp = "";
        }
        else {
            if (isnumber(c)) {
                tmp += c;
            }
        }
    }
    if (tmp.length() > 0) {
        arr.push_back(stoi(tmp));
    }
    return arr;
}

int offsets[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

bool isFour(int x, int y, int player, vector<vector<int>> matrix,int r, int c) {
    for (auto offset : offsets) {
        int len = 1;
        int x1 = x, y1 = y;
        while (true) {
            x1 += offset[0];
            y1 += offset[1];
            if (x1 >= 1 && x1 <= r && y1 >= 1 && y1 <= c && matrix[x1][y1] == player) {
                len++;
            } else {
                break;
            }
        }
        int x2 = x, y2 = y;
        while (true) {
            x2 -= offset[0];
            y2 -= offset[1];
            if (x2 >= 1 && x2 <= r && y2 >= 1 && y2 <= c && matrix[x2][y2] == player) {
                len++;
            } else {
                break;
            }
        }
        
        if (len == 4) {
            return true;
        }
    }
    return false;
}

int getResult(int n, int m, vector<int>suit) {
    sort(suit.begin(), suit.end());
    int count = 1;
    int pre = 0;
    for (int i = 1; i < suit.size(); i++) {
        if (suit[i] >= suit[pre] + m) {
            count++;
            pre = i;
        }
    }
    return count;
    
}

int main(int argc, const char * argv[]) {
    int n, m;
    cin >> n >> m;
   
    vector<int> suit(n);
    int l,r;
    for (int i = 0; i < n; i++) {
        cin >> r >> l;
        suit[i] = r + l;
    }
    cout << getResult(n,m,suit) << endl;
    return 0;
}
