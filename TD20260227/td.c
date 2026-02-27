#include <stdio.h>

int main(int argc, const char *argv[])
{
    const char *filename = "data/saucisse.iut";
    const char *mode = "w";

    FILE *f = NULL;

    // open
    f = fopen(filename, mode);
    if (NULL == f)
    {
        printf("Unable to create %s\n", filename);
        return 1;
    }

    // write
    fprintf(f, "Hello1\n");
    fprintf(f, "Hello2");

    // close
    if (0 != fclose(f))
    {
        printf("Unable to close %s\n", filename);
        return 2;
    }

    return 0;
}