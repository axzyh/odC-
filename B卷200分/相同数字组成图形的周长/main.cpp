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



// 相同数字组成图形的周长
//有一个64×64的矩阵，每个元素的默认值为0，现在向里面填充数字，相同的数字组成一个实心图形，如下图所示是矩阵的局部（空白表示填充0）：

vector<int> sprtStringToVecInt(string str,char c) {
    vector<int> vec ;
    string temp;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == c && temp.length() > 0) {
            vec.push_back(stoi(temp));
            temp = "";
        } else {
            temp += str[i];
        }
    }
    if (temp.length() > 0) {
        vec.push_back(stoi(temp));
        temp = "";
    }
    return vec;
}


string getResult(vector<vector<int>>vecs) {

    vector<int>vec;
    
    int matrix[64][64] = {0};
    
    for (auto v : vecs) {
        int num = v[0];
        for (int i = 1; i < v.size(); i+=2) {
            int x = v[i];
            int y = v[i + 1];
            matrix[x][y] = num;// 填充数字
        }
    }
    
    int offsets[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    
    for (auto v : vecs) {
        int num = v[0];
        int p = 0;
        for (int i = 1; i < v.size(); i+=2) {
            int x = v[i];
            int y = v[i + 1];
           
            for (auto offset:offsets) {
                int offsetX = offset[0];
                int offsetY = offset[1];
                
                int newX = x + offsetX;
                int newY = y + offsetY;
                if (newX >=0 && newX < 64 && newY >= 0 && newY < 64) {
                    if (matrix[newX][newY] != num) {
                        p++;
                    }
                } else {
                    p++;
                }
            }
        }
        vec.push_back(p);
    }
  
    string ans;
    for (auto i : vec) {
        if (ans.length() > 0) {
            ans += " ";
        }
        ans += to_string(i);
    }

    return ans;
   
}

int main(int argc, const char * argv[]) {
    int a;
    vector<vector<int>> vecs;
    cin >> a;
    cin.ignore();
    for (int i = 0 ; i < a; i++) {
        
        string str;
        getline(cin, str);
        string temp;
        vector<int> b;
        for (int j = 0; j < str.length(); j++) {
            if (str[j] == ' ' && !temp.empty()) {
                b.push_back(stoi(temp));
                temp = "";
            } else {
                temp += str[j];
            }
            if (j == str.length() - 1) {
                b.push_back(stoi(temp));
                temp = "";
            }
        }
       
        vecs.push_back(b);
    }
    
    cout << getResult(vecs) << endl;
    
    return 0;
}
