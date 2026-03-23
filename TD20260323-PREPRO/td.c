#include <stdio.h>
#include <stdint.h>

#define N 100
#define MY_PI 3.1415 // chépakombien

#define MAX(a, b) (a) > (b) ? (a) : (b)
#define SQUARE(a) (a) * (a)

#define DEBUG1
#define DEBUG2
#undef DEBUG2
#define GENERATE_ERROR 1
#define DEBUG_LEVEL 0

// CPU : Z80 I8085
#define CPU_Z80

int main(int argc, const char *argv[])
{
/*
#ifdef CPU_Z80
......
#endif
#ifdef I8085
......
#endif
#ifndef CPU_Z80 && I8085
#error "NO VLID CPU"
#endif
*/





#if GENERATE_ERROR == 1
//#error "ERROR GENERATED"
#endif

#if DEBUG_LEVEL >= 0
    puts("debug level 0.");
#endif
#if DEBUG_LEVEL >= 1
    puts("debug level 1.");
#endif
#ifdef DEBUG1
    puts("DEBUG1 exists.");
#endif
#ifdef DEBUG2
    puts("DEBUG2 exists.");
#endif
#ifdef DEBUG3
    puts("DEBUG3 exists.");
#endif
    printf("%d\n", N);
    printf("%lf\n", MY_PI);
    // int c=MAX(3,4);
    // float x=MAX('a',-57);

    printf("%d\n", MAX(3, 4));
    printf("%d\n", SQUARE(7));
    int i = 5;
    int j = 2;
    printf("%d\n", SQUARE(i + j));

    puts(__DATE__);
    puts(__TIME__);
    puts(__TIMESTAMP__);
    puts(__FILE__);


    return 0;
}

/*
#define DEBUG

#ifdef DEBUG
#define LOG(x) printf(x)
#else
#define LOG(x)
#endif

#define CARRE(x) x *x

typedef struct
{
    uint8_t d0 : 1;
    uint8_t d1 : 1;
    uint8_t d2 : 1;
    uint8_t d3 : 1;
    uint8_t d4 : 1;
    uint8_t d5 : 1;
    uint8_t d6 : 1;
    uint8_t d7 : 1;
} reg;

typedef union {
    reg bits;
    uint8_t byte;
} mf;

int main(int argc, const char *argv[])
{
    int c = 5;
    printf("%d : %d\n", c, CARRE(c));
    printf("%d : %d\n", c + 1, CARRE(c + 1));
    puts(__DATE__);
    puts(__TIME__);
    puts(__TIMESTAMP__);
    puts(__FILE__);
    // puts(__LINE__);

    reg a;
    a.d0 = 0;
    a.d1 = 0;
    a.d2 = 0;
    a.d3 = 0;
    a.d4 = 0;
    a.d5 = 0;
    a.d6 = 0;
    a.d7 = 0;
    printf("a.d0=%d\n", a.d0);


    mf b;
    b.byte = 0x31;
    printf("b.bits.d0=%d\n", b.bits.d0);
    printf("b.bits.d4=%d\n", b.bits.d4);
    printf("b.bits.d5=%d\n", b.bits.d5);
    printf("b.byte=%02X\n", b.byte);
    return 0;
}*/
