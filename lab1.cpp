#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

int main() 
{   /* Overall flow of the program:
   Get some input for the title
   Get some input for column header #1
   Get some input for column header #2

   Until the user types "-1":
   Get input for a string
   Validate input
   If valid...
      Split
      Validate second half of input
      If also valid...
         Store separate pieces

   Print out data in table format

   Print out data in chart format
   */
    // Get some input for the title
    string dataTitle;
    cout << "Enter a title for the data:" << endl;
    getline(cin, dataTitle);
    cout << "You entered: " << dataTitle << endl;

    // Get some input for column header #1
    string firstColumn;
    cout << "Enter the column 1 header:" << endl;
    getline(cin, firstColumn);
    cout << "You entered: " << firstColumn << endl;

    // Get some input for column header #2
    string secondColumn; 
    cout << "Enter the column 2 header:" << endl;
    getline(cin, secondColumn);
    cout << "You entered: " << secondColumn << endl;

    // Vectors to hold data points
    vector<string> stringofData;
    vector<int> integerofData;

    // Begin collecting data points through infinite loops
    while (true) {
        string pointsOfData;
        cout << "Enter a data point (-1 to stop input):" << endl;
        getline(cin, pointsOfData);

        // Check to see if the user stops entering data
        if (pointsOfData == "-1") { 
            break;
        }

        //reference for .find() string function: https://cplusplus.com/reference/string/string/find/
        //search for first comma
        size_t commaNum = pointsOfData.find(',');
        
        // Condition if no comma is in the input variable
        if (commaNum == string::npos) { //reference for string::npos: https://cplusplus.com/reference/string/string/npos/
            cout << "Error: No comma in string." << endl;
            continue;
        }

        // Condition if there's more than one comma in the input variable
        if (pointsOfData.find(',', commaNum + 1) != string::npos) {
            cout << "Error: Too many commas in input." << endl;
            continue;
        }

        // Splitting the input variable into the names and values of the data
        //reference for .substr() function: https://cplusplus.com/reference/string/string/substr/
        string dataNames = pointsOfData.substr(0, commaNum);
        string dataStringVal = pointsOfData.substr(commaNum + 1);

        try {
            // Converting value to integer
            int dataValue = stoi(dataStringVal);
            // Store extracted data for string and integer in their corresponding vectors
            stringofData.push_back(dataNames);
            integerofData.push_back(dataValue);
            // Display extracted data for string and integer
            cout << "Data string: " << dataNames << endl;
            cout << "Data integer: " << dataValue << endl;
        } 
        catch (const std::exception& ex) { //reference for std::exception&ex: https://stackoverflow.com/questions/4273375/why-is-the-c-stdexceptionwhat-member-const
            cout << "Error: Comma not followed by an integer." << endl;
        }
    }

    // Display the data in a table
    cout << endl;
    cout << setw(33) << dataTitle << endl;
    cout << setw(20) << left << firstColumn << "|" << setw(23) << right << secondColumn << endl;
    cout << "--------------------------------------------" << endl;
    for (size_t i = 0; i < stringofData.size(); ++i) {
        cout << setw(20) << left << stringofData[i] << "|" << setw(23) << right << integerofData[i] << endl;
    }
    cout << endl;
    // Display a histogram of the data
    for (size_t i = 0; i < stringofData.size(); ++i) {
        cout << setw(20) << stringofData[i] << " ";
        cout << string(integerofData[i], '*') << endl;
        }
        cout << endl;

    return 0;
}