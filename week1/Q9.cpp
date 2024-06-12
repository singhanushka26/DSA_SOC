#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPossible(const vector<int>& stalls, int k, int minDist) {
    int cows = 1;
    int prevPos = stalls[0];

    for (int i = 1; i < stalls.size(); ++i) {
        if (stalls[i] - prevPos >= minDist) {
            cows++;
            prevPos = stalls[i];
        }
        if (cows == k) return true;
    }
    return false;
}

int maxMinDistance(vector<int>& stalls, int k) {
    sort(stalls.begin(), stalls.end());

    int minDist = 1;
    int maxDist = stalls.back() - stalls[0];
    int result = -1;

    while (minDist <= maxDist) {
        int mid = minDist + (maxDist - minDist) / 2;
        if (isPossible(stalls, k, mid)) {
            result = mid;
            minDist = mid + 1;
        } else {
            maxDist = mid - 1;
        }
    }

    return result;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> stalls(n);
    for (int i = 0; i < n; ++i) {
        cin >> stalls[i];
    }

    cout << "Maximum minimum distance: " << maxMinDistance(stalls, k) << endl;

    return 0;
}
