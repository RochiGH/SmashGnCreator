#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int fltkReadLogRTK(const  string& rtkLogFile)
{
    ifstream in(rtkLogFile,ios::binary);

    string line;

    // read everything up to the first semi-colon (even if not on
    // the first line)
    // TODO : create code that fills the GN struct . 
    while(getline(in,line,'|')) {
        cout << line << endl;
    }
  
    getline(in,line,'|');
    cout << line << endl;

    // read everything else in the file (assumes NULL is not in the file)
    getline(in,line,static_cast<char>(0));
    cout << line << endl;

    return 0;
}