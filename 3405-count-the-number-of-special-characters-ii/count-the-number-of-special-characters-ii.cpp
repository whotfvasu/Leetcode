class Solution {
public:
    int numberOfSpecialChars(string word) {
        set<char> st;
        set<char> st2;
        int n = word.size();
        for(char ch: word){
            if(islower(ch)){
                if(st.find(toupper(ch)) != st.end()){
                    if(st2.find(toupper(ch)) != st2.end()){
                        st2.erase(toupper(ch));
                    }
                }
                else{
                    st.insert(ch);
                }
            }
            else{
                if(st.find(tolower(ch)) != st.end() && st.find(toupper(ch)) == st.end()){ 
                        st2.insert(ch);
                }
                st.insert(ch);
            }
        }
        return st2.size();
    }
};