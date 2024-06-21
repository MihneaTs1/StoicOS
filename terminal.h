/// Operating System (please somebody make a GUI for this)

#ifndef TERMINAL_H
#define TERMINAL_H

#include <iostream>
#include <fstream>
#include <Windows.h>
#include <direct.h>
#include <complex>
#include <vector>

using namespace std;

string usr = "", dir = "root";

namespace terminal
{
	void init()
	{
		cout << "Opensource MihneaTs1 2024\n";

		while (1) /// command get
		{
			string command; getline(cin, command);
			string request;
			vector<pair<string, string>> params;

			bool ok_req = 0;
			for (int i = 0; i < command.size(); i++)
			{
				if (!ok_req && command[i] != ' ')
					while (i < command.size() && command[i] != ' ') request += command[i], i++;
				else if (command[i] != ' ')
				{
					params.push_back({ "", "" });
					while (i < command.size() && command[i] != ' ') params.back().first += command[i], i++;
					while (i < command.size() && command[i] == ' ') i++;
					while (i < command.size() && command[i] != ' ') params.back().second += command[i], i++;
				}
			}
		}
	}
}

#endif // terminal