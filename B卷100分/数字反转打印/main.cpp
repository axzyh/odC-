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


using namespace std;

// 数字反转打印
// 小华是个对数字很敏感的小朋友，他觉得数字的不同排列方式有特殊美感。

void getResult(int n) {
    int print = 1;
    for (int i = 1; i <= n; i++) {
        vector<int> printList(i);
        for (int j = 0 ; j < i; j++) {
            printList[j] = print++;
        }
        if (i % 2 == 0) { // 逆序
            reverse(printList.begin(),printList.end());
        }
        string res;
        for (int ele : printList) {
            string sb = to_string(ele);
            while (sb.length() < 4) {
                sb += "*";
            }
            if (res.length() > 0) {
                res += "    ";
            }
            res += sb;
        }
        
        string ans = res;
        for (int k = 0; k < n - i; k++) {
            ans.insert(0, "   ");
        }
        cout << ans << endl;
    }
    
}

int main(int argc, const char * argv[]) {
    
    int n;
    cin >> n;
   
    getResult(n);
    
    return 0;
}
