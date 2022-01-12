#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int T, i, j;
    cin>>T;
    while(T--){
        int N,P,W,G,MW, ans=0;
        int dp[31]={};
        cin>>N;
        for(i=0;i<N;i++){
            cin>>P>>W;
            for(j=30;j>=W;j--) 
                if(dp[j]<dp[j-W]+P)
                    dp[j]=dp[j-W]+P;//mantengo l'informazione del valore
        }
        cin>>G;
        while(G--){
            cin>>MW;
            ans+=dp[MW];
        }
        cout << ans << "\n";
    }

	return 0;
}
