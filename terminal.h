/// Operating System (please somebody make a GUI for this)

#ifndef TERMINAL_H
#define TERMINAL_H

string usr = "", dir = "root/";

void executeCommand(string command, map<string, string> params)
{
	auto it = cmd_mgr::commandRegistry.find(command);
	if (it != cmd_mgr::commandRegistry.end()) it->second();
	else
	{
		cout << "Command \"" << command << "\" not found.\n";
	}
}

namespace terminal
{
	void init()
	{
		cout << "Open Source MihneaTs1 2024\n";
		cout << "Type \"help\" for help\n";

		while (1) /// command get
		{
			cout << dir << "> ";
			string command; getline(cin, command);
			string request;
			map<string, string> params;

			bool ok_req = 0;
			for (int i = 0; i < command.size(); i++)
			{
				if (!ok_req && command[i] != ' ')
				{
					ok_req = 1;
					while (i < command.size() && command[i] != ' ') request += command[i], i++;
				}
				else if (command[i] != ' ')
				{
					pair<string, string> prm;
					while (i < command.size() && command[i] != ' ') prm.first += command[i], i++;
					while (i < command.size() && command[i] == ' ') i++;
					while (i < command.size() && command[i] != ' ') prm.second += command[i], i++;
					params[prm.first] = prm.second;
				}
			}

			executeCommand(request, params);
		}
	}
}

#endif // terminal