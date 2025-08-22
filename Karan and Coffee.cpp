#include <bits/stdc++.h>
using namespace std;
const int MAX_MINUTE = 200001;
int main() {
    int admissedIntervals, admissibleThreshold, queries;
    cin >> admissedIntervals >> admissibleThreshold >> queries;

    vector<pair<int, int>> intervalsAndQueries;
    int totalPairs = admissedIntervals + queries;

    for (int i = 0; i < totalPairs; ++i) {
        int l, r;
        cin >> l >> r;
        intervalsAndQueries.emplace_back(l, r);
    }

    // Step 1: Build difference array from first `n` pairs
    vector<int> likes(MAX_MINUTE, 0);
    for (int i = 0; i < admissedIntervals; ++i) {
        int l = intervalsAndQueries[i].first;
        int r = intervalsAndQueries[i].second;
        likes[l]++;
        likes[r + 1]--;
    }

    // Step 2: Prefix sum over likes
    for (int i = 1; i < MAX_MINUTE; ++i) {
        likes[i] += likes[i - 1];
    }

    // Step 3: Build "good" binary mask
    vector<int> good(MAX_MINUTE, 0);
    for (int i = 1; i < MAX_MINUTE; ++i) {
        good[i] = (likes[i] >= admissibleThreshold) ? 1 : 0;
    }

    // Step 4: Prefix sum over good[]
    vector<int> prefixGood(MAX_MINUTE, 0);
    for (int i = 1; i < MAX_MINUTE; ++i) {
        prefixGood[i] = prefixGood[i - 1] + good[i];
    }

    // Step 5: Answer queries (next `q` pairs)
    for (int i = admissedIntervals; i < totalPairs; ++i) {
        int a = intervalsAndQueries[i].first;
        int b = intervalsAndQueries[i].second;
        cout << (prefixGood[b] - prefixGood[a - 1]) << "\n";
    }
    return 0;
}
