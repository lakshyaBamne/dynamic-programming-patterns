#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

using ld = long double;

int main(){
    int n;
    cin >> n;

    vector<ld> p(n);
    for(int i=0 ; i<n ; i++){
        cin >> p[i];
    }

    if(n == 1){
        cout << setprecision(20) << p[0] << endl;
        return 0;
    }

    int lim = n - ( (int)(n/2) + 1 ); // maximum number of tails we can take
    
    vector<ld> pre_tail(lim+1);
    pre_tail[1] = 1 - p[0];
    for(int i=2 ; i<=lim ; i++){
        pre_tail[i] = (1-p[i-1])*pre_tail[i-1];
    }

    vector< vector<ld> > dp(n, vector<ld>(lim+1));

    // initial calculation
    dp[0][0] = p[0];
    for(int i=1 ; i<n ; i++){
        dp[i][0] = dp[i-1][0] * p[i];
    }

    // dp table calculation
    for(int j=1 ; j<=lim ; j++){
        dp[j-1][j] = pre_tail[j];
        for(int i=j ; i<n ; i++){
            dp[i][j] = (1-p[i])*dp[i-1][j-1] + p[i]*dp[i-1][j];
        }
    }

    ld ans = 0;
    for(int j=0 ; j<=lim ; j++){
        ans += dp[n-1][j];
    }

    cout << setprecision(20) << ans << endl;

    return 0;
}