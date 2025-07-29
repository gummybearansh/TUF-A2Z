// buy and sell stock
#include <iostream>
#include <vector>

using namespace std;


void buyAndSellStockOptimal(vector<int> v){
    // calculate lowest (before current) 
    // calculate cost (price - lowestPriceBefore)
    int n = v.size(), cost = 0, lowest = v[0], maxProfit = 0;
    for (int i = 1; i < n; i++){
        cost = v[i] - lowest;
        if (cost > maxProfit) maxProfit = cost;
        if (v[i] < lowest) lowest = v[i];
    }
    cout << maxProfit << endl;
}

// calculate each pair of valid buy and sell
void buyAndSellStockBrute(vector<int> v){
    int n = v.size(), maxProfit = 0;
    for (int i = 1; i < n; i++){
        int profit = 0;
        for (int j = i+1; j < n; j++){
            profit = v[j] - v[i];
            if (profit > maxProfit) maxProfit = profit;
        }
    }
    cout << maxProfit << endl;
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    // buyAndSellStockOptimal(v);
    buyAndSellStockBrute(v);
}
