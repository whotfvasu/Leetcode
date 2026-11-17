class Solution
{
    public:
        struct cmp
        {
            bool operator()(pair<int, string> &a, pair<int, string> &b)
            {
                if (a.first != b.first)
                {
                    return a.first > b.first;
                }
                else return a.second < b.second;
            }
        };
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        int n = words.size();
       	// create freq map
        unordered_map<string, int> mpp;
        for (int i = 0; i < n; i++)
        {
            mpp[words[i]]++;
        }
       	// push k elements in min heap
       	// check rest n-k elements and do push pop if it's freq is greater then pq.top()
        priority_queue<pair<int, string>, vector< pair<int, string>>, cmp> pq;
        for (auto it: mpp)
        {
            string word = it.first;
            int freq = it.second;
            if (pq.size() < k)
            {
                pq.push({ freq,
                    word });
                continue;
            }
            if (freq < pq.top().first || (freq == pq.top().first && word > pq.top().second)) continue;
            pq.pop();
            pq.push({ freq,
                word });
        }
       	// push res elements in res array
        vector<string> res;
        while (!pq.empty())
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};