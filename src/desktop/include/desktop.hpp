#ifndef DESKTOP_HPP
#define DESKTOP_HPP
#include <iostream>

using namespace std;

class Desktop
{
public:
    string write_ram[3];
    int tty_x, tty_y;
    Desktop();
    ~Desktop();
    void run();
    void event();
    void writescr(string x);
};
#endif