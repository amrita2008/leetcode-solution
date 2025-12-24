class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n= s.length();
        int max_l=0;
        int l=0;
        unordered_set<char>charset;
        for(int r=0;r<n;r++){
            if(charset.count(s[r])==0){
                charset.insert(s[r]);
                max_l=max(max_l,r-l+1);
            }
            else{
                while(charset.count(s[r])){
                    charset.erase(s[l]);
                    l++;
                }
                charset.insert(s[r]);
            }
        }
        return max_l;
    }
};