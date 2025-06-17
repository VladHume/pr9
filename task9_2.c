import subprocess

def cat_shadow():
    try:
        output = subprocess.check_output(['sudo', 'cat', '/etc/shadow']).decode()
        print(output)
    except subprocess.CalledProcessError:
        print("Failed to read /etc/shadow. Check sudo permissions.")

if __name__ == "__main__":
    cat_shadow()
