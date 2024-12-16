#include <iostream>
#define int long long
using namespace std;

bool is_prime(int n){
    if(n == 1) return false;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}

int32_t main(){
    int n,m;cin >> n >> m;
    int sura = n; int berat = 0;
    while(n--){
        int x;cin >> x;
        for (int i = 0; i <= m; i++)
        {
            if(is_prime(i+x)){
                berat += 1;
                sura -= 1;
                break;
            }
        }
    }
    if (sura < berat) cout << "Berat" <<endl<<berat << endl;
    else cout << "Sura" <<endl<<sura << endl;
}