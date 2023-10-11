#include <iostream>
#include "StringData.h"
#include <string>
#include <ctime>
using namespace std;

int linear_search(vector<string> dataset, string element);
int binary_search(vector<string> dataset, string element);

int main() {
    vector<string> dataset;
    dataset = getStringData();
    string tests[3] = {"not_here", "mzzzz", "aaaaa"};
    int before = -1;
    int after = -1;
    int x = -1;
    for (int i = 0; i < 3; i ++) {
        time_t current_time;
        before = time(NULL);
        x = linear_search(dataset, tests[i]);
        after = time(NULL);
        cout << "\nThe time taken to find \"" << tests[i] << "\" using linear search is" << after - before << "seconds.";
        cout << "The index is" << x;
        before = time(NULL);
        x = binary_search(dataset, tests[i]);
        after = time(NULL);
        cout << "\nThe time taken to find \"" << tests[i] << "\" using binary search is" << after - before << "seconds.";
        cout << "The index is" << x;
    }
    return 0;
}

int linear_search(vector<string> dataset, string element){
    for(int i = 0; i < 11881376; i++) {
        if (dataset[i] == element) {
            return i;
        }
    }
}

int binary_search(vector<string> dataset, string element) {
    int beginning = 0;
    int end = 11881376 - 1;
    int mid = -1;
    while (beginning <= end) {
        mid = int((beginning + end) / 2);
        if (dataset[mid] < element) {
            beginning = mid + 1;
        }
        else if (dataset[mid] > element) {
            end = mid - 1;
        }
        else{
            return mid;
        }
    }
    return -1;
}