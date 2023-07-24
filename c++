class Solution {
public:
    int minSwap(int arr[], int n, int k) {
        int good = 0; // Count of elements less than or equal to k
        int bad = 0;  // Count of elements greater than k
        
        for (int i = 0; i < n; i++) {
            if (arr[i] <= k)
                good++;
        }
        
        for (int i = 0; i < good; i++) {
            if (arr[i] > k)
                bad++;
        }
        
        int i = 0;
        int j = good;
        int ans = bad;
        
        while (j < n) {
            if (arr[i] > k)
                bad--;
            
            if (arr[j] > k)
                bad++;
            
            // Update ans
            ans = std::min(ans, bad);
            i++;
            j++;
        }
        
        return ans;
    }
};
