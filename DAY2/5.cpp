#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;
        for (int i = 0; i < s.length(); i++) {
            freq[s[i]]++;
        }

        // Max heap of {frequency, character}
        priority_queue<pair<int, char>> maxHeap;
        for (unordered_map<char, int>::iterator it = freq.begin(); it != freq.end(); ++it) {
            maxHeap.push(make_pair(it->second, it->first));
        }

        string result = "";
        pair<int, char> prev = make_pair(0, '#');

        while (!maxHeap.empty()) {
            pair<int, char> current = maxHeap.top();
            maxHeap.pop();

            result += current.second;

            if (prev.first > 0) {
                maxHeap.push(prev);
            }

            current.first--;
            prev = current;
        }

        if (result.length() != s.length())
            return "";

        return result;
    }
};