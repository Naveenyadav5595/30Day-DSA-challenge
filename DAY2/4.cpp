#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> events;
        for (auto& b : buildings) {
            events.emplace_back(b[0], -b[2]);  // entering: height negative
            events.emplace_back(b[1], b[2]);   // leaving: height positive
        }

        sort(events.begin(), events.end());
        multiset<int> heights = {0};
        vector<vector<int>> result;
        int prevHeight = 0;

        for (auto& event : events) {
            int x = event.first;
            int h = event.second;

            if (h < 0) {
                heights.insert(-h);  // entering
            } else {
                heights.erase(heights.find(h));  // leaving
            }

            int currHeight = *heights.rbegin();
            if (currHeight != prevHeight) {
                result.push_back({x, currHeight});
                prevHeight = currHeight;
            }
        }

        return result;
    }
};