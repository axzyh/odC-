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



// 贪吃蛇
// 贪吃蛇是一个经典游戏，蛇的身体由若干方格连接而成，身体随蛇头移动。蛇头触碰到食物时，蛇的长度会增加一格。蛇头和身体的任一方格或者游戏版图边界碰撞时，游戏结束。

// 字符串分割成字符串数组
vector<string> sprtStringToVecString(string str,char c) {
    vector<string> vec ;
    string temp;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == c) {
            vec.push_back(temp);
            temp = "";
        } else {
            temp += str[i];
        }
    }
    if (temp.length() > 0) {
        vec.push_back(temp);
        temp = "";
    }
    return vec;
}


vector<vector<string>> matrix;
int n;
int m;

int go(int i, int j, string direction,vector<vector<int>>snake) {
    int r = i;
    int c = j;
    
    if (direction == "U") {
        r--;
    } else if (direction == "D") {
        r++;
    } else if (direction == "L") {
        c--;
    } else if (direction == "R") {
        c++;
    }
    if (r < 0 || r >= n || c < 0 || c >=m) {
        return (int)snake.size();
    } else {
        if (matrix[r][c] == "E") {
            matrix[r][c] = "H";
            snake.insert(snake.begin() + 0, {r,c});
            vector<int>temp = snake.back();
            snake.pop_back();
            matrix[temp[0]][temp[1]] = "E";
        } else if (matrix[r][c] == "F") {
            snake.push_back({r,c});
            matrix[r][c] = "H";
        } else {
            return (int)snake.size();
        }
    }
    return 0;
}

int getResult(vector<string> operates) {
   
    vector<vector<int>> snake;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == "H") {
                snake.push_back({i,j});
            }
        }
    }
    
    // 蛇头移动方向，默认向左
    string direction = "L";
    
    for (auto operate:operates) {
        if (operate == "G") { // 继续direction 前进
            vector<int> pos = snake[0];
            int res = go(pos[0], pos[1], direction, snake);
            if (res > 0) {
                return res;
            } else {
                direction = operate;
            }
        }
    }
    return (int)snake.size();
}



int main(int argc, const char * argv[]) {
   
    string s;
    getline(cin, s);
    vector<string> operates = sprtStringToVecString(s, ' ');
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    
    cout << getResult(operates) << endl;
    
    return 0;
}
