#include "endn.h"
#include "info.h"
#include "debug.h"

int main(int argc, char **argv) {

    FILE* in;
    FILE* out;

    /* Note: create a variable to assign the result of validargs */
    int result = validargs(argc, argv, &in, &out);
    //printf("result: %d\n", result);
    // debug("This is a test debug");
    //char bit7 = result &  128;
    //char bit6 = result & 64;
    char bit5 = result & 32;
   // char lowerBits = result & 31;

    //if(result!=0 && result!=128){//if not error or -h
	    DINFO("INFO: shifted alphabet: %s", Alphabet);
	    DINFO("\n");
	    DINFO("INFO: shift amount: %s",*(argv+5));
	    DINFO("\n");
	    DINFO("INFO: input file: %s", *(argv+3));
	    DINFO("\n");
	    DINFO("INFO: output file: %s", *(argv+4));
	    DINFO("\n");
	    if(bit5==32){
	    	DINFO("INFO: operation: decryption\n");
	    }else{
	    	DINFO("INFO: operation: encryption\n");
		}
	//}
    //DINFO("2 debug flag was defined\n", stderr);

    //fprintf(stderr, "%s\n", "hehe");
        USAGE(EXIT_FAILURE);
    //out = stderr;
	//printf("\n +++dd+++++++++ result : %d \n", result);
  //   if(result == 0 || result == -1){
  //   	//printf("++++++++++++ zero : %d \n", result);
  //   	if (in!=NULL){
  //   		fclose(in);
  //   	}
		// fclose(out);
  //   	USAGE(EXIT_FAILURE);
  //   	return EXIT_FAILURE;
  //   }

  //   int resulth = result & 0x80;
  //   if(resulth == 0x80){
  //   	if (in!=NULL){
  //   		fclose(in);
  //   	}
		// fclose(out);
  //   	USAGE(EXIT_SUCCESS);
  //   	return EXIT_SUCCESS;
  //   }

    if (in!=NULL){
    	fclose(in);
    }
	fclose(out);
    return EXIT_SUCCESS;
}