/// Opensource MihneaTs1 2024

#include <Windows.h>
#include "boot_mgr.h"
#include "terminal.h"

using namespace std;

int main()
{
    /// This is where everything begins...
    ::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
    boot_mgr::startup();
    system("CLS");
    terminal::init();

    return 0;
}
