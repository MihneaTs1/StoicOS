def run(args):
    if not args:
        print("Usage: cat <filename>")
        return

    filename = args[0]
    try:
        with open(filename, 'r') as file:
            print(file.read())
    except FileNotFoundError:
        print(f"No such file: {filename}")
