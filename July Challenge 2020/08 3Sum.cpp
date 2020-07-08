class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
		//We will use this set to avoid duplicates
        set<vector<int>>s;
        int n = arr.size();
		//Loop through all elements one by one till the third last element
        for (int i = 0; i < n - 2; i++)
        {
            int val = arr[i];  // The Current element
			int l = i + 1;   // set left pointer
			int r = n - 1;   // set the right pointer
			//Iterate till l and r cross each other
            while (l < r)
            {
                int csum = val + arr[l] + arr[r]; //The current sum of all three elements
                if (csum == 0){
					// if sum is equal to zero add to the set
                    s.insert({val,arr[l++],arr[r--]}); 
                }
                else if (csum < 0) {
				// If sum is less than zero that means we need a larger number to be close to zero so we should increment left pointer as the array is sorted and so the next element will be larger
                    l++;
                }else{
				// If sum is greater than zero that means we need a smaller number to be close to zero so we should decrement right pointer as the array is sorted and so the next element will be smaller.
                    r--;
                }
            }
        }
		//Add all elements from the set to ans array
        for(auto x: s){
            ans.push_back(x);
        }
        return ans;
    }
};
