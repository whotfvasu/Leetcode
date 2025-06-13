class Solution
{
    public:
        vector<int> twoSum(vector<int> &v, int k)
        {
            int n = v.size();
            int st = 0;
            int en = n - 1;
            while (st < en)
            {
                if (v[st] + v[en] == k) return {
                    st + 1,
                    en + 1
                };
                else if (v[st] + v[en] > k) en--;
                else st++;
            }
            return { -1,
                -1 };
        }
};