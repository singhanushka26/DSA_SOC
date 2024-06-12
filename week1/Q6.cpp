#include <vector>
#include <algorithm>
#include <iostream>

std::vector<std::vector<int>> findTriplets(std::vector<int>& arr, int K) {
    std::vector<std::vector<int>> result;
    int n = arr.size();
    std::sort(arr.begin(), arr.end());
    
    for (int i = 0; i < n - 2; ++i) {
        if (i > 0 && arr[i] == arr[i - 1]) continue;
        
        int target = K - arr[i];
        int left = i + 1;
        int right = n - 1;
        
        while (left < right) {
            int sum = arr[left] + arr[right];
            
            if (sum == target) {
                result.push_back({arr[i], arr[left], arr[right]});
                
                while (left < right && arr[left] == arr[left + 1]) left++;
                while (left < right && arr[right] == arr[right - 1]) right--;
                
                left++;
                right--;
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
    }
    
    return result;
}

int main() {
    std::vector<int> arr = {1, 2, -3, 4, -2, -1, 3, 2, 0};
    int K = 0;
    std::vector<std::vector<int>> triplets = findTriplets(arr, K);
    
    if (triplets.empty()) {
        std::cout << "-1" << std::endl;
    } else {
        for (const auto& triplet : triplets) {
            std::cout << "{";
            for (int num : triplet) {
                std::cout << num << " ";
            }
            std::cout << "}" << std::endl;
        }
    }
    
    return 0;
}
