#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int32_t main(){
    int n,k; cin>>n>>k;
    vector<int> stockPrizes(n,0);
    for (int i = 0; i < n; i++) cin >> stockPrizes[i];
    double sumGainsDP = 0;
    double sumLossesDP = 0;

    for (int i = 1; i < k-1; i++)
    {
        sumGainsDP += max(0,stockPrizes[i]-stockPrizes[i-1]);
        sumLossesDP += max(0,stockPrizes[i-1]-stockPrizes[i]);
    }

    for(int m = k-1; m < n; m++){
        sumGainsDP += max(0,stockPrizes[m]-stockPrizes[m-1]);
        sumLossesDP += max(0,stockPrizes[m-1]-stockPrizes[m]);

        if(m-k+1>=1){
            sumGainsDP -= max(0,stockPrizes[m-k+1]-stockPrizes[m-k]);
            sumLossesDP -= max(0,stockPrizes[m-k]-stockPrizes[m-k+1]);
        }


        if(sumGainsDP + sumLossesDP == 0){
            cout<<"0 1\n";
            continue;
        }

        double dmi = (100*sumGainsDP)/(sumGainsDP + sumLossesDP);
        
        
        cout <<fixed << setprecision(1) <<dmi << " ";
        if(dmi<35) cout<<1;
        else if(dmi>65) cout<<2;
        else cout<<0;

        cout<<"\n";
    }
    


}