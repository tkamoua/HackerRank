class Solution {
public:
    //
    //loop through each substring of searword (with start at idnex 0)
    //loop through products, if products[0:index] = searchword[0:index]
    // add to output list
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        vector<vector<string>> output;
        for(int i = 0; i < searchWord.length();++i){
            vector<string> inner;
            auto it = lower_bound(products.begin(),products.end(),searchWord.substr(0,i+1));

                while(it != products.end() && (*it).substr(0,i+1) == searchWord.substr(0,i+1)){
                    inner.push_back(*it);
                    if(inner.size()==3){
                        break;
                    }
                    it = it+1;
                }
            
           
            
            output.push_back(inner);
        }
        return output;
    }
};