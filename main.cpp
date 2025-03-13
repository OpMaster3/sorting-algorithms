#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

// Function to print an array
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Bubble Sort
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Selection Sort
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

// Insertion Sort
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Merge Sort
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> leftArr(n1);
    vector<int> rightArr(n2);

    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        rightArr[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }

    while (i < n1) {
        arr[k++] = leftArr[i++];
    }

    while (j < n2) {
        arr[k++] = rightArr[j++];
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Quick Sort
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Shell Sort
void shellSort(vector<int>& arr) {
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int main() {

int choice_file;
    cout << "Choose a dataset size:" << endl;
    cout << "1. 10k" << endl;
    cout << "2. 50k" << endl;
    cout << "3. 150k" << endl;
    cout << "4. 200k" << endl;
    cout << "5. 275k" << endl;
    cout << "Enter your choice (1-5): ";
    cin >> choice_file;

    if (choice_file < 1 || choice_file > 5) {
        cout << "Invalid choice. Exiting." << endl;
        return 1;
    }
   string file_name;
switch (choice_file) {
            case 1:
              file_name = "10k.txt";
              break;
            case 2:
              file_name = "50k.txt";                
              break;
            case 3:
                file_name = "150k.txt";
                break;
            case 4:
                file_name = "200k.txt";                
                break;
            case 5:
                file_name = "275k.txt";                
                break;
        
        }


              ifstream inputFile(file_name);



  
    if (!inputFile) {
        cerr << "Error: Unable to open the input file." << endl;
        return 1;
    }

    vector<int> data;
    int num;
    while (inputFile >> num) {
        data.push_back(num);
    }
    inputFile.close();

    int choice;
    cout << "Choose a sorting algorithm:" << endl;
    cout << "1. Bubble Sort" << endl;
    cout << "2. Selection Sort" << endl;
    cout << "3. Insertion Sort" << endl;
    cout << "4. Merge Sort" << endl;
    cout << "5. Quick Sort" << endl;
    cout << "6. Shell Sort" << endl;
    cout << "Enter your choice (1-6): ";
    cin >> choice;

    if (choice < 1 || choice > 6) {
        cout << "Invalid choice. Exiting." << endl;
        return 1;
    }

    int numRuns = 5;
    double totalTime = 0.0;
    for (int run = 1; run <= numRuns; run++) {
        vector<int> copyData = data; // Copy of the original data, to not tamper with the original
        clock_t start, end;

        switch (choice) {
            case 1:
                start = clock();
                bubbleSort(copyData);
                end = clock();
                break;
            case 2:
                start = clock();
                selectionSort(copyData);
                end = clock();
                break;
            case 3:
                start = clock();
                insertionSort(copyData);
                end = clock();
                break;
            case 4:
                start = clock();
                mergeSort(copyData, 0, copyData.size() - 1);
                end = clock();
                break;
            case 5:
                start = clock();
                quickSort(copyData, 0, copyData.size() - 1);
                end = clock();
                break;
            case 6:
                start = clock();
                shellSort(copyData);
                end = clock();
                break;
        }

        double elapsedSeconds = static_cast<double>(end - start) / CLOCKS_PER_SEC;
        totalTime += elapsedSeconds;

        cout << "Run " << run << " completed in " << elapsedSeconds << " seconds." << endl;
    }

    double averageTime = totalTime / numRuns;
    cout << "Average time for " << numRuns << " runs: " << averageTime << " seconds." << endl;

    return 0;
}