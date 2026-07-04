class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // We use a stack to keep track of the indices of the histogram bars.
        // We maintain the stack in an increasing order of heights. 
        // This helps us find the "previous smaller element" and 
        // "next smaller element" for any given bar, which defines its width.
        stack<int> s;
        int max_area = 0;
        int n = heights.size();

        // We iterate through the histogram bars.
        // We go up to n (inclusive) to handle the remaining elements in the stack
        // at the end of the loop by treating index 'n' as a bar of height 0.
        for (int i = 0; i <= n; i++) {
            
            // If i == n, we use height 0 to force the stack to empty out,
            // effectively calculating the area for all remaining bars in the stack.
            int current_height = (i == n) ? 0 : heights[i];

            // While the current bar is shorter than the bar at the top of the stack,
            // it means the rectangle with the height of the stack's top bar ends here.
            // We pop it and calculate its area.
            while (!s.empty() && current_height < heights[s.top()]) {
                
                // The height of the rectangle is the height of the bar at the popped index.
                int height = heights[s.top()];
                s.pop();

                // To find the width:
                // The right boundary is the current index 'i' (where we found a shorter bar).
                // The left boundary is the new top of the stack (the index of the 
                // first bar to the left that is smaller than the popped bar).
                // If the stack is empty, it means the popped bar was the smallest so far,
                // so the width spans from the beginning (index 0).
                int width = s.empty() ? i : (i - s.top() - 1);

                // Calculate area and update max_area if this one is larger.
                max_area = max(max_area, height * width);
            }

            // Push the current index onto the stack as a potential start for a rectangle.
            s.push(i);
        }

        return max_area;
    }
};
