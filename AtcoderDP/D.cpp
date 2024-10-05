/*
    D. Knapsack-1 : https://atcoder.jp/contests/dp/tasks/dp_d
*/

#include<iostream>
#include<vector>

using namespace std;

using ll = long long;
using ull = unsigned long long;

// function solved the bounded 01 knapsack problem given the inputs
ull knapsack01(ll N, ll Ck, vector<ll>& w, vector<ll>& v){
    vector< vector<ll> > dp(N, vector<ll>(Ck+1, 0));

    // initial calculations
    for(ll i=0 ; i<N ; i++){
        dp[i][0] = 0;
    }

    // suppose there is only the last element present to take
    for(ll j=1 ; j<=Ck ; j++){
        dp[N-1][j] = j >= w[N-1] ? v[N-1] : 0;
    }

    // dp table calculation
    for(ll i=N-2 ; i>=0 ; i--){
        for(ll j=1 ; j<=Ck ; j++){
            if(j>=w[i]){
                // taking is a possibility
                dp[i][j] = max(v[i]+dp[i+1][j-w[i]] , dp[i+1][j]);
            }
            else{
                // only skip is possible
                dp[i][j] = dp[i+1][j];
            }
        }
    }

    return dp[0][Ck];
}

int main(){
    ll N; // number of iterms
    ll Ck; // total capacity of the knapsack

    cin >> N >> Ck;

    vector<ll> w(N); // weights
    vector<ll> v(N); // values

    for(ll i=0 ; i<N ; i++){
        cin >> w[i] >> v[i];
    }

    // solve the knapsack problem
    cout << knapsack01(N, Ck, w, v) << endl;

    return 0;
}

