class Solution {
public:
    int solve(string s,int i,long long nums,int sign){
        if(i>=s.size() || !isdigit(s[i])){
            return (int)(sign*nums);
        }
        nums=nums*10+(s[i]-'0');

        if(sign * nums <= INT_MIN) return INT_MIN;
        if(sign * nums >= INT_MAX) return INT_MAX;

        return solve(s,i+1,nums,sign);
    }
    int myAtoi(string s) {
        int i=0;
        while(i<s.size() && s[i]==' ') i++;

        int sign=1;
        if(i<s.size() && (s[i]=='+' || s[i]=='-')){
            sign=(s[i]=='-')?-1:1;
            i++;
        }
        

        return solve(s,i,0,sign);
    }
};