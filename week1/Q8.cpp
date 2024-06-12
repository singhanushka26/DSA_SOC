#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int maxHistArea(const vector<int>& heights) {
    stack<int> s;
    int max_area = 0;
    int index = 0;

    while (index < heights.size()) {
        if (s.empty() || heights[s.top()] <= heights[index]) {
            s.push(index++);
        } else {
            int top = s.top();
            s.pop();
            int area = heights[top] * (s.empty() ? index : index - s.top() - 1);
            max_area = max(max_area, area);
        }
    }

    while (!s.empty()) {
        int top = s.top();
        s.pop();
        int area = heights[top] * (s.empty() ? index : index - s.top() - 1);
        max_area = max(max_area, area);
    }

    return max_area;
}

int maxRectangle(vector<vector<int>>& matrix) {
    if (matrix.empty()) return 0;

    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> heights(m, 0);
    int max_area = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            heights[j] = (matrix[i][j] == 0) ? 0 : heights[j] + 1;
        }
        max_area = max(max_area, maxHistArea(heights));
    }

    return max_area;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 0, 1, 0, 0},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 0, 0, 1, 0}
    };

    cout << "Maximum rectangle area: " << maxRectangle(matrix) << endl;

    return 0;
}
