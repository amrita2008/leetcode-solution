class Solution {
public:
    string reverseWords(string s) {
          int i=0;
          int n=s.size();
          string temp="";
          string res="";
          while(i<n){
            while(i<n && s[i]==' ') i++;
            temp="";
            while(i<n && s[i]!=' '){
                temp+=s[i];
                i++;
            }
            if(temp!=""){
                if(res!="") res=temp+" "+res;
                else res=temp;
            }
          }
          return res;
    }
};