
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > graph;

int returnNextEmptySlot(vector<bool> vec, int start){
    for(int i = start; i < vec.size(); i++){
        if(vec[i] == 0)
            return i;
    }
    return -1;
}

int getNextXValue(int x, int size){
    if(x + 1 >= size)
        return 0;
    return x + 1;
}

int returnMax(vector<bool> usedRows, vector<bool> usedCols, int thisX, int thisY, int previousScore){
    if(thisX >= usedRows.size() || thisY >= usedCols.size())
        return previousScore;
    if(returnNextEmptySlot(usedRows, 0) == -1)
        return previousScore;
    
    int maxScore = 0;
    int x = returnNextEmptySlot(usedRows, thisX);
    int y = returnNextEmptySlot(usedCols, thisY);
    //Find next x and y to search in later iterations
    int xNext = getNextXValue(x, usedRows.size());
    int yNext = y;
    if(xNext == 0)
        yNext++;
    //cout << "thisX: " << thisX << endl;    
    //cout << "x: " << x << endl;
    //cout << "xNext: " << xNext << endl;
    
    if(x == -1 || y == -1){
        maxScore = returnMax(usedRows, usedCols, xNext, yNext, previousScore);
    }
    else if(xNext == 0){
        int thisScoreSoFar = previousScore + graph[thisX][thisY];
        usedRows[thisX] = 1; usedCols[thisY] = 1;
        maxScore = returnMax(usedRows, usedCols, xNext, yNext, thisScoreSoFar);
    }
    else{
        int moveWithoutScore = returnMax(usedRows, usedCols, xNext, yNext, previousScore);
        int thisScoreSoFar = previousScore + graph[thisX][thisY];
        usedRows[x] = 1; usedCols[y] = 1;
        maxScore = max(moveWithoutScore, returnMax(usedRows, usedCols, xNext, yNext, thisScoreSoFar));
    }

    return maxScore;
}

int main() {
    int n; cin >> n;
    graph = vector<vector<int>>(n, vector<int>(n, 0));
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> graph[i][j];
    
    int curbYourGreedScore = returnMax(vector<bool>(n, 0), vector<bool>(n, 0), 0, 0, 0);
    cout << curbYourGreedScore;
    return curbYourGreedScore;
}