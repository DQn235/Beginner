#include <bits/stdc++.h>

using namespace std;
int cnt[1000001];//mang dem
int main()
{
    int tc; cin>>tc; //testcase
    while(tc--)
    {
        int n; cin>>n;
        int a[n];
        //memset(cnt,0,sizeof(cnt));//set mang ->0
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            cnt[a[i]]++;
        }
        int dem=0;
        for(int i=1;i<=n;i++)
        {
            if(cnt[a[i]]>1)dem++;
        }
            cout<<dem;

    }
    return 0;
}
