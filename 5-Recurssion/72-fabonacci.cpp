#include<iostream>
using namespace std;
//BY ITERATION
int fib(int n){
    int t0=0,t1=1,s=0,i;
    if(n<=1){
        return n;
    }
    for(i=2;i<=n;i++){
        s=t0+t1;
        t0=t1;
        t1=s;

    }
    return s;
}
//BY RECURSION
int rfib(int n){
    if(n<=1)
    return n;
    else
    return rfib(n-2)+rfib(n-1);
}
//BY MEMOIZATION
int F[10];
int mfib(int n)
{
if(n<=1){
    return n;
}
else
if(F[n-2]==-1){
    F[n-2]=mfib(n-2);
}
if(F[n-1]==-1){
    F[n-1]=mfib(n-1);
}
return F[n-2]+F[n-1];
}

int main(){
    int f;
    for(f=0;f<10;f++){
        F[f]=-1;
    }
    int i,r,m;
    i=fib(5);
    r=rfib(5);
    m=mfib(5);
    cout<<i<<endl;
    cout<<r<<endl;
    cout<<m<<endl;
     return 0;
}