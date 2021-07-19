class RandomizedSet {
public:
    void swap(int &a, int &b){
        int temp = b;
        b = a;
        a = temp;
    }
    vector<int> A;
    unordered_map<int, int> umap;    
    /** Initialize your data structure here. */
    RandomizedSet() {
        A.clear();
        umap.clear();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (umap.find(val) != umap.end())
            return false;
        A.push_back(val);
        umap.insert(pair<int, int>(val, A.size() - 1));        
        
        return true;        
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {        
        if (umap.find(val) == umap.end())
            return false;
        
        int index = umap[val];
        A[index] = A[A.size()-1];
        umap[A[index]] = index;        
        A.pop_back();        
        umap.erase(val);
    
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return A[rand() % A.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
