#include <iostream>
#include <vector>
#include <algorithm> 

void reverseAfterPosition(std::vector<int>& arr, int M) {
    if (M >= arr.size() - 1) {
        return;
    }
    std::reverse(arr.begin() + M + 1, arr.end());
}

int main() {
    std::vector<int> ARR = {1, 2, 3, 4, 5, 6};
    int M = 3;
    reverseAfterPosition(ARR, M);
    
    for (int i = 0; i < ARR.size(); i++) {
        std::cout << ARR[i] << " ";
    }
    return 0;
}
