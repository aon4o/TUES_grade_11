#include <stdint.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <string.h>

void *read_image( const char *filepath );

int main( int argc, const char* argv[] ) {
    const char* fp = argv[1];

    if ((strstr(fp, ".png") == NULL && strstr(fp, ".PNG") == NULL)) {
        printf("The input file should be a real file of the PNG type!\n");
        return 0;
    }

	char *image = read_image(fp);
	uint32_t* wight = (uint32_t*)(image + 16);
	uint32_t* height = (uint32_t*)(image + 20);

    FILE * f = fopen(fp, "r");
    fseek(f, 0, SEEK_END);
    unsigned long size = (unsigned long)ftell(f);
    fclose(f);

    printf("Image wight: %d\n", ntohl(*wight));
    printf("Image height: %d\n", ntohl(*height));
    printf("Image size(B): %ld\n", size);
    return 0;
}
