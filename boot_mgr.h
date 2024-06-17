#ifndef BOOT_MGR_H
/// Boot Manager header file
/// Helps create and restore the file system.

#define BOOT_MGR_H

#include <fstream>
#include <direct.h>
#include "usr_mgr.h"
using namespace std;

namespace boot_mgr
{
    void startup()
    {
        { /// root test
            ifstream test_root_presence("root/test");
            if (test_root_presence.fail())
            {
                _mkdir("root");
                ofstream gen_root("root/test");
                gen_root.close();
            }
            test_root_presence.close();
        }
        { /// root/usr test
            ifstream test_usr_presence("root/usr/test");
            if (test_usr_presence.fail())
            {
                _mkdir("root/usr");
                ofstream gen_usr("root/usr/test");
                gen_usr.close();
            }
            test_usr_presence.close();
        }
        { /// root/usr/admin test
            ifstream test_admin_presence("root/usr/admin/test");
            if (test_admin_presence.fail())
            {
                _mkdir("root/usr/admin");
                ofstream gen_admin("root/usr/admin/test");
                gen_admin.close();
                usr_mgr::g_admin();
            }
        }
    }
}

#endif // boot_mgr

