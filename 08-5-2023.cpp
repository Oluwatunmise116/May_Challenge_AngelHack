#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
    // Define the integer string
    string num_str = "1867";

    // Generate all permutations of the integer string
    vector<string> perms;
    sort(num_str.begin(), num_str.end());
    do {
        perms.push_back(num_str);
    } while (next_permutation(num_str.begin(), num_str.end()));

    // Check each permutation for divisibility by 7
    vector<int> divisible_perms;
    for (string perm : perms) {
        int num = stoi(perm);
        if (num % 7 == 0) {
            divisible_perms.push_back(num);
        }
    }

    // If there are no divisible permutations, print a message and exit
    if (divisible_perms.empty()) {
        cout << "No permutations are divisible by 7" << endl;
        return 0;
    }

    // Compute the average of the smallest and largest divisible permutations
    int smallest = *min_element(divisible_perms.begin(), divisible_perms.end());
    int largest = *max_element(divisible_perms.begin(), divisible_perms.end());
    double avg = static_cast<double>(smallest + largest) / 2;

    // Print the result
    cout << "The average of the smallest and largest divisible permutations is: " << avg << endl;

    return 0;
}
