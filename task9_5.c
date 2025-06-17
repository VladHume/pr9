#include <stdio.h>
#include <stdlib.h>

int main() {
    system("touch /tmp/tempfile.txt");
    system("echo 'Дані' > /tmp/tempfile.txt");

    printf("Змінюємо власника на root і права доступу...\n");
    system("sudo chown root:root /tmp/tempfile.txt");
    system("sudo chmod 600 /tmp/tempfile.txt");

    printf("Спроба читати файл:\n");
    int ret = system("cat /tmp/tempfile.txt");
    if (ret != 0)
        printf("Читання не дозволено\n");

    printf("Спроба записати у файл:\n");
    ret = system("echo 'Новий рядок' >> /tmp/tempfile.txt");
    if (ret != 0)
        printf("Запис не дозволено\n");

    return 0;
}
