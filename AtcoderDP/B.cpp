/*
    B. Frog-2 -> https://atcoder.jp/contests/dp/tasks/dp_b
*/

#include<iostream>
#include<vector>
#include<queue>
#include<utility>

using namespace std;

// finds the best choice for a given index in O(K) time
// thus making the overall complexity O(NK).
int find_min_cost(vector<int>& h, vector<int>& min_costs, int i, int k){
    int min_cost = INT_MAX;

    for(int j=i-1 ; j>=0 && j>=i-k ; j--){
        min_cost = min(min_cost, min_costs[j] + abs(h[i]-h[j]));
    }

    return min_cost;
}

int main(){
    int N, K, temp;
    cin >> N >> K;

    vector<int> h;
    for(int i=0 ; i<N ; i++){
        cin >> temp;

        h.push_back(temp);
    }

    // vector of min costs reaching any stone
    vector<int> min_cost(N, 0);

    for(int i=1 ; i<N ; i++){
        min_cost[i] = find_min_cost(h, min_cost, i, K);
    }

    cout << min_cost.back() << endl;
}

