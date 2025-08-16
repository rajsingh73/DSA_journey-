class Solution {
public:
    int reversenum(int num){
        int newnum=0;
        while(num>0){
            int rem=num%10;
            newnum=newnum*10+rem;
            num=num/10;
        }
        return newnum;
    }
    int maximum69Number (int num) {
        int revone=reversenum(num);
        int ansone=0;
        int count=0;
        while(revone>0){
            int rem=revone%10;
            if(rem==6 && count==0){
                count=1;
                ansone=ansone*10+9;
            }
            else ansone=ansone*10+rem;
            revone=revone/10;
        }
        return ansone;
    }
};