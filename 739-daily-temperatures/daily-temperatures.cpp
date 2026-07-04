class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // We create an 'answer' vector of the same size as 'temperatures', 
        // initialized to 0. If we never find a warmer day for a specific index, 
        // it will remain 0 by default.
        int n = temperatures.size();
        vector<int> answer(n, 0);

        // We use a stack to store the indices of the days.
        // This stack will be "monotonic," meaning the temperatures corresponding 
        // to the indices in the stack will be in non-increasing order.
        stack<int> indices;

        // Iterate through each day in the temperatures array
        for (int i = 0; i < n; ++i) {
            
            // While the stack is not empty AND the current day's temperature is 
            // strictly warmer than the temperature at the index stored at the 
            // top of the stack:
            // This condition means we have found a warmer day for the 'past' day!
            while (!indices.empty() && temperatures[i] > temperatures[indices.top()]) {
                
                // Get the index of the past day that we are waiting for
                int pastIndex = indices.top();
                indices.pop(); // Remove it from the stack as it's now solved

                // The answer for that past day is the current day index (i) 
                // minus the past day index (pastIndex).
                answer[pastIndex] = i - pastIndex;
            }

            // Push the current day index onto the stack. We do this for every day, 
            // because this day might be the "past day" for some future warmer day.
            indices.push(i);
        }

        // Return the final result array where each index holds the number of days 
        // waited, or 0 if no warmer day was found.
        return answer;
    }
};
