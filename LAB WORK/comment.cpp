
#include <bits/stdc++.h>

using namespace std;

string removeComments(const string &input)
{
    string result;
    bool BC = 0;
    bool inLineComment = 0;

    for (size_t i = 0; i < input.length(); ++i)
    {
        if (!BC && input[i] == '/' && i + 1 < input.length())
        {
            if (input[i + 1] == '*')
            {
                BC = 1;
                ++i;
                continue;
            }
            else if (input[i + 1] == '/')
            {
                inLineComment = 1;
                ++i;
                continue;
            }
        }

        if (BC && input[i] == '*' && i + 1 < input.length() && input[i + 1] == '/')
        {
            BC = 0;
            ++i;
            continue;
        }

        if (!BC && !inLineComment)
        {
            result += input[i];
        }

        if (inLineComment && input[i] == '\n')
        {
            inLineComment = 0;
        }
    }

    return result;
}

int main()
{
    ifstream inputFile("input.txt");
    if (!inputFile)
    {
        cout << "Error opening the file!" << endl;
        return 1;
    }

    string inputContent((istreambuf_iterator<char>(inputFile)), (istreambuf_iterator<char>()));
    inputFile.close();

    string result = removeComments(inputContent);

    cout << "Content without comments:"<<endl;
    cout<<endl;
    cout << result << endl;

    return 0;
}
