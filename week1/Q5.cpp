#include <vector>
#include <iostream>
#include <algorithm>

int maxProfit(const std::vector<int>& prices) {
    if (prices.empty()) return 0;

    int min_price = INT_MAX;
    int max_profit = 0;

    for (int price : prices) {
        if (price < min_price) {
            min_price = price;
        }

        int potential_profit = price - min_price;

        if (potential_profit > max_profit) {
            max_profit = potential_profit;
        }
    }

    return max_profit;
}

int main() {
    std::vector<int> prices = {7, 1, 5, 3, 6, 4};
    std::cout << "Max Profit: " << maxProfit(prices) << std::endl;
    return 0;
}
