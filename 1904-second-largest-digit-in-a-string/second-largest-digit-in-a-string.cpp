class Solution {
public:
    int secondHighest(string s) {
        int n = s.length();
        int maxi = -1;
        int secondmaxi = -1;
        for(int i=0;i<n;i++){
            int digit = s[i]-'0';
            if(digit>=0 && digit<=9){
                // maxi = max(maxi,s[i]-'0');
                if(digit>maxi){
                    secondmaxi = maxi;
                    maxi = digit;
                }
                else if(digit> secondmaxi && digit<maxi){
                    secondmaxi = digit;
                }

            }
            
        }
        
        return secondmaxi;
    }
};