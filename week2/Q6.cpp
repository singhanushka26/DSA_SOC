#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

void backtrack(std::string& s, int start, std::set<std::string>& uniquePermutations) {
    if (start == s.length() - 1) {
        uniquePermutations.insert(s);
        return;
    }
    
    for (int i = start; i < s.length(); ++i) {
        std::swap(s[start], s[i]);
        backtrack(s, start + 1, uniquePermutations);
        std::swap(s[start], s[i]);
    }
}

void printUniquePermutations(std::string s) {
    std::sort(s.begin(), s.end()); 
    std::set<std::string> uniquePermutations;
    backtrack(s, 0, uniquePermutations);
    
    for (const auto& permutation : uniquePermutations) {
        std::cout << permutation << std::endl;
    }
}

int main() {
    std::string S;
    std::cout << "Enter the string: ";
    std::cin >> S;
    
    std::cout << "Unique permutations of " << S << " are:\n";
    printUniquePermutations(S);
    
    return 0;
}
