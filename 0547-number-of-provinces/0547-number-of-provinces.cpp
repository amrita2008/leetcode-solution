class Solution {
public:

    void dfs(int node,
             vector<vector<int>>& isConnected,
             vector<int>& vis) {

        vis[node] = 1;

        for(int neigh = 0; neigh < isConnected.size(); neigh++) {

            if(isConnected[node][neigh] == 1 &&
               !vis[neigh]) {

                dfs(neigh, isConnected, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();

        vector<int> vis(n, 0);

        int provinces = 0;

        for(int city = 0; city < n; city++) {

            if(!vis[city]) {

                provinces++;

                dfs(city, isConnected, vis);
            }
        }

        return provinces;
    }
};