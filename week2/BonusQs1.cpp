#include <iostream>

void towerOfHanoi(int n, int source, int destination, int auxiliary, int& moves) {
    if (n == 1) {
        std::cout << "Move disk 1 from rod " << source << " to rod " << destination << std::endl;
        moves++;
        return;
    }
    towerOfHanoi(n - 1, source, auxiliary, destination, moves);
    std::cout << "Move disk " << n << " from rod " << source << " to rod " << destination << std::endl;
    moves++;
    towerOfHanoi(n - 1, auxiliary, destination, source, moves);
}

int main() {
    int n;
    std::cout << "Enter the number of disks: ";
    std::cin >> n;

    int moves = 0;
    towerOfHanoi(n, 1, 3, 2, moves);
    
    std::cout << "Total moves: " << moves << std::endl;

    return 0;
}
