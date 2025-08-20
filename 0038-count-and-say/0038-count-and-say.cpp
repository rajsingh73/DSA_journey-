class Solution {
public:
    string countAndSay(int n) {
        string temp="1";
        for(int i=0;i<n-1;i++){
            string t="";
            int j=0;
            while(j<temp.size()){
                int count=0;
                char c=temp[j];
                while(j<temp.size() && c==temp[j]){
                    count++;
                    j++;
                }
                t+=char(count+'0');
                t+=c;
            }
            temp=t;
        }
        return temp;
        
    }
};