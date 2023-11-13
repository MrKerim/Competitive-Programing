    // It took me a lot of time to realize that however:
    // We are axrually burute forcing
    // Meaning we are looking all the possible subsets of the array
    // which is 2 to the power of n and has the same complexity of O(2^n)
    // That's why this porblem is not good for brute force

#include <iostream>
#include <vector>
using namespace std;


long long divide_sum(int x, long long greedy_sum){

    greedy_sum = greedy_sum - x;

    //cout statements
    cout<<"Test: divide sum x: "<<x<<" Greedy: "<<greedy_sum<<endl;


    if(greedy_sum < 0 || x < 1){
        return 0;

        //cout
        cout<<"first if executed for x: "<<x<<"and Greedy: "<<greedy_sum<<endl;
    }
    else if (greedy_sum == 0){
        //cout
        cout<<"Second if executed for x: "<<x<<"and Greedy:"<<greedy_sum <<endl;
        return 1;
    }
    else{
        cout<<"Third if executed for x: "<<x<<"and Greedy:"<<greedy_sum <<endl;
        long long res = 0;
        for(int temp= x-1;temp >0;temp-=1){
            res = (res + divide_sum(temp,greedy_sum))%(1000000007);
        }

        return res;
    }
    


}


int main(){

 



    int n;     
    cin>> n;
    if((n*(n+1)/2)%2){
        cout<<0<<endl;
        return 0;
        }

    else{
    
    // Here we write the program:
    // We need to use greedy algorithm in order to that we need to find the total

    long long sum_of_numbers = n*(n+1)/4;
 
    long long result = 0;
    for (int output_counter =n;output_counter>(n/2);output_counter-=1){
        result+= divide_sum(output_counter,sum_of_numbers);
    }
    cout<<result<<endl;



    }
    
}