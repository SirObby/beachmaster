#ifndef _H_BINARY_FORMAT
#define _H_BINARY_FORMAT

#define BINARY_FORMAT_MAXIMUM_BYTES 4096

enum binary_format_type {
    PACKAGE,
    DEPENDANCY,
    MANIFEST
};

enum binary_format_sector_name {
    NAME,
    VERSION,
    URL,
    DEPENDANCIES,
    BYTECOUNT
};

typedef struct binary_format
{
    enum binary_format_type type;
    char bytes[BINARY_FORMAT_MAXIMUM_BYTES];
    int byte_count;    
};

/**
 * @brief set a (binary format) sector, must be run in order.
 * 
 * @param bf 
 * @param byte_count 
 */
void bf_set_sector(binary_format bf, binary_format_sector_name bf_type, int byte_count);
char *bf_get_sector_char(binary_format bf, binary_format_sector_name bf_type);
int bf_get_sector_int(binary_format bf, binary_format_sector_name bf_type);

struct binary_format parse_from_file(binary_format bf);

#endif