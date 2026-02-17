class Solution {
  public:
  
    bool canPaint(vector<int>& arr, int k, long long maxTime)
    {
        long long currentSum = 0;
        int painters = 1;
        
        for(int i = 0; i < arr.size(); i++)
        {
            if(currentSum + arr[i] <= maxTime)
            {
                currentSum += arr[i];
            }
            else
            {
                painters++;
                currentSum = arr[i];
                
                if(painters > k)
                    return false;
            }
        }
        
        return true;
    }
  
    int minTime(vector<int>& arr, int k) 
    {
        long long low = *max_element(arr.begin(), arr.end());
        long long high = 0;
        
        for(int i = 0; i < arr.size(); i++)
            high += arr[i];
        
        long long answer = high;
        
        while(low <= high)
        {
            long long mid = low + (high - low) / 2;
            
            if(canPaint(arr, k, mid))
            {
                answer = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        
        return answer;
    }
};
