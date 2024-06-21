/// Opensource MihneaTs1 2024

#include <iostream>
#include <fstream>
#include <Windows.h>
#include <direct.h>
#include <complex>
#include <vector>
#include <map>
#include <functional>
#include <conio.h>
#include <string>
using namespace std;
#include "cmd_mgr.h"
#include "terminal.h"
#include "boot_mgr.h"

int main()
{
    /// This is where everything begins...
    ::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
    boot_mgr::startup();
    system("CLS");
    terminal::init();

    return 0;
}
