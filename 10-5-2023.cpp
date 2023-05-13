#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

int min_task_cost(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int min_cost = INT_MAX;
    for (int i = 0; i < n; i++) {
        int excluded_worker = arr[i];
        vector<int> remaining_workers(arr.begin(), arr.end());
        remaining_workers.erase(remaining_workers.begin() + i);
        vector<pair<int, int>> pairs;
        for (int j = 0; j < n - 2; j += 2) {
            pairs.push_back({ remaining_workers[j], remaining_workers[j+1] });
        }
        int cost = 0;
        for (auto p : pairs) {
            cost += abs(p.first - p.second);
        }
        if (cost < min_cost) {
            min_cost = cost;
        }
    }
    return min_cost;
}

int main() {
    vector<int> arr = {1, 3, 54, 712, 52, 904, 113, 12, 135, 32, 31, 56, 23, 79, 611, 123, 677, 232, 997, 101, 111, 123, 2, 7, 24, 57, 99, 45, 666, 42, 104, 129, 554, 335, 876, 35, 15, 93, 13};
    int min_cost = min_task_cost(arr);
    cout << "The minimum cost is " << min_cost << endl;
    return 0;
}
