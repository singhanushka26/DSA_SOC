#include <iostream>
#include <vector>

int compress(std::vector<char>& chars) {
    int n = chars.size();
    int writeIndex = 0;
    
    for (int readIndex = 0; readIndex < n; ) {
        char currentChar = chars[readIndex];
        int count = 0;
       
        while (readIndex < n && chars[readIndex] == currentChar) {
            readIndex++;
            count++;
        }
        
        chars[writeIndex++] = currentChar;
        
        if (count > 1) {
            std::string countStr = std::to_string(count);
            for (char c : countStr) {
                chars[writeIndex++] = c;
            }
        }
    }
    
    return writeIndex;
}

int main() {
    std::vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    
    std::cout << "Original array: ";
    for (char c : chars) {
        std::cout << c << " ";
    }
    std::cout << std::endl;
    
    int compressedLength = compress(chars);
    
    std::cout << "Compressed array: ";
    for (int i = 0; i < compressedLength; ++i) {
        std::cout << chars[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
