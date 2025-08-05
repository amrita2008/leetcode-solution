class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0||(x%10==0&& x!=0)){
            return false;
        }
        int revertednumber=0;
        while(x>revertednumber){
            revertednumber=revertednumber*10+x%10;
            x=x/10;
        
        }
        return x==revertednumber || x==revertednumber/10;
    }
};