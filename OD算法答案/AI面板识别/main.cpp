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



// AI面板识别
// AI识别到面板上有N（1 ≤ N ≤ 100）个指示灯，灯大小一样，任意两个之间无重叠。
struct Light {
    int id;
    int x;
    int y;
    int r;
    
    Light(int id,int x,int y, int r): id(id),x(x),y(y),r(r){}
};
bool sortCompare(Light a, Light b) {
    
    if (a.y < b.y) {
        return true;
    }
    
    return false;
}
bool sortXCompare(Light a, Light b) {
    
    if (a.x <= b.x) {
        return false;
    }
    
    return true;
}
// 取数组中id
string getStringForVec(vector<Light> a) {
    string str;
    for (int i = 0; i < a.size(); i++) {
        if (str.length() > 0) {
            str += " ";
        }
        str += to_string(a[i].id);
    }
    return str;
}

string getResult(vector<Light>vec) {
   
    sort(vec.begin(), vec.end(), sortCompare);
    string ans;
    
    vector<Light> sameRowLights;
    Light base = vec[0];
    sameRowLights.push_back(base);
    
    for (int i = 1; i < vec.size(); i++) {
        Light light = vec[i];
        if (light.y - base.y <= base.r) {
            sameRowLights.push_back(light);
        } else {
            sort(sameRowLights.begin(), sameRowLights.end(), sortXCompare);
            if (ans.length() > 0) {
                ans += " ";
            }
            ans += getStringForVec(sameRowLights);
            sameRowLights = vector<Light>();
            base = light;
            sameRowLights.push_back(base);
        }
    }
    
    if (sameRowLights.size() > 0) {
        sort(sameRowLights.begin(), sameRowLights.end(), sortXCompare);
        if (ans.length() > 0) {
            ans += " ";
        }
        ans += getStringForVec(sameRowLights);
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    vector<Light> vec;
    for (int i = 0; i < n; i++) {
        int id,x1,y1,x2,y2;
        cin >> id >> x1 >> y1 >> x2 >> y2;
        vec.push_back(Light(id,(x1 + y1)/2,(x2 + y2)/2,(x2 - x1)/2));
    }
    cout << getResult(vec) << endl;
    
    return 0;
}
