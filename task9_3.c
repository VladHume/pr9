import os
import subprocess

def create_file(path):
    with open(path, 'w') as f:
        f.write("Sample content\n")

def copy_as_root(src, dest):
    subprocess.run(['sudo', 'cp', src, dest])
    subprocess.run(['sudo', 'chown', 'root:root', dest])

def try_modify(path):
    try:
        with open(path, 'a') as f:
            f.write("Adding text\n")
        print("File modified successfully.")
    except PermissionError:
        print("Permission denied: cannot modify file.")

def try_delete(path):
    try:
        os.remove(path)
        print("File deleted successfully.")
    except PermissionError:
        print("Permission denied: cannot delete file.")

if __name__ == "__main__":
    user_file = '/tmp/user_file.txt'
    root_copy = '/home/username/user_file_copy.txt'  # change username appropriately
    
    create_file(user_file)
    copy_as_root(user_file, root_copy)
    try_modify(root_copy)
    try_delete(root_copy)
