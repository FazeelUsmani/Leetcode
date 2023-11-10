class Trie {
public:
    Trie* children[26] = {};
    bool isWord = false;
    
    void insert(string word) {
        Trie* cur = this;
        for (char c : word) {
            c -= 'a';
            if (cur->children[c] == nullptr)
                cur->children[c] = new Trie();
            cur = cur->children[c];
        }
        cur->isWord = true;
    }
    
    bool search(string word) {
        Trie* cur = this;
        for (char c : word) {
            c -= 'a';
            if (cur->children[c] == nullptr) return false;
            cur = cur->children[c];
        }
        return cur->isWord;
    }
    
    bool startsWith(string prefix) {
        Trie* cur = this;
        for (char c : prefix) {
            c -= 'a';
            if (cur->children[c] == nullptr) return false;
            cur = cur->children[c];
        }
        return true;
    }
};
