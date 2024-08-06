import os


def run(args):
    if args:
        path = args[0]
    else:
        path = '.'

    try:
        for item in os.listdir(path):
            print(item)
    except FileNotFoundError:
        print(f"No such directory: {path}")
