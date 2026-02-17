class Solution {
  public:

    bool canPlace(vector<int> &stalls, int k, int distance)
    {
        int count = 1;
        int lastPosition = stalls[0];

        for(int i = 1; i < stalls.size(); i++)
        {
            if(stalls[i] - lastPosition >= distance)
            {
                count++;
                lastPosition = stalls[i];
            }

            if(count >= k)
                return true;
        }

        return false;
    }

    int aggressiveCows(vector<int> &stalls, int k) 
    {
        sort(stalls.begin(), stalls.end());

        int low = 1;
        int high = stalls.back() - stalls.front();
        int answer = 0;

        while(low <= high)
        {
            int mid = (low + high) / 2;

            if(canPlace(stalls, k, mid))
            {
                answer = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return answer;
    }
};
