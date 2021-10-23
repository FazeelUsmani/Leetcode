 int findMin(vector<int>& nums) {
        
        int l = 0, r = nums.size()-1;
        
        if(nums[l]<nums[r]) // already sorted (0 rotation)
            return nums[0]; // return first element
    
        while(l<r)
        {
            int mid = l + (r-l)/2; // finding middle
            
            if(nums[mid]>nums[r]){
                l = mid + 1;
            }
            else if(nums[l]>nums[mid]){
                r = mid;
            }
            else{
                r--; //overcome duplicate elements
            }
        }
        return nums[r];   
    }
