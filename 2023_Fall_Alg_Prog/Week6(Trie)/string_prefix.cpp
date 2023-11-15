#include <iostream>
#include <map>
using namespace std;

struct Node{
    int visit=0;
    map<char,int> child;
};

Node nodes[10000000];
int last_index = 2;

void insert(string s){
    int current_node = 1;
    for(char c: s){
        if(nodes[current_node].child.count(c)==0)  nodes[current_node].child[c] = last_index++;
        current_node = nodes[current_node].child[c];
        nodes[current_node].visit++;
    }
}

int search(string s){
    int current_node = 1;
    for(char c:s){
        if(nodes[current_node].child[c]==0) return 0;
        current_node=nodes[current_node].child[c];
    }
    return nodes[current_node].visit;
}

int32_t main(){
    int n,q;cin>>n>>q;
    while(n--){
        string s; cin>>s;
        insert(s);
    }

    while(q--){
        string s; cin>>s;
        cout<<search(s)<<endl;
    }

    return 0;
}
