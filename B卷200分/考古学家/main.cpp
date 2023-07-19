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



// 考古学家
// 有一个考古学家发现一个石碑，但是很可惜，发现时其已经断成多段，原地发现n个断口整齐的石碑碎片。为了破解石碑内容，考古学家希望有程序能帮忙计算复原后的石碑文字组合数，你能帮忙吗？


void dfs(int n, vector<string>arr, vector<bool>&visited,vector<string>&path,set<string> &sSet) {
    if (path.size() == n) {
        string res;
        for (auto i : path) {
            res += i;
        }
        
        if (sSet.count(res) != 1) {
            sSet.insert(res);
        }
        return;
    }
    for (int i = 0; i < n; i++) {
        
        if (i > 0 && arr[i] == arr[i - 1] && !visited[i - 1]) {
            continue;
        }
        
        if (!visited[i]) {
        path.push_back(arr[i]);
        visited[i] = true;
        dfs(n, arr, visited, path, sSet);
        visited[i] = false;
        path.pop_back();
        }
    }
}

void getResult(int n, vector<string>arr) {
    set<string> sSet;
    vector<bool> visited(n);
    
    vector<string> path;
    
    dfs(n, arr, visited, path, sSet);
    for (auto i :sSet) {
        cout << i << endl;
    }
}

int main(int argc, const char * argv[]) {
   
    int n;
    cin >> n;
    cin.ignore();
    string str;
    vector<string> arr(n);
    for (int i = 0; i < n; i++) {
        getline(cin, arr[i]);
    }
    
    getResult(n, arr);
    
    return 0;
}
