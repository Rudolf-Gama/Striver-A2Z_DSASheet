#include<bits/stdc++.h>
using namespace std;

// A structure to represent a job
struct Job {
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

// Comparator function to sort jobs according to profit in descending order
static bool comp(Job a, Job b) {
    return a.profit > b.profit;
}

vector<int> JobScheduling(Job arr[], int n) {
    // Sort jobs according to their profit in descending order
    sort(arr, arr + n, comp);

    // Find the maximum deadline
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        maxDeadline = max(maxDeadline, arr[i].dead);
    }

    // Create a slot array to keep track of free time slots
    vector<int> slot(maxDeadline + 1, -1);

    // Initialize the count of jobs and total profit
    int countJobs = 0, totalProfit = 0;

    // Iterate through all given jobs
    for (int i = 0; i < n; i++) {
        // Find a free slot for this job (starting from its deadline)
        for (int j = arr[i].dead; j > 0; j--) {
            // If the slot is free
            if (slot[j] == -1) {
                slot[j] = arr[i].id; // Assign the job to this slot
                countJobs++;         // Increment the count of jobs
                totalProfit += arr[i].profit; // Add profit
                break;               // Break the loop once the job is assigned
            }
        }
    }

    return {countJobs, totalProfit};
}

int main() {
    Job arr[] = {{6, 2, 80}, {3, 6, 70}, {4, 6, 65}, {2, 5, 60}, 
                 {5, 4, 25}, {8, 2, 22}, {1, 4, 20}, {7, 2, 10}};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> result = JobScheduling(arr, n);
    cout << "Number of jobs scheduled: " << result[0] << endl;
    cout << "Total profit: " << result[1] << endl;
    return 0;
}