#include "include/desktop.hpp"
#include <cstddef>
#include <iostream>
#include <string>
#include <sys/ioctl.h>
#include <unistd.h>
#include <fstream>
#include <algorithm>

using namespace std;

string writelog(string log,int categories)
{
    ofstream file("log.txt");
    time_t now = time(0);
    tm* localTime = localtime(&now);
    string returnlog;
   
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
    returnlog = string(buffer)+" "+head+log;
    return returnlog;
}
int gtty_resolution(int c) 
{
    //获取到TTY分辨率大小
    struct winsize ws;
    int ttyr[2] = {0,0};
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == 0)
    {
        ttyr[0] = ws.ws_row;//行数
        ttyr[1] = ws.ws_col;//列数
    }
    else
    {
        writelog("Can't get TTY resolution!",2);
    }
    if (c == 0)
        return ttyr[1];//列数
    else if (c == 1)
        return ttyr[0];//行数
}

Desktop::Desktop()
{
    tty_x = gtty_resolution(1);
    tty_y = gtty_resolution(0);
}
void Desktop::writescr(string x)
{
    write_ram[0] = x;
    write_ram[0] = "";
    write_ram[1] = "";
    write_ram[2] = "";

    size_t pos = 0;
    while (pos < x.length()) {
        // 计算当前行的长度
        size_t current_length = min(static_cast<size_t>(tty_y), x.length() - pos);
        // 获取当前行的文本
        write_ram[2] = x.substr(pos, current_length);
        pos += current_length;
    
        // 输出当前行的文本
        cout << write_ram[2] << endl;
    
        // 将剩余的文本移到第二标
        write_ram[1] = x.substr(pos, x.length() - pos);
    
        // 清空第一标和第三标
        write_ram[0] = "";
        write_ram[2] = "";
    
        // 将第二标的内容移到第一标
        write_ram[0] = write_ram[1];
        write_ram[1] = "";
    }
}