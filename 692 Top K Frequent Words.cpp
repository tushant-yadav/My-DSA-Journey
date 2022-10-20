/*
692. Top K Frequent Words
https://leetcode.com/problems/top-k-frequent-words
Given an array of strings words and an integer k, return the k most frequent strings.

Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.

*/class Solution {
public:
    static bool comp(pair<string,int> a, pair<string,int> b){
        if(a.second==b.second) return a.first<b.first;
        return a.second>b.second;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> um;
        for(auto i:words){
            um[i]++;
        }
        vector<pair<string,int>> count;
        for(auto i:um){
            count.push_back({i.first,i.second});
            
        }
        sort(count.begin(),count.end(),comp);
        vector<string> ans;
        for(int i =0;i<k;i++){
            cout<<count[i].first<<":"<<count[i].second<<endl;
            ans.push_back(count[i].first);
        }
        return ans;
    }
};
