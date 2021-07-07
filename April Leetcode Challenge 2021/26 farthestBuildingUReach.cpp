class Solution {
public:
    int furthestBuilding(vector<int>& H, int bricks, int ladders) {
        
        int i = 0, n = size(H), jumpHeight;
        // pq will store the first ladder number of largest jumps
        priority_queue<int, vector<int> ,greater<int> > pq;
        // first ladder number of jumps would be assumed to be the largest
        // hence, push all these jumps into the queue
        while (i < n - 1 && size(pq) < ladders) {
            jumpHeight = H[i + 1] - H[i];
            if(jumpHeight > 0) 
                pq.push(jumpHeight);
            i++;            
        }
        // From here, we can't just use ladder and need to spend bricks from now on...
        while (i < n - 1) {
            jumpHeight = H[i + 1] - H[i];
            // if next building is bigger than current, bricks need to be used
            if(jumpHeight > 0) {
                // First check if we have a previous jump requiring less number of bricks than currentDiff
                if(!pq.empty() && pq.top() < jumpHeight) {                    
                    // if there is, just use bricks for that jump and assign ladder for current one
                    bricks -= pq.top(); pq.pop(); 
                    pq.push(jumpHeight);                    
                }
                // jumpHeight is already minimum jump size. So, no choice than spending that many bricks
                else bricks -= jumpHeight;    
            }
            // if bricks become negative, we can't travel any further as all bricks and ladders are used up
            if(bricks < 0) return i;
            i++;
        }
        
        return i;
        
    }
};
