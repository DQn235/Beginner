#include <bits/stdc++.h>

using namespace std;
int cnt[1000001];//mang dem
int main()
{
    int tc; cin>>tc;
    while(tc--){
        int n; cin>>n;
        int a[n], max_val = -100000000;

        for(int i=0;i<n;i++){
            cin >> a[i];  cnt[a[i]]++;
            if(a[i] > max_val){
              max_val = a[i];
           }
        }
        for(int i=0; i <= max_val; i++){
            if(cnt[i]>=1)
                cout<<i<<" xuat hien "<<cnt[i]<<" lan\n";
        }

    }
    return 0;
}
