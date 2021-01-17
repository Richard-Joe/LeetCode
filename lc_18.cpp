#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        int len = nums.size();

        for (int i = 0; i < len-3; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;

            for (int j = i+1; j < len-2; j++) {
                if(j > i+1 && nums[j] == nums[j-1]) continue;
                int L = j + 1;
                int R = len - 1;

                while (L < R) {
                    int sum = nums[i] + nums[j] + nums[L] + nums[R];
                    if (sum == target) {
                        vector<int> tmp {nums[i], nums[j], nums[L], nums[R]};
                        res.push_back(tmp);
                        cout << nums[i] << ", " << nums[j] << ", " << nums[L] << ", " << nums[R] << endl;
                        while (L < R && nums[L] == nums[++L]);
                        while (L < R && nums[R] == nums[--R]);
                    } else if (sum > target)
                        while (L < R && nums[R] == nums[--R]);
                    else
                        while (L < R && nums[L] == nums[++L]);
                }
            }
        }

        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> vec {0,4,-5,2,-2,4,2,-1,4};
    Solution s;
    s.fourSum(vec, 12);
    return 0;
}