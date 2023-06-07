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

// Excel单元格数值统计
//Excel工作表中对选定区域的数值进行统计的功能非常实用。仿照Excel的这个功能，请对给定表格中选中区域中的单元格进行求和统计，并输出统计结果。

vector<vector<string>> vec;

pair<int, int> getPos(string s1) {
//    每个单元格坐标
    int c = s1[0] - 65;
    int r = stoi(s1.substr(1,s1.length()))-1;
    pair<int, int> val = {make_pair(r, c)};
    return val;
}

int getCellVal(string s);
 
int getPosVal(pair<int, int> pos) {
  // 每个单元格的值
    int r = pos.first, c = pos.second;
    int val = getCellVal(vec[r][c]);
    vec[r][c] = to_string(val);
    return val;
}
// 双目运算

bool isPos(string v) {
    // 判断是否是单元格
    char c = v[0];
    return c <= 'Z' && c >= 'A';
}

int operate(vector<string>ops,bool isAdd) {
    //每个单元格计算
    int op1,op2;
    if (isPos(ops[0])) {// 单元格
        string temp ;
        temp+= ops[0];
        op1 = getPosVal(getPos(temp));
    } else {
        op1 = stoi(ops[0]);
    }
    
    if (isPos(ops[1])) {// 单元格
        string temp ;
        temp+= ops[1];
        op2 = getPosVal(getPos(temp));
    } else {
        op2 = stoi(ops[1]);
    }
   
    if (isAdd) {
        return op1 + op2;
    } else {
        return op1 - op2;
    }
}

 int getCellVal(string cell) {
     
     // 公式计算
    if (cell[0] == '=') { // 公式
        string fn = cell.substr(1,cell.length());
        
        if (fn.find('+') != string::npos ) { // 加法
            vector<string> c;
            int pos =(int) fn.find('+');
            c.push_back(fn.substr(0,pos));
            c.push_back(fn.substr(pos+1,fn.length()));
            return operate(c, true);
            
        } else if (fn.find('-') != string::npos) { // 减法
            vector<string> c;
            int pos =(int) fn.find('-');
            c.push_back(fn.substr(0,pos));
            c.push_back(fn.substr(pos+1,fn.length()));
            return operate(c, false);
        } else { // 坐标
            return getPosVal(getPos(fn));
        }
        
    } else { // 准确的值
     
        return stoi(cell);
    }
}


int getResult(int a,int b,string s1) {
    
    int pos = (int)s1.find(':');// 去需要计算的坐标
    string start = s1.substr(0,pos);
    string end = s1.substr(pos+1,s1.length());
 
    pair<int, int> s = getPos(start);
    pair<int, int> e = getPos(end);
    
    int r1 = s.first, c1 = s.second;
    int r2 = e.first, c2 = e.second;
    
    int ans = 0;
    for (int i =  r1; i <= r2; i++) {
        for (int j = c1; j <= c2; j++) {
            // 计算
            ans += getCellVal(vec[i][j]);
        }
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    int a, b;
    string s1;
    cin >> a >> b;
    
    vector<string>v(b);
    for (int i = 0; i < a; i++) {
        
        for (int j = 0; j < b; j++) {
            cin >> v[j];
        }
        vec.push_back(v);
    }
    cin.ignore();
    getline(cin, s1);
    cout << getResult(a,b,s1) << endl;
    
    return 0;
}
