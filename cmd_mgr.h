#ifndef CMD_MGR_H
#define CMD_MGR_H

namespace cmd_mgr
{
	using CommandFunction = std::function<void()>;
	map<string, CommandFunction> commandRegistry;
}

#endif // cmd_mgr