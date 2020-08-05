class WordDictionary {
public:
    struct Node {
        bool isWord;
        unordered_map<char,Node*> child;
        Node(Node *parent = NULL, char c = ' ') : isWord(false) {
            if (parent) parent->child[c] = this;
        }
        Node* get(char c, bool create = false) {
            auto iter = child.find(c);
            if (iter != child.end()) return iter->second;
            return create ? new Node(this, c) : NULL;
        }
    };
    
    Node trieRoot;
    
    WordDictionary() { }
    
    void addWord(string word) {
        Node *cur = &trieRoot;
        for (auto c : word) 
            cur = cur->get(c, true);
        cur->isWord = true;
    }
    
    //
    // Using DFS  ::  132ms, 38.3mb
    //
    bool search(string word) {
        return word.length() ? searchDFS(word, 0, &trieRoot) : false;
    }
    
    bool searchDFS(string& word, int idx, Node* node) {
        char c = word[idx];
        if (c == '.') {
            for (auto& iter : node->child) {
                if (idx+1 == word.length() && iter.second->isWord)
                    return true;
                if (searchDFS(word, idx+1, iter.second))
                    return true;
            }
        } else {
            Node *childNode = node->get(c);
            if (childNode) {
                if (idx+1 == word.length() && childNode->isWord)
                    return true;
                if (searchDFS(word, idx+1, childNode))
                    return true;
            }
        }
        return false;
    }
        
    /*
    //
    // Using BFS  ::  132 ms, 54.7 mb
    //
    bool search(string word) {
        Node *childNode, *curNode;
        int i, charIdx = 0;
        queue<Node*> q;
        
        q.push(&trieRoot);
        while (q.size() && charIdx < word.length()) {
            int qsize = q.size();
            char c = word[charIdx++];
            for (i = 0; i < qsize; ++i) {
                curNode = q.front();  
                q.pop();
                if (c == '.') { 
                    for (auto& iter : curNode->child) {
                        if (charIdx == word.length() && iter.second->isWord) 
                            return true;
                        q.push(iter.second);
                    }
                } else if (childNode = curNode->get(c)) { 
                    if (charIdx == word.length() && childNode->isWord) 
                        return true;
                    q.push(childNode);
                }
            }
        }
        return false;
    }
    */   
};
