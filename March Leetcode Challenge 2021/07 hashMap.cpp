class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap(): m_(1000000+1, -1) { // better
        //m_ = vector<int> (1000000+1, -1); //ok
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        m_[key]=value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        return m_[key];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        m_[key]=-1;
    }
    
private:
    vector<int> m_;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
