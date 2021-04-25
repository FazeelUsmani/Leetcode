class Solution {
    public int findUnsortedSubarray(int[] nums) {
         
         int start = -1;
         int end = -1;
         int prevHigh = nums.length-1;
         int prevLow = 0;
         for(int i=0;i<nums.length;i++){
             if(nums[i]<nums[prevLow]){
                 end = i;
             } else {
                 prevLow = i;
             }
         }

         for(int i=nums.length-1; i >= 0; i--){
             if(nums[i] > nums[prevHigh]){
                 start = i;
             } else {
                 prevHigh = i;
             }
         }

         return (start>=0 && end>=0) ? (end-start)+1 : 0;

    }
}
