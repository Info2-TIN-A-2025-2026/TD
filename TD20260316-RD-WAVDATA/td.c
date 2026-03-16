#include <stdio.h>
#include <stdlib.h> // for malloc...
#include <stdint.h>

typedef struct
{
    uint8_t riff[4]; // must contain "RIFF"
    uint32_t length; // must contain total length of file - 8
    uint8_t wav[4];  // must contain "WAVE"
} WavRiffHeader;

typedef struct
{
    uint8_t fmt[4];            // must contain "fmt "
    uint32_t length;           // must contain 0x10
    uint16_t audio_format;     // must contain 1 for PCM
    uint16_t num_channels;     // 1 = mono, 2 = stereo, ...
    uint32_t sampling_rate;    // in Hz
    uint32_t byte_rate;        // == sample_rate * channel_number * BitsPerSample/8
    uint16_t bytes_per_sample; // 1=8 bit Mono, 2=8 bit Stereo or 16 bit Mono, 4=16 bit Stereo
    uint16_t bit_per_sample;   // = 8, 16
} WavFormatHeader;

typedef struct
{
    uint8_t data[4]; // must contain data
    uint32_t length; // length of data;
} WavDataHeader;

typedef struct
{
    WavRiffHeader riff;
    WavFormatHeader format;
    WavDataHeader data;
} WavHeader;

typedef struct
{
    int16_t left;
    int16_t right;
} StereoSample;

int main(int argc, const char *argv[])
{
    const char *filename = "data/440Hz.wav";
    const char *mode = "rb";

    FILE *f = NULL;

    printf("Sizeof WavHeader = %ld bytes\n", sizeof(WavHeader));

    f = fopen(filename, mode);
    if (NULL == f)
    {
        printf("Unable to open %s\n", filename);
        return 1;
    }

    fseek(f, 0, SEEK_END);
    long filesize = ftell(f);
    printf("File size = %ld bytes\n", filesize);

    fseek(f, 0, SEEK_SET); // read index at position 0

    WavHeader h;
    int ret = fread(&h, sizeof(h), 1, f);
    if (1 != ret)
    {
        printf("Unable to read the header\n");
        return 4;
    }
    printf("Header size       : %ld\n", sizeof(WavHeader));
    printf("Data Length       : %d\n", h.data.length);
    printf("Number of channels: %d\n", h.format.num_channels);
    printf("Sampling rate     : %d\n", h.format.sampling_rate);
    printf("Bit per sample    : %d\n", h.format.bit_per_sample);
    printf("Bytes per sample  : %d\n", h.format.bytes_per_sample);

    size_t num_samples = h.data.length / sizeof(StereoSample);
    printf("num_samples       : %lu samples\n", num_samples);

    StereoSample *d = NULL;
    d = (StereoSample *)calloc(num_samples, sizeof(StereoSample));
    printf("adress=%p\n", d);

    if (NULL == d)
    {
        printf("Unable to allocate memory.\n");
        return 8;
    }

    // here you can use d
    ret = fread(d, sizeof(StereoSample), num_samples, f);
    if (num_samples != ret)
    {
        printf("Unable to read the data\n");
        return 16;
    }

    size_t i = 0; // loop index
    int16_t min_value = d[0].left;
    int16_t max_value = d[0].left;
    int64_t sum = 0;
    int16_t mean_value = 0;

    for (i = 0; i < num_samples; i++)
    {
        min_value = d[i].left < min_value ? d[i].left : min_value;
        max_value = d[i].left > max_value ? d[i].left : max_value;
        sum += d[i].left;
    }
    mean_value = sum / num_samples;

    printf("Min  : %+hd\n", min_value);
    printf("Max  : %+hd\n", max_value);
    printf("Mean : %+hd\n", mean_value);

    if (0 != fclose(f))
    {
        printf("Unable to close %s\n", filename);
        return 2;
    }

    // create a copy of 440Hz.wav as cp.wav
    const char *filename2 = "data/cp.wav";
    const char *mode2 = "wb";

    f = fopen(filename2, mode2);
    if (NULL == f)
    {
        printf("Unable to open %s\n", filename2);
        return 1;
    }
    ret = fwrite(&h, sizeof(h), 1, f);
    if (1 != ret)
    {
        printf("Unable to write the header\n");
        return 4;
    }
    // change waveform from sine to square
    for (i = 0; i < num_samples; i++)
    {
        d[i].left = d[i].left>0 ? max_value : min_value;
        d[i].right = d[i].right>0 ? max_value : min_value;
    }

    ret = fwrite(d, sizeof(StereoSample), num_samples, f);
    if (num_samples != ret)
    {
        printf("Unable to write the data\n");
        return 16;
    }
    if (0 != fclose(f))
    {
        printf("Unable to close %s\n", filename2);
        return 2;
    }






    free(d);
    // here you can not use d

    return 0;
}