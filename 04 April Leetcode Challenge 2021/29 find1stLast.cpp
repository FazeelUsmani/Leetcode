class Solution {
public:
    int bs(vector<int> & nums,int l,int h,int tar,bool uff)
    {
        int res=-1;
        while(l<=h)
        {
            int mid=(l+h)/2;
            
            if(nums[mid]==tar)
            {
                res=mid;
                if(uff)
                    l=mid+1;
                else
                    h=mid-1;
            }
            else if(nums[mid]>tar)
                h=mid-1;
            else
                l=mid+1;
        }
        return res;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> res(2);
        int n=nums.size();
        res[0]=bs(nums,0,n-1,target,false);
        res[1]=bs(nums,0,n-1,target,true);
        
        return res;
    }
};
