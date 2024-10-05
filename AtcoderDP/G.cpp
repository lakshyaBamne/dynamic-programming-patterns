/*
    G. Longest Path -> https://atcoder.jp/contests/dp/tasks/dp_g

    -> Since we are given a Directed Acyclic Graph
    -> we can simply use the Kahn's algorithm to get the Topological Sort in O(V + E)
    -> Now maintain a DP table and keep track of the longest path starting from a vertex
    -> go in reverse of the given topological sort
*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> indegree(n+1);
    vector< vector<int> > adj(n+1, vector<int>(0));

    for(int i=0 ; i<m ; i++){
        int x, y;
        cin >> x >> y;

        indegree[y]++;
        adj[x].push_back(y);
    }

    vector<int> topo;
    queue<int> processing;

    // initialize the processing queue
    for(int i=1 ; i<=n ; i++){
        if(indegree[i] == 0){
            processing.push(i);
        }
    }

    while(!processing.empty()){
        int top = processing.front();
        processing.pop();

        for(auto y : adj[top]){
            indegree[y]--;

            if(indegree[y] == 0){
                processing.push(y);
            }
        }

        topo.push_back(top);
    }

    vector<int> dp(n+1, 0);
    int max_path_length = 0;

    for(int i=topo.size()-1 ; i>=0 ; i--){
        for(auto j : adj[topo[i]]){
            dp[topo[i]] = max(dp[topo[i]], 1 + dp[j]);
        }

        max_path_length = max(max_path_length, dp[topo[i]]);
    }

    cout << max_path_length << endl;

    return 0;
}


