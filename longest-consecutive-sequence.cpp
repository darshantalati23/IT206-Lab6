#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l=0, r=1, maxl=nums.size()>0?1:0;
        while (l<=r&&r<nums.size()) {
            if (nums[r]==nums[r-1]+1||nums[r]==nums[r-1]) {
                maxl=max(nums[r]-nums[l]+1, maxl);
            } else {
                l=r;
            }
            r++;
        }
        return maxl;
    }
};