#include <iostream>
#include <vector>

using namespace std;


bool finder(char x){
    if(x =='a' || x=='e' || x=='i'|| x=='o' ||x=='u'){
        return true;
    }
    else{
        return false;
    }
}

int main(){

    string book;
    string key;
    cin>>book>>key;
    char frst = key[0];
    int keyLen = key.size();
    int bookLen = book.size();

    //Clearing the input:
    int i=1;
    while(i<bookLen){
        if(book[i]==book[i-1]){
            if(finder(book[i])){
                book.erase(book.begin() + i);
                bookLen-=1;
                i-=1;
            }
        }
    i++;
    }
    i=1;
    while(i<keyLen){
        if(key[i]==key[i-1]){
            if(finder(key[i])){
                key.erase(key.begin() + i);
                keyLen-=1;
                i-=1;
            }
        }
    i++;
    }

    //Searching

    for(int counter = 0;counter<bookLen;counter++){
        if(book[counter]==frst){
            for(int inner=1;inner<keyLen;inner++){
                if(key[inner]!=book[inner+counter]){
                    break;
                }else if(inner==keyLen-1){
                    cout<<"yes"<<endl;
                    return 0;
                }
            }
        }
    }

    cout<<"no"<<endl;
    return 0;
}