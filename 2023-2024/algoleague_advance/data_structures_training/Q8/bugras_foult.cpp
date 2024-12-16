#include <iostream>
#include <queue>
#define int long long
#define MOD 1000000007
using namespace std;

int get_number(queue<char> numbers){
    int result = 0;
    while (!numbers.empty())
    {
        result = ((result*10)%MOD + (numbers.front() - '0')%MOD)%MOD;
        numbers.pop();
    }
    return result;
}

int32_t main(){
    int n; cin>>n;
    string input; cin>>input; input += '+';
    // We will have several kinds of operations
    // If there is a number just push the number into the number stack
    // When there is a '*' operation we will take that number and multiply it with the multp
    // Whene there is + or - we will get the number or get the multipleied and push it to the final result then
    // We multiply multp by 1 or -1 in this way we can gurantee the sign and convinient to work while not knwoing the remaining array
 
    queue<char> number_queue;
    int current_number=0;
    int multiply=1;
    int result=0;

    for (int i = 0; i <= n; i++)
    {   
        char elem = input[i];

        if(elem != '+' && elem != '-' && elem != '*')number_queue.push(elem); 
        else if(elem != '*'){
            current_number = get_number(number_queue);
            while(!number_queue.empty()) number_queue.pop();
            multiply = ((multiply)%MOD*(current_number)%MOD)%MOD;
            current_number=0;
            result = (result%MOD + multiply%MOD)%MOD;
            if (elem=='+') multiply = 1; else multiply= -1;
        }
        else{
            current_number = get_number(number_queue);
            while(!number_queue.empty()) number_queue.pop();
            multiply = ((multiply)%MOD*(current_number)%MOD)%MOD;
            current_number = 0;
        }
    }

    cout<<(result+MOD)%MOD<<endl;

    

}