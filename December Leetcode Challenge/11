class Solution {
public:
    int removeDuplicates(vector<int>& n) {
        if(n.size()<=1)
            return n.size();
        int a=n[0],ans=1;
        bool k=0;
        for(int i=1;i<n.size();i++)
        {
            if(n[i]==a)
            {
                if(k)
                {
                    n.erase(n.begin()+i);
                    i--;
                }
                else
                {
                    k=1;
                    ans++;
                }
            }
            else
            {
                a=n[i];
                k=0;
                ans++;
            }
        }
        return ans;
    }
};
