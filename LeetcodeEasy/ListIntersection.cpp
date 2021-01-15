class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> nums1set;
        vector<int>output;
        for(int i = 0; i < nums1.size();++i){
            nums1set.insert(nums1[i]);
        }
        for(int i = 0; i < nums2.size();++i){
            auto it = nums1set.find(nums2[i]);
            if(it != nums1set.end()){
                output.push_back(nums2[i]);
                nums1set.erase(it);
            }
        }
          return output;
    }
  
};