#include <stdio.h>
#include <math.h>

int main(int argc, const char *argv[])
{
    const double ANGLE_MIN = 0.;
    const double ANGLE_MAX = 359.;
    const double STEP = 1.;
    const char *filename = "data/sc.data";
    const char *mode = "w";

    FILE *f = NULL;

    // open
    f = fopen(filename, mode);
    if (NULL == f)
    {
        printf("Unable to create %s\n", filename);
        return 1;
    }

    for(double alpha=ANGLE_MIN;alpha<=ANGLE_MAX;alpha+=STEP) {
        double c=cos(alpha/180.*M_PI);
        double s=sin(alpha/180.*M_PI);
        fprintf(f,"%3.0lf %+.6lf %+.6lf\n",
            alpha, c, s);
    }

    // close
    if (0 != fclose(f))
    {
        printf("Unable to close %s\n", filename);
        return 2;
    }

    return 0;
}