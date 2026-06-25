class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string strs1=strs[0];
        string strs2=strs[strs.size()-1];
        string str="";
        int minlength=min(strs1.size(),strs2.size());
        for(int i=0;i<minlength;i++){
            if(strs1[i] != strs2[i]) break;
            str+=strs1[i];
        }
        return str;

    }
};