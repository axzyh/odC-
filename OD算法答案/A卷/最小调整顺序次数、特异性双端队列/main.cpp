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

// 最小调整顺序次数、特异性双端队列
// 有一个特异性的双端队列，该队列可以从头部或尾部添加数据，但是只能从头部移出数据。
/*
5
head add 1
tail add 2
remove
head add 3
tail add 4
head add 5
remove
remove
remove
remove
*/

int getResult(vector<string> cmds) {
    int size = 0;
    bool isSorted = true;
    int count = 0;
    for (int i = 0; i < cmds.size(); i++) {
        string cmd = cmds[i];
        if ((int)cmd.find("head add") >= 0) {
            if (size > 0 && isSorted) {
                isSorted = false;
            }
            size++;
        } else if((int)cmd.find("tail add") >= 0) {
            size++;
        } else {
            if (size == 0) {
                continue;
            }
            if (!isSorted) {
                count++;
                isSorted = true;
            }
            size--;
        }
        
    }
    
    
    return count;
}



int main(int argc, const char * argv[]) {
    int n, m;
    cin >> n;
    m = 2 * n;
    vector<string> cmds(m);
//    string str;
    cin.ignore();
    for (int i = 0; i < m; i++) {
        getline(cin, cmds[i]);
    }
    
    cout << getResult(cmds) << endl;
//
    return 0;
}




