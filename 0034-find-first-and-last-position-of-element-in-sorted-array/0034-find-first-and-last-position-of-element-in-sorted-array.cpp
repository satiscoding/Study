class Solution {
public:
    int findfirst(vector<int>& arr,int x) {
        int low = 0 ,high = arr.size() - 1;
        int result = - 1;

        while (low <= high) {
           int mid = low + (high - low) / 2;

            if (arr[mid] == x){
                result = mid;
                high = mid - 1;
            } else if (arr[mid] < x){
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return result;
    }
    int findlast(vector<int>& arr,int x) {
        int low = 0, high = arr.size() - 1;
        int result = - 1;

        while (low <= high){
          int  mid = low + (high - low) / 2;

            if (arr[mid] == x){
                result = mid;
                low = mid + 1;
            } else if (arr[mid] < x){
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return result;
    }
    vector<int> searchRange(vector<int>& arr, int x) {
        int first = findfirst(arr,x);
        int last = findlast(arr,x);

        return {first, last};
    }
};