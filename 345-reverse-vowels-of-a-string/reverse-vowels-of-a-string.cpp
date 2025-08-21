class Solution {
public:
stack<char> st;
    string reverseVowels(string s) {
        for(char ch:s){
            if(ch=='a'||ch=='A'||ch=='e'||ch=='E'||ch=='i'||ch=='I'||ch=='o'||ch=='O'||ch=='u'||ch=='U'){
                st.push(ch);
            }
        }
        for( char &ch:s){
             if(ch=='a'||ch=='A'||ch=='e'||ch=='E'||ch=='i'||ch=='I'||ch=='o'||ch=='O'||ch=='u'||ch=='U'){
                ch=st.top();
                st.pop();
             }
        }
          return s;
    }
};