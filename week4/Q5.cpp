#include <iostream>
#include <stack>
#include <unordered_map>

bool isValid(const std::string& s) {
    std::stack<char> stk;
    std::unordered_map<char, char> matchingBracket = {
        {')', '('},
        {'}', '{'},
        {']', '['}
    };

    for (char ch : s) {
        if (ch == '(' || ch == '{' || ch == '[') {
            stk.push(ch);
        } else {
            if (stk.empty() || stk.top() != matchingBracket[ch]) {
                return false;
            }
            stk.pop();
        }
    }

    return stk.empty();
}

int main() {
    std::string s = "{[()]}";
    
    if (isValid(s)) {
        std::cout << "The string is valid." << std::endl;
    } else {
        std::cout << "The string is not valid." << std::endl;
    }

    return 0;
}
