class Solution {
public:
    string removeDuplicateLetters(string text) {
        
           if(text.length()==0)
            return text;
            vector<int> freq(26,0);
            for(char &ch : text)
                freq[ch-'a']++;

            vector<bool> seen(26,0);
            string ans="0";
            for(char &ch: text)
            {
                freq[ch-'a']--;
                if(seen[ch-'a']==true)  //we can not have duplicate char
                    continue;
                while(ans.back() > ch && freq[ans.back()-'a'] >0)  //We'll only pop when ans.back() char has freq >0 (means it cannot occur later in string so must preserve it because we have to have each letter in ans and distinct also)
                {
                    seen[ans.back()-'a']=false;  //as we'are removing the last char so we mark it not vis in ans string
                    ans.pop_back();
                }

                seen[ch-'a']=true;
                ans+=ch;
            }
            return ans.substr(1);              
    }
};
