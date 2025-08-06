string justify(vector<string>& container,int containerSize,int len){

    // extra spaces  must be divided evenly len/(containerSize-1)
    // if there is one entry EDGE CASE -> len spaces
    // beside that let their be x+1 words and y len
    // then every space gets y/x and
    // extra_lefts gets 1 from y-y/x*x if exists

    string result = "";

    //edgecase
    if(containerSize == 1){
        result = container[0];
        while(len--) result = result + " ";
        return result;
    }

    int extra_space = len/(containerSize-1);
    int extra_extra_left_space = len - extra_space*(containerSize-1);

    int i = 0;
    while(i<containerSize-1){
        result += container[i] + " ";
        for(int j = 0;j<extra_space;j++) result+= " ";
        if(extra_extra_left_space-- > 0) result += " ";
        i++;
    }
    result += container[i];

    return result;
}



class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        vector<string> container(110,"");
        int containerSize = 0;
        int len = maxWidth;

        for(string s : words){
            if( (int) s.length() <= len ){


                // we can add the container
                container[containerSize] = s;
                containerSize++;
                len = len - s.length() - 1;
            }
            else{
                // we will justify the container

                result.push_back(
                    justify(container,containerSize,len+1)
                );
                // reset the container
                containerSize = 0;
                len = maxWidth;

                // handle first case since
                // s.length() < len is must
                container[containerSize] = s;
                containerSize++;
                len = len - s.length() - 1;
            }
        }


        // handle last case
        string temp_result = "";
        int i = -1;
        while(++i<containerSize){
            temp_result += container[i];
            if(i<containerSize-1)
                temp_result+= " ";
        }

        while(temp_result.length()<maxWidth) temp_result+= " ";
        result.push_back(temp_result);

        return result;
    }
};