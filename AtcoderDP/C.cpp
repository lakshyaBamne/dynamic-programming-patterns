/*
    C. Vacation -> https://atcoder.jp/contests/dp/tasks/dp_c
*/

#include<iostream>
#include<vector>

using namespace std;

int main(){
    int N;
    cin >> N;

    vector< vector<int> > dp(N, vector<int>(3, 0));
    vector<int> x(3, 0);

    for(int i=0 ; i<N ; i++){
        for(int j=0 ; j<3 ; j++){
            cin >> x[j];
        }

        if(i == 0){
            for(int j=0 ; j<3 ; j++){
                dp[i][j] = x[j];
            }
        }
        else{
            for(int j=0 ; j<3 ; j++){
                for(int k=0 ; k<3 ; k++){
                    if(j != k){
                        dp[i][j] = max(dp[i][j], dp[i-1][k] + x[j]);
                    }
                }
            }
        }

    }

    cout << max(dp[N-1][0], max(dp[N-1][1], dp[N-1][2])) << endl;

    return 0;
}