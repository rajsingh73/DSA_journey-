class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count=0;
        for(int i=low;i<=high;i++){
            string s=to_string(i);
            if(s.size()%2!=0) continue;
            int firstend=(s.size()/2);
            int firstsum=0;
            for(int j=0;j<firstend;j++){
                firstsum+=s[j]-'0';
            }
            int secondsum=0;
            for(int j=firstend;j<s.size();j++){
                secondsum+=s[j]-'0';
            }
            if(firstsum==secondsum) count++;
        }
        return count;
        
    }
};