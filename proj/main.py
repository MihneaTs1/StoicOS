import os
import importlib

os_ver = "version 0.1P Alpha"

def load_modules():
    modules = {}
    modules_dir = 'modules'
    for filename in os.listdir(modules_dir):
        if filename.endswith('.py') and filename != '__init__.py':
            module_name = filename[:-3]
            module = importlib.import_module(f'{modules_dir}.{module_name}')
            modules[module_name] = module
    return modules


def main():
    print(f"Welcome to StoicOS {os_ver}!")
    modules = load_modules()

    while True:
        try:
            command = input("> ").strip().split()
            if not command:
                continue

            cmd_name = command[0]
            args = command[1:]

            if cmd_name == 'exit':
                print("Exiting...")
                break

            if cmd_name in modules:
                if cmd_name == 'help':
                    modules[cmd_name].run(args, modules.keys())
                else:
                    modules[cmd_name].run(args)
            else:
                print(f"Command '{cmd_name}' not found. Type 'help' for a list of commands.")
        except (KeyboardInterrupt, EOFError):
            print("\nExiting...")
            break


if __name__ == "__main__":
    main()
