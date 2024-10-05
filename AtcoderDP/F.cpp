/*
    F. LCS -> https://atcoder.jp/contests/dp/tasks/dp_f
*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

string longestCommonSubsequence(string s1, string s2) {
    int n1 = s1.size();
    int n2 = s2.size();

    vector< vector<int> > dp(n1, vector<int>(n2, 0));

    // initial calculations
    dp[n1-1][n2-1] = s1[n1-1] == s2[n2-1] ? 1 : 0;

    // last column
    for(int i=n1-2 ; i>=0 ; i--){
        dp[i][n2-1] = s1[i]==s2[n2-1] || dp[i+1][n2-1]==1 ? 1 : 0;
    }

    // last row
    for(int j=n2-2 ; j>=0 ; j--){
        dp[n1-1][j] = s1[n1-1]==s2[j] || dp[n1-1][j+1]==1 ? 1 : 0;
    }

    // dp table calculations
    for(int i=n1-2 ; i>=0 ; i--){
        for(int j=n2-2 ; j>=0 ; j--){

            if(s1[i] == s2[j]){
                dp[i][j] = max(1+dp[i+1][j+1], max(dp[i+1][j], dp[i][j+1]));
            }
            else{
                dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
            }
        }
    }

    // to construct the lcs we backtrack from the top
    string lcs = "";
    int i=0;
    int j=0;
    while(i<n1-1 && j<n2-1){
        if(s1[i] == s2[j]){
            lcs += s1[i];
            i++;
            j++;
        }
        else{
            if(dp[i+1][j] >= dp[i][j+1]){
                i++;
            }
            else{
                j++;
            }
        }
    }

    while(i<n1 && j<n2){
        if(s1[i] == s2[j]){
            lcs += s1[i];

            j = n2;
            break;
        }
        else{
            j++;
        }
    }

    while(j<n2 && i<n1){
        if(s1[i] == s2[j]){
            lcs += s1[i];

            i = n1;
            break;
        }
        else{
            i++;
        }
    }

    return lcs;
}

int main(){
    string s,t;
    cin >> s >> t;

    cout << longestCommonSubsequence(s, t) << endl;

    return 0;
}

