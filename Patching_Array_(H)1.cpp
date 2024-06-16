class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int count=0;
        int sum=0;
        long long last=0;
       for(int i=0;i<nums.size();i++){
           if(nums[i]-last<=1) {
            last=nums[i]+last;
            continue;
           }

           if(last>=n) return count;

           int val=last+1;
           while(nums[i]-last>1){
                count++;
                last=last+val;
                val=last+1;
                if(nums[i]-last<=1 && nums[i]+last>=n || n-last<=0) return count;
           }
           
        //    if(last>=n) return count;

           last=last+nums[i];


       }

       while(last<n){
          count++;
          last=2*last+1;
       }
       
       return count;
    }
};