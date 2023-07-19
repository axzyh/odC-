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

// 出错的或电路
// 某生产门电路的厂商发现某一批次的或门电路不稳定，具体现象为计算两个二进制数的或操作时，第一个二进制数中某两个比特位会出现交换，交换的比特位置是随机的，但只交换这两个位，其他位不变。

int getResult(int n,string bin1, string bin2) {
    
    int x = 0;
    int y = 0;
    int a = 0;
    int b = 0;
    
    
    for (int i = 0; i < n; i++) {
        if (bin1[i] == '0') {
            b++;
            if (bin2[i] == '0') {
                x++;
            }
        } else {
            a++;
            if (bin2[i] == '0') {
                y++;
            }
        }
    }
    
    
      return x * a + y * b - x * y;
    
}

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    cin.ignore();
    string bin1, bin2;
    getline(cin, bin1);
    getline(cin, bin2);
    
    cout << getResult(n, bin1,bin2) << endl;
    return 0;
}
