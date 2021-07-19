#define ROW 30
#define COL 1000000

int trie[ROW][COL];
int cnt[ROW][COL];
bool EOW[ROW][COL];
int nextAvailable = 1;       


class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        
        for (int i = 0; i < ROW; i++){
            for (int j = 0; j < COL; j++){
                trie[i][j] = -1;
                cnt[i][j] = 0;
                EOW[i][j] = false;
            }
        }
        nextAvailable = 1;                           
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        
        int ptr = 0;
        int len = word.length();

        for (int i = 0; i < len; i++){
            char ch = word[i];
            int index = ch-'a'+1;

            cnt[index][ptr] ++;

            if (trie [index][ptr] == -1){
                trie [0][nextAvailable] = ch;
                trie [index][ptr] = nextAvailable;
                ptr = nextAvailable;
                nextAvailable++;
            }
            else{
                ptr = trie [index][ptr];
            }
            if (i == len-1)
                EOW[index][ptr] = true;      
        }
        
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int ptr = 0;
        int len = word.length();

        for (int i = 0; i < len; i++){
            char ch = word[i];
            int index = ch - 'a' + 1;

            if (trie[index][ptr] == -1)
                return false;
            else
            {
                ptr = trie[index][ptr];
                if (ch != trie[0][ptr])
                    return false;
                if (i == len-1){
                    if (EOW[index][ptr] == false){
                        return false;
                    }
                }
            }              
        }

        return true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) {
        int ptr = 0;
        int len = word.length();

        for (int i = 0; i < len; i++){
            char ch = word[i];
            int index = ch - 'a' + 1;

            if (trie[index][ptr] == -1)
                return false;
            else
            {
                ptr = trie[index][ptr];
                if (ch != trie[0][ptr])
                    return false;
            }              
        }

        return true;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
