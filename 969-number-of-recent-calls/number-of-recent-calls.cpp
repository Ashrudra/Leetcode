class RecentCounter {
private:
    // Queue to store the timestamps of the requests
    std::queue<int> requests;

public:
    // Constructor: Initializes the RecentCounter object
    RecentCounter() {
        // No initialization needed as queue is empty by default
    }

    // Method to add a new request at time t and return the number of requests
    // that have happened in the last 3000 milliseconds (inclusive)
    int ping(int t) {
        // Add the new request timestamp to the queue
        requests.push(t);

        // Remove all requests that are older than t - 3000 milliseconds
        // Because only requests in the range [t-3000, t] are considered recent
        while (!requests.empty() && requests.front() < t - 3000) {
            requests.pop();
        }

        // The size of the queue now represents the number of recent requests
        return requests.size();
    }
};


