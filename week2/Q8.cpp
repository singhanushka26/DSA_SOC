#include <iostream>
#include <string>

int maxBalancedSubstrings(std::string str) {
    int count = 0;
    int zeros = 0, ones = 0;
    
    for (char c : str) {
        if (c == '0') {
            zeros++;
        } else {
            ones++;
        }
        
        if (zeros == ones) {
            count++;
            zeros = 0;
            ones = 0;
        }
    }
    
    if (zeros != 0 || ones != 0) {
        return -1;
    }
    
    return count;
}

int main() {
    std::string str;
    std::cout << "Enter the binary string: ";
    std::cin >> str;
    
    int result = maxBalancedSubstrings(str);
    
    std::cout << "Maximum count of consecutive balanced substrings: " << result << std::endl;
    
    return 0;
}
