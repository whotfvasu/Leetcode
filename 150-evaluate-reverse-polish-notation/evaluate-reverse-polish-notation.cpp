class Solution
{
    public:
        bool isNumber(const string &s)
        {
            if (s.empty()) return false;

            if ((s == "-") || (s == "+")) return false;

            int start = (s[0] == '-' || s[0] == '+') ? 1 : 0;
            for (int i = start; i < s.size(); ++i)
            {
                if (!isdigit(s[i])) return false;
            }
            return true;
        }
    int applyOperator(int a, int b, char op)
    {
        switch (op)
        {
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '*':
                return a * b;
            case '/':
                return a / b;
            default:
                throw runtime_error("Unknown operator");
        }
    }
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;

        for (const string &token: tokens)
        {
            if (isNumber(token))
            {
                st.push(stoi(token));
            }
            else
            {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                int result = applyOperator(a, b, token[0]);
                st.push(result);
            }
        }

        return st.top();
    }
};