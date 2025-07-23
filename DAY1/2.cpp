#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class Solution {
    priority_queue<pair<int,int>> pq;
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        for(int i=0;i<k;i++){
            pq.push({nums[i],i});
        }
        ans.push_back(pq.top().first);
        for(int i=k;i<nums.size();i++){
            while(!pq.empty()&& pq.top().second<=i-k){
                pq.pop();
            }
            pq.push({nums[i],i});
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};