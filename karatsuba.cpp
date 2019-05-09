#include<bits/stdc++.h>
using namespace std;


int karatsuba(int x, int y){
    int a,b,c,d;
    int n = ceil(log10(x));
    int n1 = ceil(log10(x));
    int n2 = ceil(log10(y));
    if(n1<=2 || n2<=2) return (x*y);
    a = x/pow(10,(n/2));
    b = fmod(x,pow(10,(n/2)));
    c = y/pow(10,(n/2));
    d = fmod(y,pow(10,(n/2)));
    int p1 = karatsuba(a,c);
    int p2 = karatsuba(b,d);
    int p3 = karatsuba(a+b,c+d);
    long p = (pow(10,n)*(p1)) + (pow(10,(n/2))*(p3-p1-p2)) + p2;
    return p;
}

int main(){
    int x,y;
    cin>>x>>y;
    // x=5678;
    long prod = karatsuba(x,y);
    cout<<prod<<endl;
    // int n = ceil(log10(x));
    // cout<<n<<endl;
    // int a = x/pow(10,(n/2));
    // double b = fmod(x,pow(10,(n/2)));
    // cout<<a<<" "<<b<<endl;
}