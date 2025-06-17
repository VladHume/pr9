import subprocess

def run_commands():
    whoami = subprocess.check_output(['whoami']).decode().strip()
    user_id = subprocess.check_output(['id']).decode().strip()
    print(f"User: {whoami}")
    print(f"ID and groups: {user_id}")

if __name__ == "__main__":
    run_commands()
