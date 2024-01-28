
/* /// input///
 #include<bits/stdc++.h>
using namespace std;

int main()
{
    // This is a single line comment
    cout << "Hello, World!" << endl;
    // This is a single line comment
    cout << "This is a simple C++ program." << endl;
    //MY name is Mayeen Uddin hasan
    cout<<"MY Name is Mayeen Uddin Hasan"<<endl;
    return 0;
}*/
#include <bits/stdc++.h>

using namespace std;


string removeComments(const string& line) {
    string result;
    bool inBlockComment = false;

    for (size_t i = 0; i < line.size(); ++i) {
        if (!inBlockComment && i + 1 < line.size() && line[i] == '/' && line[i + 1] == '/') {

            break;
        } else if (!inBlockComment && i + 1 < line.size() && line[i] == '/' && line[i + 1] == '*') {

            inBlockComment = true;
            ++i;
        } else if (inBlockComment && i + 1 < line.size() && line[i] == '*' && line[i + 1] == '/') {

            inBlockComment = false;
            ++i;
        } else if (!inBlockComment) {

            result += line[i];
        }
    }

    return result;
}

int main() {
    string inputFileName, line;

    cout << "Enter input file name: ";
    cin >> inputFileName;


    ifstream inputFile(inputFileName);

    if (!inputFile) {
        cout << "Error: Unable to open input file." << endl;
        return 1;
    }
    ofstream outputFile(inputFileName + "_temp");

    if (!outputFile) {
        cout << "Error: Unable to open output file." << endl;
        return 1;
    }

    while (getline(inputFile, line)) {
        string processedLine = removeComments(line);
        outputFile << processedLine << endl;
    }

    inputFile.close();
    outputFile.close();
    if (remove(inputFileName.c_str()) != 0 || rename((inputFileName + "_temp").c_str(), inputFileName.c_str()) != 0) {
        cout << "Error: Unable to update the input file." << endl;
        return 1;
    }

    cout << "Comments removed successfully and updated in the input file." << endl;

    return 0;
}
