#include <iostream>
#include <vector>
#define int long long
using namespace std;


class UnionFind {
private:
    std::vector<int> parent;
    std::vector<int> rank;

public:
    UnionFind(int size) {
        parent.resize(size);
        rank.resize(size, 0);
        for (int i = 0; i < size; ++i) {
            parent[i] = i;  // Each element is initially its own representative
        }
    }

    int get_rank(int x){
        return rank[x];
    }
    int get_parent(int x){
        return parent[x];
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // Path compression
        }
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            // Union by rank heuristic
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootX] = rootY;
                rank[rootY]++;
            }
        }
    }
};

void dfs(const vector<vector<int> > &graph){

}


int main() {
    int T;cin>>T;
    while(T--)
    {

        int R,C;cin>>R>>C;


    }

    return 0;
}
