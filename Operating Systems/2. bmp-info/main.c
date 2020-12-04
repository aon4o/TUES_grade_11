#include <stdint.h>
#include <stdio.h>
#include "read.c"

int main( int argc, const char* argv[] ) {
    char* image_info = read_image(argv[1]);

    uint32_t *wight = (uint32_t*)(image_info + 18);
    uint32_t *height = (uint32_t*)(image_info + 22);

    printf("Image wight = %d.\n", *wight);
    printf("Image height = %d.\n", *height);

    return 0;
}
