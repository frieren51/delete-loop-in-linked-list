//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

 class Solution {
  public:
    // Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int> &arr, int target) {
        int n = arr.size();
        // Get the size of the array

        int last = 0;
        int start = 0;
        unsigned long long currsum = 0;
        bool flag = false;
        vector<int> res;

        // Iterating over the array.
        for (int i = 0; i < n; i++) {
            // Storing sum up to current element.
            currsum += arr[i];

            // Checking if current sum is greater than or equal to the target number.
            while (currsum >= target) {
                // If current sum becomes equal to target, we store
                // the starting and ending index for the subarray.
                if (currsum == target) {
                    res.push_back(start + 1);
                    // +1 for 1-based indexing

                    res.push_back(i + 1);
                    // +1 for 1-based indexing

                    flag = true;
                    break;
                }
                // Subtracting the element from the left (arr[start])
                currsum -= arr[start];
                start++;
            }

            // Break if subarray is found
            if (flag)
                break;
        }

        // If no subarray is found, we store -1 in the result.
        if (!flag)
            res.push_back(-1);

        // Returning the result.
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t
    while (t--) {
        vector<int> arr;
        int d;
        string input;

        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore(); // Ignore the newline character after d

        Solution ob;
        vector<int> result = ob.subarraySum(arr, d);
        for (int i : result) {
            cout << i << " ";
        }
        cout << "\n~\n";
    }
    return 0;
}

// } Driver Code Ends