import os
import subprocess

def list_and_test(path):
    print(f"Listing files in {path}:")
    try:
        files = os.listdir(path)
    except PermissionError:
        print("Permission denied to list directory.")
        return

    for f in files[:5]:  # limit output for demo
        full_path = os.path.join(path, f)
        try:
            st = os.stat(full_path)
            print(f"{f}: owner={st.st_uid}, permissions={oct(st.st_mode)}")

            can_read = os.access(full_path, os.R_OK)
            can_write = os.access(full_path, os.W_OK)
            can_exec = os.access(full_path, os.X_OK)
            print(f"  Read: {can_read}, Write: {can_write}, Execute: {can_exec}")
        except FileNotFoundError:
            pass

if __name__ == "__main__":
    home = os.path.expanduser('~')
    for directory in [home, '/usr/bin', '/etc']:
        list_and_test(directory)
        print()
