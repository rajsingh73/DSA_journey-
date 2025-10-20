class Solution {
public:
    bool isPalindrome(int x) {
        if(x==0) return true;
        if(x<0 || x%10==0) return false;
        int reverse=0;
        int temp=x;
        while(x>0){
            int rem=x%10;
            if(reverse>(INT_MAX/10)) return false;
            reverse=(reverse*10)+rem;
            x=x/10;
        }
        return temp==reverse;  
    }
};