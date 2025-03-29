#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v=nums;
        sort(nums.begin(), nums.end());
        int l=0, r=nums.size()-1;
        while (l<r) {
            int sum=nums[l]+nums[r];
            if (sum==target) {
                vector<int> ans;
                for (int i=0; i<v.size(); i++) {
                    if (v[i]==nums[l]) {
                        ans.push_back(i);
                        break;
                    }
                }
                for (int i=0; i<v.size(); i++) {
                    if (v[i]==nums[r]&&i!=ans[0]) {
                        ans.push_back(i);
                        break;
                    }
                }
                return ans;
            } else if (sum>target) {
                r--;
            } else {
                l++;
            }
        }
        return nums;
    }
};
/*
Alternative (using maps):

map<int, int> mp;
for (int i=0; i<nums.size(); i++) {
    mp[nums[i]]=i+1;
}
for (int i=0; i<nums.size(); i++) {
    if (mp[target-nums[i]]>0&&mp[target-nums[i]]-1!=i) {
        vector<int> ans;
        ans.push_back(i);
        ans.push_back(mp[target-nums[i]]-1);
        return ans;
    }
}
return nums;

*/