class Solution {
public:
    int helper(vector<int>&arr2,int num)
    {
        int low=0;
        int high=arr2.size()-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(arr2[mid]==num){return 0;}
            else if(arr2[mid]>num){high=mid-1;}
            else{low=mid+1;}
        }
        if(low<arr2.size() && high>=0)
        return min(abs(arr2[low]-num),abs(arr2[high]-num));
        else if(low>=arr2.size()){return abs(arr2[high]-num);}
        else{return abs(arr2[low]-num);}
    }
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(),arr2.end());
        int ans=0;
        for(int i=0;i<arr1.size();i++)
        {
            if(helper(arr2,arr1[i])>d){ans+=1;}
        }
        return ans;
    }
};