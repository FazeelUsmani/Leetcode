#include <stdio.h>
#include <conio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    int n = nums.size();

    if(n == 0 || k < 0  || t < 0) return false;

    unordered_map<int,int> buckets;

    for(int i=0; i<n; ++i) {
        int bucket = nums[i] / ((long)t + 1);
        
        if(nums[i] < 0) --bucket;
        
        if(buckets.find(bucket) != buckets.end()) return true;
        else {
            buckets[bucket] = nums[i];
            if(buckets.find(bucket-1) != buckets.end() && (long) nums[i] - buckets[bucket-1] <= t) return true;
            if(buckets.find(bucket+1) != buckets.end() && (long) buckets[bucket+1] - nums[i] <= t) return true;
            
            if(buckets.size() > k) {
                int key_to_remove = nums[i-k] / ((long)t + 1);
                
                if(nums[i-k] < 0) --key_to_remove;
                
                buckets.erase(key_to_remove);
            }
        }
    }
    return false;  
}     

int main(){
    vector<int> A{1,2,3,1};
    int k = 3, t = 0;
    cout<<containsNearbyAlmostDuplicate(A, k, t);

    return 0;
}