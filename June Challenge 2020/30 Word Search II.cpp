struct TrieNode {
    unordered_map<char, TrieNode *> dict;   // hold mapping between character and child TrieNode
    bool endOfWord;                         // marks end of word
    string word;                            // holds complete word when marked as end
    TrieNode(): endOfWord(false) {}
};

class Solution {    
public:
    // build trie data structure from words to search
    TrieNode *buildTrie(vector<string> words) {
        TrieNode *root = new TrieNode();
        // for each word in dictionary
        for(string w: words) {
            TrieNode *node = root;
            // iteratively populate trie nodes
            for(char c: w) {
                // if character does not exist in map of current trie node
                if(node->dict.empty() || node->dict.find(c) == node->dict.end()) {
                    node->dict.insert({c, new TrieNode});   // add character with new child trie node
                }
                node = node->dict[c];   // move trie node pointer to child node
            }
            node->endOfWord = true;     // mark node as end of word
            node->word = w;             // store complete word in that node
        }
        return root;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode *root = buildTrie(words);      // returns root of trie data structure after building
        
        int m = board.size(), n = board[0].size();
        set<string> s;      // store found words in set to avoid duplicates
        // for each cell of the board recursively check if character is present in trie nodes
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                dfs(board, root, i, j, s);
            }
        }
            
        // throw every found word in vector and return
        vector<string> res;
        for(string word: s)     res.push_back(word);
        return res;
    }
    
    void dfs(vector<vector<char>> &board, TrieNode *node, int i, int j, set<string> &s) {
        // handles out of bounds or if board character is not present in trie node
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || node->dict.find(board[i][j]) == node->dict.end())     return;
        
        // if current board character is found in trie node move node control to child of that character
        node = node->dict[board[i][j]];      
        if(node->endOfWord)     s.insert(node->word);   // check if node is marked as end of word and push word stored in that node to set of found words
        
        char c = board[i][j];   // store cell temporarily
        board[i][j] = ' ';      // mark cell as visited by invalidating
        
        // recursively check if characters to the up, right, down or left of current board character can be included in words to search
        dfs(board, node, i-1, j, s);
        dfs(board, node, i, j+1, s);
        dfs(board, node, i+1, j, s);
        dfs(board, node, i, j-1, s);
        
        board[i][j] = c;        // undo/backtrack changes to cell
    }
};
