#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        priority_queue<pair<int,int>> pq;
        for(int i = 0; i < aliceValues.size(); i++){
            pq.push({aliceValues[i] + bobValues[i], i});
        }
        int turn = 0, alice = 0, bob = 0;
        while(!pq.empty()){
            int idx = pq.top().second;
            pq.pop();
            if(turn % 2 == 0) alice += aliceValues[idx];
            else bob += bobValues[idx];
            turn++;
        }
        return alice > bob ? 1 : alice == bob ? 0 : -1;
    }
};
