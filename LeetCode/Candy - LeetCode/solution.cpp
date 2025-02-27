class Solution {
public:
    int candy(vector<int>& ratings) {
        int i = 0;
        int n = ratings.size();

        if(n == 1) return 1;

        vector<int> res(n,1);
        vector<pair<int,int> > arr;
        vector<bool> visited(n,false);
        for(int r : ratings) arr.push_back({r,i++});
        sort(arr.begin(),arr.end());

        for(auto p : arr){
            int rating = p.first;
            int index =  p.second;

            if(index == n-1){
                if(visited[index-1] && rating > ratings[index-1])
                    res[index] = res[index-1] + 1;
                else res[index] = 1;
                visited[index] = true;
                continue;
            }

            if(index == 0){
                if(visited[1] && rating > ratings[1])
                    res[0] = res[1] + 1;
                else res[0] = 1;
                visited[index] = true;
                continue;
            }

            if(visited[index + 1] && visited[index-1]){
                if(rating == ratings[index-1] && rating == ratings[index+1])
                res[index] = 1;
                else if(rating == ratings[index-1])
                res[index] = res[index+1] + 1;
                else if(rating == ratings[index+1])
                res[index] = res[index-1] + 1;
                else res[index] = max(res[index-1],res[index+1]) + 1;

                visited[index] = true;
                continue;
            }

            if(visited[index + 1]){
                if(ratings[index-1] > rating && rating > ratings[index+1])
                res[index] = res[index+1] + 1;
                else if(ratings[index-1] > rating && rating == ratings[index+1])
                res[index] = 1;
                else if(ratings[index-1] == rating && rating > ratings[index+1])
                res[index] = res[index+1] + 1;
                else res[index] = 1;

                visited[index] = true;
                continue;
            }

            if(visited[index - 1]){
                if(ratings[index-1] < rating && rating < ratings[index+1])
                res[index] = res[index-1] + 1;
                else if(ratings[index-1] < rating && rating == ratings[index+1])
                res[index] = res[index-1] + 1;
                else if(ratings[index-1] == rating && rating < ratings[index+1])
                res[index] = 1;
                else res[index] = 1;

                visited[index] = true;
                continue;
            }

            res[index] = 1;
            visited[index] = true;
            continue; 
        }
        

        int sum = 0;
        for(int x : res) sum+= x;

        return sum;
        
    }
};