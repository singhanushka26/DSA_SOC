#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPossible(const vector<int>& boards, int painters, long long time) {
    int currentPainterTime = 0;
    int totalPainters = 1;

    for (int board : boards) {
        currentPainterTime += board;
        if (currentPainterTime > time) {
            totalPainters++;
            currentPainterTime = board;
        }
        if (totalPainters > painters) return false;
    }

    return true;
}

long long minTimeToPaintBoards(const vector<int>& boards, int painters) {
    long long low = *max_element(boards.begin(), boards.end());
    long long high = accumulate(boards.begin(), boards.end(), 0LL);
    long long result = -1;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (isPossible(boards, painters, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return result;
}

int main() {
    int n, painters;
    cin >> n >> painters;
    vector<int> boards(n);
    for (int i = 0; i < n; ++i) {
        cin >> boards[i];
    }

    cout << "Minimum time to paint all boards: " << minTimeToPaintBoards(boards, painters) << endl;

    return 0;
}
