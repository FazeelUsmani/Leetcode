#include<bits/stdc++h>
using namespace std;
  
int change(int amount, vector<int>  coins){
    
    int ways[amount+1];
    ways[0] = 1;
    
    for (int coin : coins){
        for (int i = coin; i <= amount; ++i){
            ways[i] += ways[i-coin];
        }
    }
    
    return ways[amout];  
  }
