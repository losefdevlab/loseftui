//Loseftui boot part
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

extern void writelog(string log,int categories)
{
    ofstream file("log.txt");
    time_t now = time(0);
    tm* localTime = localtime(&now);
   
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localTime);

    string head;

    if (categories == 0)
        head = "[INFO] ";
    else if (categories == 1)
        head = "[WARNING] ";
    else if (categories == 2)
        head = "[ERROR] ";
    else if (categories == 3)
        head = "[DEBUG] ";
    else if (categories == 4)
        head = "[FATAL] ";
    else if (categories == 5)
        head = "[TRACE] ";
    else if (categories == 6)
        head = "[UNKNOWN] ";
    else if (categories == 7)
        head = "[MSG]";
    file << buffer << " " << head << log << endl;
}
int main()
{
    cout << "Welcome to ---" << endl;
    cout << "Loseftui\n     Press enter..."<< endl;
    if(getchar() == '\n')
    {
        //tuidesktop tdktp;
        //tdktp.into();
    }
    return 0;
}