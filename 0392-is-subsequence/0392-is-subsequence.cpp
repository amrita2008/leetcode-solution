class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=t.size();
        int m=s.size();
        int i=0,j=0;
       while(i<m && j<n){
        if(t[j]==s[i]){
            i++;
        }
        j++;
       }
       return i==s.size();
    }
};