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



// 分积木
// Solo和koko是两兄弟，妈妈给了他们一大堆积木，每块积木上都有自己的重量。现在他们想要将这些积木分成两堆。哥哥Solo负责分配，弟弟koko要求两个人获得的积木总重量“相等”（根据Koko的逻辑），个数可以不同，不然就会哭，但koko只会先将两个数转成二进制再进行加法，而且总会忘记进位（每个进位都忘记）。如当25（11101）加11（01011）时，koko得到的计算结果是18（10010）：

string getResult(vector<int>nums) {
    sort(nums.begin(), nums.end());
    int min = nums[0];
    int correctSum = min;
    int faultSum = min;
    
    for (int i = 1; i < nums.size(); i++) {
        correctSum += nums[i];
        faultSum ^= nums[i];
    }
    if (faultSum == 0) {
        return to_string(correctSum - min);
    } else {
        return "NO";
    }
}

int main(int argc, const char * argv[]) {
  
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
   cout << getResult(nums) << endl;
    return 0;
}
