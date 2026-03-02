#include <stdio.h>
#include <math.h>

#define N 5

// view hex content of file : od -t x1 filename

typedef struct
{

    double alpha;
    double c;
    double s;

} Data; // new type : Data

int main(int argc, const char *argv[])
{
    const double ANGLE_MIN = 0.;
    const double ANGLE_MAX = 359.;
    const double STEP = 1.;
    const char *filename = "data/sc.data.bin";
    const char *mode = "wb";

    FILE *f = NULL;

    // open
    f = fopen(filename, mode);
    if (NULL == f)
    {
        printf("Unable to create %s\n", filename);
        return 1;
    }
    // Test write one double
    // double x = 0.123456789;
    // size_t ret=0;
    // ret=fwrite(&x, sizeof(double), 1, f);
    // if (1 != ret)
    // {
    //     printf("Unable to write in %s\n", filename);
    //     return 1;
    // }

    // Test write a table of short
    // const short t[N] = { 0x0123, 0x1234, 0x2345, 0x3456, 0x4567};
    // ret=fwrite(t, sizeof(short), N, f);
    // if (N != ret)
    // {
    //     printf("Unable to write in %s\n", filename);
    //     return 1;
    // }

    // Data d;
    // d.alpha = 34.0;
    // d.c = 0.;
    // d.s = -0.342;
    // sizeof(Data) = 24
    // printf("%lf", d.alpha)

    // Data *p;
    // p = &d;
    // p->alpha = 1.;

    // HEADER of binary file
    size_t num_lines = 1+(ANGLE_MAX-ANGLE_MIN)/STEP;
    size_t ret=0;
    ret = fwrite(&num_lines, sizeof(size_t), 1, f);
    if (1 != ret)
    {
        printf("Unable to write the header in %s\n", filename);
        return 1;
    }

    // DATA of binary file
    for (double alpha = ANGLE_MIN; alpha <= ANGLE_MAX; alpha += STEP)
    {
        // double c=cos(alpha/180.*M_PI);
        // double s=sin(alpha/180.*M_PI);
        // size_t ret=0;
        // ret=fwrite(&alpha, sizeof(double), 1, f);
        // if(1!=ret) {
        //     printf("Unable to write in %s\n", filename);
        //     return 1;
        // }
        // ret=fwrite(&c, sizeof(double), 1, f);
        // if(1!=ret) {
        //     printf("Unable to write in %s\n", filename);
        //     return 1;
        // }
        // ret=fwrite(&s, sizeof(double), 1, f);
        // if(1!=ret) {
        //     printf("Unable to write in %s\n", filename);
        //     return 1;
        // }

        // Data d = {.alpha = alpha, .c = cos(alpha/180.*M_PI), .s = sin(alpha/180.*M_PI)};
        Data d;
        d.alpha = alpha;
        d.c = cos(alpha / 180. * M_PI);
        d.s = sin(alpha / 180. * M_PI);

        size_t ret=0;
        ret = fwrite(&d, sizeof(Data), 1, f);
        if (1 != ret)
        {
            printf("Unable to write in %s\n", filename);
            return 1;
        }
    }

    // close
    if (0 != fclose(f))
    {
        printf("Unable to close %s\n", filename);
        return 2;
    }

    return 0;
}