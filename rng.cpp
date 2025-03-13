#include <fstream>
#include <iostream>
#include <random>
#include <set>
using namespace std;

int main() {
  // set the amount of elements for the file: 10k, 50k, 150k, 200k, or 275k
  const int numRandomNumbers = 275000;

  // use sets to ensure no repeating numbers
  set<int> generatedNumbers;

  // generate a random number
  random_device rd;
  mt19937 generator(rd());

  // create an output file. After running this program, rename the file to its size.
  ofstream outFile("numbers.txt");
  
  // ends progam if output file can not be opened 
  if (!outFile) {
    cout << "Error opening the output file." << endl;
    return 1;
  }

  // generate and write unique random numbers to the file
  while (generatedNumbers.size() < numRandomNumbers) {
    int randomNumber = generator(); // Generate a random number

    // check if the number is not already created
    if (generatedNumbers.find(randomNumber) == generatedNumbers.end()) {
       // Store the generated number
      generatedNumbers.insert(randomNumber);
      // insert the number into the file
      outFile << randomNumber << endl; 
    }
  }

  // Close the output file
  outFile.close();

  cout << "Random numbers generated and saved to 'numbers.txt'."
            << endl;

  return 0;
}