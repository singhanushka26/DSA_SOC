#include <iostream>
#include <vector>
#include <algorithm>

int maxProduct(const std::vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }

    int maxProd = nums[0];
    int minProd = nums[0];
    int result = nums[0];

    for (size_t i = 1; i < nums.size(); ++i) {
        if (nums[i] < 0) {
            std::swap(maxProd, minProd);
        }

        maxProd = std::max(nums[i], maxProd * nums[i]);
        minProd = std::min(nums[i], minProd * nums[i]);

        result = std::max(result, maxProd);
    }

    return result;
}

int main() {
    std::vector<int> nums = {2, 3, -2, 4};

    std::cout << "The maximum product of a subarray is " << maxProduct(nums) << std::endl;

    return 0;
}
