/*
Leetcode problem no .- 1310
problem name -XOR Queries of a Subarray
Difficulty - Medium

*/

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
         int n=arr.size(); vector<int> ans;
     int prefix[n];
        prefix[0]=arr[0];
             for(int i=1;i<arr.size();i++)                                                        
                prefix[i]=prefix[i-1]^arr[i];
        
        for(auto x:queries){
            ans.push_back(arr[x[0]] ^ prefix[x[0]] ^ prefix[x[1]]);
        }
                                                                            
        return ans;
        
        
    }
};
