#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
int t;
int start, fine, n, f;
struct qujian{
    int start;
    int end;
};

qujian q[1000005], p[1000005];

int cmp(qujian a, qujian b){
    return a.end>b.end;
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>t;
    while(t--){
       n=0;
       f=0;
       start=0;
       cin>>fine;
       while(cin>>q[n].start && cin >> q[n].end && (q[n].start||q[n].end)){
           n++;
       }
       
       sort(q,q+n, cmp);
       while(start<fine){
           int i;
           for(i=0;i<n;i++){
               if(q[i].start <= start && q[i].end > start){
                   start=q[i].end; //aggiorno l'intervallo
                   p[f]=q[i];
                   f++;
                   break;
               }
           }
           if(i==n) break; //se non ci sono intervalli che incontrano le condizioni, finisce direttamente
       }
       if(start < fine) cout << "0\n";
       else{
           cout<< f << "\n" ;
           for(int i=0;i<f;i++) cout << p[i].start << " " << p[i].end << "\n";
       }
       if(t) cout << "\n";
       
    }
	return 0;
}
