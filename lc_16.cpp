#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int ans = nums[0] + nums[1] + nums[2];
        int len = nums.size();

        for (int i = 0; i < len; i++) {
            int L = i + 1;
            int R = len - 1;

            while (L < R) {
                int sum = nums[i] + nums[L] + nums[R];
                if (abs(target - sum) < abs(target - ans))
                    ans = sum;
                if (sum > target) {
                    R--;
                }
                else if (sum < target) {
                    L++;
                }
                else return ans;
            }
        }

        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> vec {-1, 2, 1, -4};
    Solution s;
    cout << s.threeSumClosest(vec, 1) << endl;
    return 0;
}