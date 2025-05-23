#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<pair<int, int>> sortMapByFreqDecreasing(map<int, int>& m) {
            
            vector<pair<int, int>> freqVec(m.begin(), m.end());
            
            sort(freqVec.begin(), freqVec.end(), 
                [](const pair<int, int>& a, const pair<int, int>& b) {
                    return a.second > b.second;
                });
            
            return freqVec;
        }
        vector<int> topKFrequent(vector<int>& nums, int k) {
            map<int, int> m;
            for (int i=0; i<nums.size(); i++) {
                m[nums[i]]++;
            }
            vector<pair<int, int>> v = sortMapByFreqDecreasing(m);
            vector<int> ans;
            for(int i=0; i<k; i++) {
                ans.push_back(v[i].first);
            }
            return ans;
        }
    };