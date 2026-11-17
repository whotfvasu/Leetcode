class Solution {
public:
    struct cmp{
        bool operator()(pair<int,int> &a, pair<int,int> &b){
            if(a.first!=b.first){
                return a.first>b.first;
            }
            else return a.second>b.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        // create freq map
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        // push k elements in min heap
        // check rest n-k elements and do push pop if it's freq is greater then pq.top()
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
        for(auto it: mpp){
            int num = it.first;
            int freq = it.second;
            if(pq.size()<k){
                pq.push({freq,num});
                continue;
            }
            if(freq<pq.top().first) continue;
            pq.pop();
            pq.push({freq,num});
        }
        // push res elements in res array
        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop(); 
        }
        return res;
        
    }
};