#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        int len = nums.size();

        for (int i = 0; i < len; i++) {
            if (nums[i] > 0)
                return res;
            if(i > 0 && nums[i] == nums[i-1])
                continue;

            int L = i + 1;
            int R = len - 1;

            while (L < R) {
                if (nums[i] + nums[L] + nums[R] == 0) {
                    vector<int> tmp {nums[i], nums[L], nums[R]};
                    res.push_back(tmp);
                    while (L < R && nums[L] == nums[L+1]) L++;
                    while (L < R && nums[R] == nums[R-1]) R--;
                    L++;
                    R--;
                } else if (nums[i] + nums[L] + nums[R] > 0)
                    R--;
                else
                    L++;
            }
        }

        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> vec {-1, 0, 1, 2, -1, -4};
    Solution s;
    s.threeSum(vec);
    return 0;
}