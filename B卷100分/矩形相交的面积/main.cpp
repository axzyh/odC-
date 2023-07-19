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

// 矩形相交的面积
// 给出3组点坐标(x, y, w, h)，-1000<x,y<1000，w,h为正整数。


int getMin(int n1, int n2, int n3) {
    int min1 = min(n1, n2);
    min1 = min(min1, n3);
    return min1;
}

int getMax(int n1, int n2, int n3) {
    int max1 = max(n1, n2);
    max1 = max(max1, n3);
    return max1;
}

int main(int argc, const char * argv[]) {
    
    int x1,y1,w1,h1,x2,y2,w2,h2,x3,y3,w3,h3;
    cin >> x1 >> y1 >> w1 >> h1 >> x2 >> y2 >> w2 >> h2 >> x3 >> y3 >> w3 >> h3;
    
    int wid = getMin(x1 + w1, x2 + w2, x3 + w3) - getMax(x1, x2, x3);
    if (wid <= 0) {
        cout << 0 << endl;
    }
    
    int hei = getMin(y1, y2, y3) - getMax(y1 - h1, y2 - h2, y3 - h3);
    if (hei <= 0) {
        cout << 0 << endl;
    }
    
    cout << wid * hei << endl;
    
    return 0;
}
