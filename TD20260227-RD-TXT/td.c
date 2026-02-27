#include <stdio.h>
#include <math.h>

int main(int argc, const char *argv[])
{
    const double ANGLE_MIN = 0.;
    const double ANGLE_MAX = 359.;
    const double STEP = 1.;
    const char *filename = "../TD20260227-WR-TXT/data/sc.data";
    const char *mode = "r";

    FILE *f = NULL;

    // open
    f = fopen(filename, mode);
    if (NULL == f)
    {
        printf("Unable to open %s\n", filename);
        return 1;
    }
    double sum_c = 0.;
    double sum_s = 0.;
    for (double alpha = ANGLE_MIN; alpha <= ANGLE_MAX; alpha += STEP)
    {
        double c = 0.;
        double s = 0.;
        int ret = 0;
        ret = fscanf(f, "%*f %lf %lf", &c, &s);
        if (2 != ret)
        {
            printf("Unable to read from %s\n", filename);
            return 2;
        }
        sum_c += c * STEP;
        sum_s += s * STEP;
    }
    printf("sum cos = %+lf\n", sum_c);
    printf("sum sin = %+lf\n", sum_s);

    // close
    if (0 != fclose(f))
    {
        printf("Unable to close %s\n", filename);
        return 3;
    }

    return 0;
}