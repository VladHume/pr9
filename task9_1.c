#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    FILE *fp = popen("getent passwd", "r");
    if (fp == NULL) {
        perror("popen");
        exit(EXIT_FAILURE);
    }

    char line[512];
    uid_t uid = getuid();

    while (fgets(line, sizeof(line), fp)) {
        char *username = strtok(line, ":");
        strtok(NULL, ":"); // password field
        char *uid_str = strtok(NULL, ":");

        if (username && uid_str) {
            int user_uid = atoi(uid_str);
            if (user_uid >= 1000 && user_uid != uid) { 
                printf("Found another regular user: %s (UID: %d)\n", username, user_uid);
            }
        }
    }

    pclose(fp);
    return 0;
}
