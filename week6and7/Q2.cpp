#include <iostream>
#include <vector>
#include <algorithm>

int lengthOfLIS(const std::vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }

    std::vector<int> dp(nums.size(), 1);

    for (size_t i = 1; i < nums.size(); ++i) {
        for (size_t j = 0; j < i; ++j) {
            if (nums[j] < nums[i]) {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
    }

    return *std::max_element(dp.begin(), dp.end());
}

int main() {
    std::vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    std::cout << "The length of the longest increasing subsequence is " << lengthOfLIS(nums) << std::endl;

    return 0;
}
