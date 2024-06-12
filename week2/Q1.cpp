#include <iostream>
#include <cctype>

bool isPalindrome(std::string s) {
   
    for (char &c : s) {
        if (std::isupper(c)) {
            c = std::tolower(c);
        }
    }
    
    s.erase(std::remove_if(s.begin(), s.end(), [](char c) {
        return !std::isalnum(c);
    }), s.end());
    
    int i = 0, j = s.length() - 1;
    while (i < j) {
        if (s[i] != s[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    if (isPalindrome(input)) {
        std::cout << "The string is a palindrome.\n";
    } else {
        std::cout << "The string is not a palindrome.\n";
    }

    return 0;
}
