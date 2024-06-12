#include <vector>
#include <iostream>

std::vector<int> findDuplicates(std::vector<int>& nums) {
    std::vector<int> result;
    
    for (int i = 0; i < nums.size(); ++i) {
        int index = abs(nums[i]) - 1;
        if (nums[index] < 0) {
            result.push_back(index + 1);
        } else {
            nums[index] = -nums[index];
        }
    }
    
    return result;
}

int main() {
    std::vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    std::vector<int> duplicates = findDuplicates(nums);

    for (int num : duplicates) {
        std::cout << num << " ";
    }

    return 0;
}
