#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
int countWords(const string &text) {
    stringstream stream(text);
    string word;
    int count = 0;
    while (stream >> word) {
        count++;
    }
    return count;
}
int main() {
    string fileName;
    cout << "Enter the name of the text file: ";
    cin >> fileName;
    ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open the file." << endl;
        return 1; 
    }
    stringstream buffer;
    buffer << inputFile.rdbuf();
    string fileContent = buffer.str();
    int wordCount = countWords(fileContent);
    cout << "Total number of words in the file: " << wordCount << endl;
    inputFile.close();
    return 0; 
}
