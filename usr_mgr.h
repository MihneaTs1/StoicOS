/// User Manager header file

#ifndef USR_MGR_H
#define USR_MGR_H

string get_pass() /// Safe password get method
{
    string ret = "";
    char c;
    while (1)
    {
        c = _getch();
        if ((int)c == 8)
        {
            if (!ret.empty()) ret.pop_back();
        }
        else if ((int)c == 13)
        {
            cout << '\n';
            return ret;
        }
        else ret += c;
    }
}

namespace usr_mgr
{
    string currentusr = "";
    string currentdir = "root";
    bool admin = 0;
    void gen_usr(bool possible_admin = 0)
    {

    }
    void g_admin()
    {
        string admin_pass;
        cout << "Welcome to Mihnux! If you see this message, then you are about to create an administrator role user (usually happens when first booting or when the admin user files are corrupted." << endl;
        cout << "Enter admin's password: ";

        string pass = get_pass();

        cout << "Creating user...\n";
        _mkdir("root/usr/admin");
        ofstream out_pass("root/usr/admin/pass");
        out_pass << pass;
        out_pass.close();
        cout << "User finished creating!\n";
    }
}

#endif // usr_mgr
