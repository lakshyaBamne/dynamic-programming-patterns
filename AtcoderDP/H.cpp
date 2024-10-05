#include<iostream>
#include<vector>

using namespace std;

int main(){
    int m = 1E9 + 7;

    int h, w;
    cin >> h >> w;

    vector< vector<char> > grid(h, vector<char>(w));
    for(int i=0 ; i<h ; i++){
        for(int j=0 ; j<w ; j++){
            cin >> grid[i][j];
        }
    }

    vector< vector<int> > dp(h, vector<int>(w, 0));
    
    dp[0][0] = 1;

    for(int i=1 ; i<h ; i++){
        if(grid[i][0] == '.'){
            dp[i][0] = 1;
        }
        else{
            break;
        }
    }

    for(int j=1 ; j<w ; j++){
        if(grid[0][j] == '.'){
            dp[0][j] = 1;
        }
        else{
            break;
        }
    }

    // dp table calculation
    for(int i=1 ; i<h ; i++){
        for(int j=1 ; j<w ; j++){
            if(grid[i][j] != '#'){
                dp[i][j] = (dp[i-1][j] + dp[i][j-1])%m;
            }
        }
    }

    cout << dp[h-1][w-1] << endl;

    return 0;
}