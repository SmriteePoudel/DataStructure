#include <iostream>
#include <vector>
#include <numeric>  // For accumulate

// Function to calculate mean of the elements in the array list
double calculateMean(const std::vector<double>& data) {
    if (data.empty()) {
        return 0.0;
    }
    double sum = std::accumulate(data.begin(), data.end(), 0.0);
    return sum / data.size();
}

// Function to display elements of the array list
void displayData(const std::vector<double>& data) {
    std::cout << "Data: ";
    for (double val : data) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Creating an array list using vector
    std::vector<double> dataList;

    // Adding elements
    dataList.push_back(23.5);
    dataList.push_back(25.0);
    dataList.push_back(22.1);
    dataList.push_back(26.7);
    dataList.push_back(24.3);

    std::cout << "Initial Dataset:" << std::endl;
    displayData(dataList);

    // Calculating and displaying mean
    double mean = calculateMean(dataList);
    std::cout << "Mean of the dataset: " << mean << std::endl;

    // Removing the last element
    dataList.pop_back();
    std::cout << "After removing the last element:" << std::endl;
    displayData(dataList);

    // Inserting a new element at the beginning
    dataList.insert(dataList.begin(), 21.9);
    std::cout << "After inserting a new element at the beginning:" << std::endl;
    displayData(dataList);

    // Accessing a specific element
    std::cout << "Element at index 2: " << dataList[2] << std::endl;

    return 0;
}

