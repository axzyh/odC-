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
#include <iomanip>


using namespace std;

// 打印机队列
// 有5台打印机打印文件，每台打印机有自己的待打印队列。
/*
 7
 IN 1 1
 IN 1 2
 IN 1 3
 IN 2 1
 OUT 1
 OUT 2
 OUT 2
*/

vector<string> getArrStringForS(string str) {
    vector<string> arr;
    string temp;
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        if (c == ' ' && temp.length() > 0) {
            arr.push_back(temp);
            temp = "";
        } else {
            temp += c;
        }
    }
    if (temp.length() > 0) {
        arr.push_back(temp);
    }
    return arr;
}

//bool compare (vector<int> a, vector<int> b) {
//
//}
template <typename T>
struct cmp2 {
    bool operator()( T a, T b) {
        if(a[1] < b[1]){
            return true;
        }
        if (a[1] == b[1] && a[2] - b[2] > 0) {
            return true;
        }
        return false;
    }
    
};

void getResult(vector<vector<string>> tasks) {

    unordered_map<string, priority_queue<vector<int>,vector<vector<int>>,cmp2<vector<int>>>> print;
    
    int x = 1;
    for (int i = 0; i < tasks.size(); i++) {
        vector<string> task = tasks[i];
        string type = task[0];
        string printId = task[1];
        if (type.find("IN") != string::npos) {
            string priority = task[2];
            vector<int> arr = {x, stoi(priority),i};
            
            print[printId].push(arr);
            x++;
        } else {
            if (!print.count(printId) || print[printId].size() == 0) {
                cout << "NULL" << endl;
            } else {
                vector<int> arr = print[printId].top();
                print[printId].pop();
                if (arr.size() > 0) {
                    cout << arr[0] << endl;
                } else {
                    cout << "NULL" << endl;
                }
            }
        }
        
    }
}



int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    vector<vector<string>> tasks(n);
    string str;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        getline(cin, str);
        vector<string> tmp = getArrStringForS(str);
        tasks[i] = tmp;
    }
  
    getResult(tasks);
//
    return 0;
}




