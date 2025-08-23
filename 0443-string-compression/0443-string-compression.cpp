class Solution {
public:
    int compress(vector<char>& chars) {
        int ans=0;
        int i=0;
        int index=0;
        while(i<chars.size()){
            char c=chars[i];
            int length=0;
            while(i<chars.size() && chars[i]==c){
                length++;
                i++;
                cout<<c<<" "<<length<<endl;
            }
            if(length==1){
                chars[index]=c;
                index++;
            }
            else {
                chars[index]=c;
                index++;
                vector<int> temp;
                while(length>0){
                    char f=(length%10)+'0';
                    temp.push_back(f);
                    length=length/10;
                }
                for(int k=temp.size()-1;k>=0;k--){
                    chars[index]=temp[k];
                    index++;
                }
            }
        }
        return index;
    }
};