#ifndef HW_H
#define HW_H
#include <stdlib.h>
#include <stdio.h>

#include "const.h"

/**
 * @brief Validates command line arguments passed to the program.
 * @details This function will validate all the arguments passed to the program
 * and will return 1 byte (char) that will contain the information necessary for
 * the proper execution of the program.
 *
 * @param argc The number of arguments passed to the program from the CLI.
 * @param argv The argument strings passed to the program from the CLI.
 * @param in The OUTPUT_FILE of the program.
 * @param out The INPUT_FILE of the program.
 * @return Refer to homework document for the return value of this function.
 */
char validargs(int argc, char **argv, FILE **in, FILE **out);
int string_length(char * str);
int charToDecimal(char * str, int nLength);
char get_flag(char * str);
int encryption(int alphabetLength, int shiftAmout, FILE* in, FILE* out);
int decryption(int alphabetLength, int shiftAmout, FILE* in, FILE* out);
int tutEncryption(int alphabetLength, int shiftAmout, FILE* in, FILE* out);
int tutDecryption(int alphabetLength, int shiftAmout, FILE* in, FILE* out);
//int checkSqua(char* currentbuffer, char* targetChars, int targetLength);
int tutEncryptionWrite(char targetWrite, FILE * out, int readUpper);
int tutEncryptionWriteDouble(FILE * out);
int writeOneChar(FILE * out, char targetWrite, int readUpper);
//int checkBuffer(char* currentbuffer);
//int cleanBuffer(char* currentbuffer);
void checkBuffer();
void cleanBuffer();
//int searchTargetWord(char* currentbuffer, char targetChar, FILE* out);
//int writeBuffertoFile(char *targetBuffer, FILE * out);
//int oldContentBuffer(char* currentbuffer, FILE * out);

int checkSqua(char* targetChars, int targetLength);
int matchBufferWithArray(FILE * out);

//int searchTargetWordNew(char* currentbuffer, char targetChar, int curretBufferLength);

#define USAGE(retcode) do{                                                        \
fprintf(stderr, "%s\n",                                                           \
"usage: ./hw1 [-s | -t | -h]\n"                                                   \
"    -s       Substitution cipher\n"                                              \
"             Additional parameters: [-e | -d] n INPUT_FILE OUTPUT_FILE\n"        \
"                 -e           Encrypt using the substitution cipher.\n"          \
"                 -d           Decrypt using the substitution cipher.\n"          \
"                  n           The amount of position to shift by.\n"             \
"                  INPUT_FILE  This can be any file on the file system or '-'\n"  \
"                              which specifies stdin.\n"                          \
"                  OUTPUT_FILE This can be any file on the system or '-'\n"       \
"                              which specifies stdout.\n"                         \
"\n"                                                                              \
"    -t       Tutnese Translation\n"                                              \
"             Additional parameters: [-e | -d]   INPUT_FILE OUTPUT_FILE\n"        \
"                 -e          Encode into tutnese\n"                              \
"                 -d          Decode from tutnese (extra credit)\n"               \
"                 INPUT_FILE  This can be any file on the file system or '-'\n"   \
"                             which specifies stdin\n"                            \
"                 OUTPUT_FILE This can be any file on the system or '-'\n"        \
"                             which specifies stdout.\n"                          \
"\n"                                                                              \
"    -h       Display this help menu.");                                          \
exit(retcode);                                                                    \
} while(0)

#endif
