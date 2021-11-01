class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> almac;
    
    for(auto i : nums)
    {
        almac.push(i);
        if(almac.size()>k) almac.pop();
    }
    
    return almac.top();
    }
};