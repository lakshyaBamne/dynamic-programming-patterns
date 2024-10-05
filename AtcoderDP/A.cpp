/*
    A. Frog-1 -> https://atcoder.jp/contests/dp/tasks/dp_a
*/

#include<iostream>
#include<vector>

using namespace std;

int main(){
    int N, temp;
    cin >> N;

    vector<int> h;
    for(int i=0 ; i<N ; i++){
        cin >> temp;

        h.push_back(temp);
    }

    vector<int> min_cost(N, 0);

    min_cost[1] = abs(h[1]-h[0]);

    for(int i=2 ; i<N ; i++){
        min_cost[i] = min(
            min_cost[i-1] + abs(h[i]-h[i-1]),
            min_cost[i-2] + abs(h[i]-h[i-2])
        );
    }

    cout << min_cost.back() << endl;

}

