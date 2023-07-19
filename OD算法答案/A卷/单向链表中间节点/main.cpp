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

// 单向链表中间节点
// 求单向链表中间的节点值，如果奇数个节点取中间，偶数个取偏右边的那个值。

string getResult(string head, unordered_map<string, vector<string>> nodes) {
    
    vector<string> link;
    vector<string> node= nodes[head];
    while (node.size() > 0) {
        string val = node[0];
        string next = node[1];
        link.push_back(val);
        node = nodes[next];
    }
    int len = (int)link.size();
    int mid = len / 2;
  
    return link[mid];
}



int main(int argc, const char * argv[]) {
    string head;
    int n;
    cin >> head >> n;
    unordered_map<string, vector<string>> nodes;
    string addr, val, nextAddr;
    for (int i = 0; i < n; i++) {
        cin >> addr >> val >> nextAddr;
        nodes[addr] = {val, nextAddr};
    }

    cout << getResult(head,nodes) << endl;
//
    return 0;
}




