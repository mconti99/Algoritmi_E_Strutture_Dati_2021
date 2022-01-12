#include <iostream>
#include <cmath>
#include <iomanip>
#include <bits/stdc++.h>
using namespace std;

double f(double x, double p, double q, double r, double s, double t, double u){
    return p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    double p,q, r,s,t,u;
    while(cin>>p>>q>>r>>s>>t>>u){
        //metodo della bisezione
        //f(0)=1, f(1)=-1
        
        double U=1.0, L=0.0;
        while(U-L>=1e-9){
            double m=(L+U)/2.0;
            double value=f(m,p,q,r,s,t,u);
            if(value<0) U=m;
            else L=m;
        }
        if(abs(f((L+U)/2,p,q,r,s,t,u))<=1e-4)
            cout << setprecision(4) << fixed << (L+U)/2.0 << "\n";
        else cout << "No solution" << "\n";
    }

	return 0;
}
