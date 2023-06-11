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

// 竖直四子棋
// 竖直四子棋的棋盘是竖立起来的，双方轮流选择棋盘的一列下子，棋子因重力落到棋盘底部或者其他棋子之上，当一列的棋子放满时，无法再在这列上下子。

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

string getResult(int n, int m, vector<int>colors) {
    int r = m;
    int c = n;
    vector<vector<int>> matrix(r+1,vector<int>(c + 1));
    
    for (int i = 0; i < colors.size(); i++) {
        if (colors[i] < 1 || colors[i] > c) {
            return to_string(i + 1) + ",error";
        }
        int player = i % 2 == 0 ? 1: 2;
        int x = m;
        int y = colors[i];
        while (matrix[x][y] > 0) {
            x--;
            if (x < 1) {
                return to_string(i+ 1) + ",error";
            }
        }
        matrix[x][y] = player;
        
        if (i >= 6 && isFour(x, y, player, matrix, r, c)) {
            return to_string(i + 1)  + "," + (player == 1 ? "red" : "blue");
        }
    }
   
    return "0,draw";
    
}

int main(int argc, const char * argv[]) {
    int n, m;
    cin >> n >> m;
    string str;
    cin.ignore();
    getline(cin, str);
    vector<int> colors = getArrForString(str);
    
    cout << getResult(n,m,colors) << endl;
    return 0;
}
