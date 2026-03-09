#include <stdio.h>
#include <math.h>

typedef struct
{

    double alpha;
    double c;
    double s;

} Data; // new type : Data

int main(int argc, const char *argv[])
{
    const char *filename = "data/sc.data.bin";
    const char *mode = "rb";

    FILE *f = NULL;

    // open
    f = fopen(filename, mode);
    // perror("toto");
    if (NULL == f)
    {
        printf("Unable to open %s\n", filename);
        return 1;
    }

    fseek(f, 0, SEEK_END);
    long filesize = ftell(f);
    printf("File size = %ld bytes\n", filesize);

    fseek(f, 0, SEEK_SET); // read index at position 0
    // rewind(f); // same same

    size_t num_lines = 0;
    int ret = 0;
    ret = fread(&num_lines, sizeof(size_t), 1, f);
    if (1 != ret)
    {
        printf("Unable to read in %s\n", filename);
        return 1;
    }
    printf("num_lines=%lu\n", num_lines);

    Data d;
    for (size_t index = 0; index < num_lines; index++)
    {

        ret = fread(&d, sizeof(Data), 1, f);
        if (1 != ret)
        {
            printf("Unable to read in %s\n", filename);
            return 1;
        }
        printf("%03lu, ⍺=%+5.1lf c=%+6.3lf s=%+6.3lf\n",
               index, d.alpha, d.c, d.s);
    }

    // close
    if (0 != fclose(f))
    {
        printf("Unable to close %s\n", filename);
        return 2;
    }

    return 0;
}