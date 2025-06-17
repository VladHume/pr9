import os
import subprocess

def get_regular_users(min_uid=1000):
    users = []
    current_uid = os.getuid()
    output = subprocess.check_output(['getent', 'passwd']).decode()
    for line in output.splitlines():
        parts = line.split(':')
        username, uid = parts[0], int(parts[2])
        if uid >= min_uid and uid != current_uid:
            users.append(username)
    return users

if __name__ == "__main__":
    users = get_regular_users()
    if users:
        print("Other regular users:", ', '.join(users))
    else:
        print("No other regular users found.")
