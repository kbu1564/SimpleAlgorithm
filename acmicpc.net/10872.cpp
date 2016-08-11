#include<iostream>
int N;int fact(int n){return n<2?1:fact(n-1)*n;}main(){std::cin>>N;std::cout<<fact(N);}
