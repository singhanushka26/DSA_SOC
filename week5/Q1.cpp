#include <iostream>
#include <vector>
#include <queue>

int findKthLargest(const std::vector<int>& nums, int k) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    for (int num : nums) {
        minHeap.push(num);
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }

    return minHeap.top();
}

int main() {
    std::vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;

    std::cout << "The " << k << "th largest element is " << findKthLargest(nums, k) << std::endl;

    return 0;
}
