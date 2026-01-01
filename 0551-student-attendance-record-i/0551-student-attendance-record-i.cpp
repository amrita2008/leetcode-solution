class Solution {
public:
    bool checkRecord(string s) {
        int n=s.size();
        int countA=0;
        int countL=0;
        for(int i=0;i<n;i++){
            if(s[i]=='A'){
                countA++;
                if(countA>=2)
                return false;
            }
            if(s[i]=='L'){
                countL++;
                if(countL>=3)
                return false;      
            }
            else{
                countL=0;
            }
        }
        return true;
    }
};