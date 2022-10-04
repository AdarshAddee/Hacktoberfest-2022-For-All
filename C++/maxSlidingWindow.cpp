// Github username : arnav0929
// Aim : Added Maximum Sliding Window in C++
// Date : 04-10-2022

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        
        vector<int>ans;
        
        for(int i=0;i<nums.size();i++)
        {
            if(q.size()!=0 && q.front()<=(i-k))
                q.pop_front();
            
            while(q.size()!=0 && nums[q.back()]<=nums[i])
                q.pop_back();
            
            q.push_back(i);
            
            if(i>=k-1)
            ans.push_back(nums[q.front()]);
        }
        return ans;
    }
