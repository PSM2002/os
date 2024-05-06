#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    char msg[1000], ch;
    char old_name[20], new_name[20], source_file[20], target_file[20];
    FILE *fptr, *source, *target;

    printf("\n1. Create File and Write Data\n");
    printf("2. Read Data\n");
    printf("3. Rename File\n");
    printf("4. Copy Data from One File to Another\n");
    printf("Enter Your Choice: ");
    scanf("%d", &choice);
    getchar(); // consume the newline character after reading integer

    switch (choice) {
        case 1:
            fptr = fopen("program2.txt", "w");
            if (fptr == NULL) {
                printf("Error creating file!\n");
                exit(1);
            }
            printf("Enter message: ");
            fgets(msg, sizeof(msg), stdin);
            fprintf(fptr, "%s", msg);
            fclose(fptr);
            break;

        case 2:
            fptr = fopen("program2.txt", "r");
            if (fptr == NULL) {
                printf("Error opening file!\n");
                exit(1);
            }
            fgets(msg, sizeof(msg), fptr);
            printf("Message is: %s\n", msg);
            fclose(fptr);
            break;

        case 3:
            printf("Enter the current file name: ");
            scanf("%19s", old_name);
            printf("Enter the new file name: ");
            scanf("%19s", new_name);
            if (rename(old_name, new_name) == 0) {
                printf("File renamed successfully.\n");
            } else {
                printf("Unable to rename files. Please check if files exist and you have permission to modify files.\n");
            }
            break;

        case 4:
            printf("Enter the name of the file to copy from: ");
            scanf("%19s", source_file);
            source = fopen(source_file, "r");
            if (source == NULL) {
                printf("Error opening source file.\n");
                exit(EXIT_FAILURE);
            }
            printf("Enter the name of the target file: ");
            scanf("%19s", target_file);
            target = fopen(target_file, "w");
            if (target == NULL) {
                printf("Error creating target file.\n");
                fclose(source);
                exit(EXIT_FAILURE);
            }
            while ((ch = fgetc(source)) != EOF) {
                fputc(ch, target);
            }
            fclose(source);
            fclose(target);
            printf("File copied successfully.\n");
            break;

        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}
