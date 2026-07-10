class Solution {
public:
    bool judgeCircle(std::string moves) {
        // need to track the robot's position on a 2D plane.
        // x represent horizontal movement (Right+, Left-)
        // y represent vertical movement (Up+, Down-)
        int x = 0;
        int y = 0;
        
        // Iterate through each move in the string
        for (char move : moves) {
            if (move == 'U') {
                // Moving Up increases the y-coordinate
                y++;
            } else if (move == 'D') {
                // Moving Down decreases the y-coordinate
                y--;
            } else if (move == 'R') {
                // Moving Right increases the x-coordinate
                x++;
            } else if (move == 'L') {
                // Moving Left decreases the x-coordinate
                x--;
            }
        }
        
        // If the robot is back at the origin, both x and y should be 0.
        return (x == 0 && y == 0);
    }
};
