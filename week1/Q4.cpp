#include <vector>
#include <iostream>

void sortColors(std::vector<int>& arr) {
    int low = 0;
    int mid = 0;
    int high = arr.size() - 1;

    while (mid <= high) {
        switch (arr[mid]) {
            case 0:
                std::swap(arr[low], arr[mid]);
                low++;
                mid++;
                break;
            case 1:
                mid++;
                break;
            case 2:
                std::swap(arr[mid], arr[high]);
                high--;
                break;
        }
    }
}

int main() {
    std::vector<int> arr = {2, 0, 2, 1, 1, 0};
    sortColors(arr);

    for (int num : arr) {
        std::cout << num << " ";
    }

    return 0;
}
