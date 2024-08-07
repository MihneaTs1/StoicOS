import os
import requests
import zipfile
import io
import shutil

GITHUB_API_URL = "https://api.github.com/repos"


def download_and_install(repo_name, module_name):
    repo_url = f"{GITHUB_API_URL}/{repo_name}/zipball/main"

    print(f"Downloading {repo_name}...")
    try:
        response = requests.get(repo_url)
        response.raise_for_status()
    except requests.RequestException as e:
        print(f"Failed to download {repo_name}: {e}")
        return

    print(f"Extracting {module_name}...")
    try:
        with zipfile.ZipFile(io.BytesIO(response.content)) as z:
            temp_dir = f"modules/temp_{module_name}"
            os.makedirs(temp_dir, exist_ok=True)
            z.extractall(temp_dir)

            # Find the extracted folder
            extracted_folder = next(os.path.join(temp_dir, name) for name in os.listdir(temp_dir) if
                                    os.path.isdir(os.path.join(temp_dir, name)))

            # Move the contents to the target module directory
            for item in os.listdir(extracted_folder):
                s = os.path.join(extracted_folder, item)
                d = os.path.join('modules', item)
                if os.path.isdir(s):
                    shutil.copytree(s, d, dirs_exist_ok=True)
                else:
                    shutil.copy2(s, d)

            # Clean up the temporary directory
            shutil.rmtree(temp_dir)

        print(f"{module_name} installed successfully!")
    except Exception as e:
        print(f"Failed to extract {repo_name}: {e}")


def run(args):
    if len(args) < 2:
        print("Usage: package_manager install <github_repo> <module_name>")
        return

    command = args[0]
    if command == "install":
        repo_name = args[1]
        module_name = args[2] if len(args) > 2 else repo_name.split('/')[-1]
        download_and_install(repo_name, module_name)
    else:
        print(f"Unknown command: {command}")
