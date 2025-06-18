class Solution
{
    public:
        bool isValid(string s)
        {
            map<char, char> mpp;
            mpp[')'] = '(';
            mpp['}'] = '{';
            mpp[']'] = '[';
            stack<char> st;
            int n = s.length();
            for (int i = 0; i < n; i++)
            {
                if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                {
                    st.push(s[i]);
                }
                else
                {
                    if (!st.empty() && st.top() == mpp[s[i]]) st.pop();
                    else return false;
                }
            }
            if (!st.empty()) return false;
            return true;
        }
};