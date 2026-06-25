class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char, int> mp;

        for(char ch : s) {
            mp[ch]++;
        }

        vector<pair<char, int>> freq(mp.begin(), mp.end());

        sort(freq.begin(), freq.end(),
             [](pair<char,int>& a, pair<char,int>& b) {
                 return a.second > b.second;
             });

        string ans = "";

        for(auto &p : freq) {
            ans.append(p.second, p.first);
        }

        return ans;
    }
};