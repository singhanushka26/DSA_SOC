#include <iostream>

double power(double x, int n) {
    if (n == 0) {
        return 1.0;
    }
    
    double halfPower = power(x, n / 2);
    
    if (n % 2 == 0) {
        return halfPower * halfPower;
    } else {
        if (n > 0) {
            return x * halfPower * halfPower;
        } else {
            return (halfPower * halfPower) / x;
        }
    }
}

int main() {
    double x;
    int n;
    
    std::cout << "Enter the value of x: ";
    std::cin >> x;
    std::cout << "Enter the value of n: ";
    std::cin >> n;
    
    double result = power(x, n);
    
    std::cout << "Result: " << result << std::endl;
    
    return 0;
}
