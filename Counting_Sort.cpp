#include <iostream>
#include <vector>

void countingSort(std::vector<int>& arr, int maxValue) {

    std::vector<int> count(maxValue + 1, 0);
    for (int num : arr) {
        count[num]++;
    }
    int index = 0;
    for (int i = 0; i <= maxValue; ++i) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }
}

int main() {
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    std::vector<int> arr(n);
    int maxValue = 0;

    std::cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
        if (arr[i] > maxValue) {
            maxValue = arr[i];
        }
    }

    countingSort(arr, maxValue);

    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
