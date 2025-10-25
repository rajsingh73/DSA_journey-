class Solution {
    public int distMoney(int money, int children) {
        if(money<children) return -1;
        int mul=money/8;
        int rem=money%8;
        while(true){
            if(rem!=0){
                if((children-mul<=0) || (children-mul>rem)|| (children-mul==1 && rem==4)){
                    rem+=8;
                    mul-=1;
                }
                else return mul;
            }
            else{
                if(children-mul==0) return mul;
                else{
                    rem+=8;
                    mul-=1;
                }
            }
        }
    }
}