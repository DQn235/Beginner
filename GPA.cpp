#include <bits/stdc++.h>

using namespace std;
float diem(float d,int tc)
{
    if(d<4)return 0;
    if(d>=4   && d<=4.7) return tc;
    if(d>=4.8 && d<=5.4) return tc*1.5;
    if(d>=5.5 && d<=6.2) return tc*2;
    if(d>=6.3 && d<=6.9) return tc*2.5;
    if(d>=7   && d<=7.7) return tc*3;
    if(d>=7.8 && d<=8.4) return tc*3.5;
    if(d>=8.5 && d<=8.9) return tc*3.8;
    if(d>=9   && d<=10)  return tc*4;



}
int main()
{
    int n,t=0,tc[100];
    float score[100],d=0;
    cin>>n;
    for(int i=0;i<n;i++)  cin>>score[i]>>tc[i];

    for(int i=0;i<n;i++)
    {
        t+=tc[i];
        d+=diem(score[i],tc[i]);
    }
    cout<<fixed<<setprecision(2)<<d/t;
    return 0;
}
/*
10
6.3 2
5 3
6.9 3
5.4 3
6.7 3
7.1 2
6.3 2
6.1 2
6.8 3
7.2 3
*/
