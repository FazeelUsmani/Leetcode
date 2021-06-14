class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxes, int truckSize) {
                 
        int res = 0, sizeBucket[1001] = {}, currBatch;
        set<int, greater<int>> bucketSizes;
        // bucket sorting tthe boxes and recording the bucket range
        for (auto &boxType: boxes) {
            bucketSizes.insert(boxType[1]);
            sizeBucket[boxType[1]] += boxType[0];
        }
		// carrying as many larger sized boxes as we can first
        for (int size: bucketSizes) {
            currBatch = min(sizeBucket[size], truckSize);
            truckSize -= currBatch;
            res += currBatch * size;
            if (!truckSize) break;
        }
        return res;       
    }
};
