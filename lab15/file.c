#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100

typedef struct {
    char name[10];
    char surname[15];
    int id;
    char lvl[7];
} user_t;

double get_size(char *filename) {
    FILE *f = fopen(filename, "rb");
    if (f == NULL) {
        printf("Error opening file!!!\n");
    }
    fseek(f, 0, SEEK_END);
    double size = ftell(f);
    fclose(f);
    return size;
}

void compress() {
    FILE *in = fopen("hos.jpg", "rb");
    FILE *out = fopen("database.rle", "wb");
    if (in == NULL || out == NULL ) {
        printf("Error opening file!!!\n");
        exit(1);
    }

    int cur;
    int next;
    unsigned char count;

    cur = fgetc(in);
    while (cur != EOF) {
        count = 1;
        while ((next = fgetc(in)) == cur && count < 255) {
            count++;
        }
        fputc(count, out);
        fputc(cur, out);
        cur = next;
    }

    fclose(in);
    fclose(out);

    double s1 = get_size("database.dat");
    double s2 = get_size("database.rle");
    double p = (s2/s1)*100;
    if ( p > 100) {
        p = 100 - p;
    }
 
    printf("Size before: %.0f byte, Size after: %.0f byte. Compression: %.1f%%\n", s1, s2, p);
}

void decompress() {
    FILE *in = fopen("database.rle", "rb");
    FILE *out = fopen("database_rerle.jpg", "wb");
    if ( in == NULL || out == NULL ) {
        printf("Error opening file!!!\n");
        exit(1);
    }

    unsigned char count;
    int value;

    while (fread(&count, 1, 1, in) == 1) {
        value = fgetc(in);
        for (int i = 0; i < count; i++) {
            fputc(value, out);
        }
    }

    fclose(in);
    fclose(out);
}

void Search(FILE *f) {
    int searchid;
    int flag = 0; 
    user_t buffer;

    rewind(f);

    printf("What ID do u need?\n");
    if (scanf("%d", &searchid) != 1) return;

    while (fread(&buffer, sizeof(user_t), 1, f) == 1) {
        if (buffer.id == searchid) {
            printf("User was found!\n| Name: %s | Surname: %s | ID: %d | Lvl: %s |\n", 
                    buffer.name, buffer.surname, buffer.id, buffer.lvl);
            flag = 1;
            break;
        }
    }

    if (flag==0) {
        printf("User not found!\n");
    }
}

int main (int argc, char *argv[]) {
    if (argc < 2) exit(1);

    FILE* dataf = fopen("database.dat", "wb");
    if (dataf == NULL) exit(1);

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        fclose(dataf);
        exit(1);
    }

    char line[N];
    printf("+-------------------------------------------------+\n");
    printf("| Name     | Surname      | ID   | Lvl            |\n");
    printf("+----------+--------------+------+----------------+\n");

    while (fgets(line, sizeof(line), file)) {
        user_t temp;
        int parts = sscanf(line, "%s %[^;];%d;%s", temp.name, temp.surname, &temp.id, temp.lvl);
        if (parts == 4) {
            printf("| %-8s | %-12s | %-4d | %-14s |\n", temp.name, temp.surname, temp.id, temp.lvl);
            fwrite(&temp, sizeof(user_t), 1, dataf);
        }
    }
    printf("+-------------------------------------------------+\n");

    Search(dataf);
    fclose(dataf);
    fclose(file);

    compress();
    decompress();

    return 0;
}
