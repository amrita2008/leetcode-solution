class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int HashLen = 256;
        int hash[HashLen];
        for (int i = 0; i < HashLen;i++) {
            hash[i] = -1;
        }
        int l=0;
        int r=0;
        int maxlength=0;
        int n=s.size();
        while(r<n){
            if(hash[s[r] !=-1]){
                if(hash[s[r]]>=l){
                    l=hash[s[r]]+1;
                }
            }
            int length=r-l+1;
            maxlength=max(length,maxlength);
            hash[s[r]]=r;
            r++;
      }
      return maxlength;
    }
};