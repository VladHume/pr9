import os
import tempfile
import subprocess

def check_access(path):
    can_read = os.access(path, os.R_OK)
    can_write = os.access(path, os.W_OK)
    print(f"Read access: {can_read}, Write access: {can_write}")

if __name__ == "__main__":
    with tempfile.NamedTemporaryFile(delete=False) as tmp:
        path = tmp.name
        print(f"Temporary file created at: {path}")

    # Change ownership and permissions as root
    subprocess.run(['sudo', 'chown', 'root:root', path])
    subprocess.run(['sudo', 'chmod', '600', path])

    # Check access as current user
    check_access(path)

    # Cleanup
    try:
        os.remove(path)
    except Exception:
        pass
