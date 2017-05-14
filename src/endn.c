#include "endn.h"
// For your helper functions (you may add additional files also)
// DO NOT define a main function here!

char validargs(int argc, char** argv, FILE** in, FILE** out) {
	char ret = 0; // for failure
	int n = 320; // default value for n

	int alphabetLength = string_length(Alphabet);

	if(argc < 2 || argc > 6){
		return ret;
	}

	int strlen = string_length(*(argv + 1)); // 2nd arg flag

	if(strlen != 2){
		ret = ( ret | 0x00 ) & 0x00;
		return ret;
	}else{

		char vaildflag = get_flag(*(argv + 1));

		// s flag is for part 2
		if(vaildflag == 's'){
			ret = ( ret | 0x40 ) & 0x40;

			if(argc > 5){
				int nLength = string_length(*(argv + 5));
				n = charToDecimal(*(argv + 5), nLength);
				n = n%alphabetLength;
				ret = ret | n;
				//return ret;
			}
		// end s flag is for part 2
		}else if(vaildflag == 't'){
			ret = ( ret | 0x00 ) & 0x00;
			n = n%alphabetLength;
			ret = ret | n;
		}else if(vaildflag == 'h'){
			ret = ( ret | 0x80 );// & 0x80;
			return ret;
		}else{
			ret = ( ret | 0x00 ) & 0x00;
			return ret;
		}
	}

	strlen = string_length(*(argv + 2));  // 3rd arg flag
	if(strlen != 2){
		ret = ( ret | 0x00 ) & 0x00;
		//USAGE(EXIT_FAILURE);
		return ret;
	}else{
		char vaildflag2 = get_flag(*(argv + 2));

		if(vaildflag2 == 'e'){
			ret = ( ret | 0x00 ) ;//& 0x00;
			int checkFlag = 0;
			checkFlag = ret & 0x40; // check  it has -s flag

			// check  it has -s flag  ( -s -e )
			if(checkFlag == 0x40){
				int openFilelen = string_length(*(argv + 3)); // 4th arg = input file
				int outFilelen = string_length(*(argv + 4)); // 5th arg
					if(outFilelen == 1){
						*out = stdout;
					}else{
						*out = fopen(*(argv + 4), "w");
						if(*out == NULL){
						}
					}

				if(openFilelen == 1){
					*in = stdin;
				}else{
					*in = fopen(*(argv + 3), "r");
					if(*in == NULL){
						ret = ( ret | 0x00 ) & 0x00;
						return ret;
					}else{
						encryption(alphabetLength, n, *in, *out);
					}

				}

			}//end if(checkFlag == 0x40)
			else{
			// check  it has -t flag
				int openFilelen = string_length(*(argv + 3)); // 4th arg = input file
				int outFilelen = string_length(*(argv + 4)); // 5th arg

				if(outFilelen == 1){
					*out = stdout;
				}else{
					*out = fopen(*(argv + 4), "w");

					if(*out == NULL){
					}
				}


				if(openFilelen == 1){
					*in = stdin;
				}else{

					*in = fopen(*(argv + 3), "r");
					if(*in == NULL){
						ret = ( ret | 0x00 ) & 0x00;
						return ret;
					}else{
						tutEncryption(alphabetLength, n, *in, *out);

					}
				}
			}

		}else if(vaildflag2 == 'd'){
			ret = ( ret | 0x20 );// & 0x20;

			int checkFlag = 0;
			checkFlag = ret & 0x40; // check  it has -s flag

			// check  it has -s flag
			if(checkFlag == 0x40){

				int openFilelen = string_length(*(argv + 3)); // 4th arg = input file
				int outFilelen = string_length(*(argv + 4)); // 5th arg

					if(outFilelen == 1){
						*out = stdout;
					}else{
						*out = fopen(*(argv + 4), "w");
						if(*out == NULL){
						}else{
						}
					}




				if(openFilelen == 1){
					*in = stdin;
				}else{

					*in = fopen(*(argv + 3), "r");
					if(*in == NULL){
						ret = ( ret | 0x00 ) & 0x00;
						return ret;
					}else{
						decryption(alphabetLength, n, *in, *out);

					}

				}

			} // end -s -d flag
			else{ // -t -d case
				int openFilelen = string_length(*(argv + 3)); // 4th arg = input file
				int outFilelen = string_length(*(argv + 4)); // 5th arg

				if(outFilelen == 1){
					*out = stdout;
				}else{
					*out = fopen(*(argv + 4), "w");

					if(*out == NULL){
					}
				}


				if(openFilelen == 1){
					*in = stdin;
				}else{

					*in = fopen(*(argv + 3), "r");
					if(*in == NULL){
						ret = ( ret | 0x00 ) & 0x00;
						return 0;
					}else{
						tutDecryption(alphabetLength, n, *in, *out);
					}

				}

			} // end -t -d case

		} 		// end of -d case
		else{ //invaild case : none of -e and -d
			ret = ( ret | 0x00 ) & 0x00;
			return EXIT_FAILURE;
		}
	}
	return ret;
}

int string_compare(char * str1, char * str2){
	if (string_length(str1) > string_length(str2)){
		return 1;
	}else if (string_length(str1) < string_length(str2)){
		return -1;
	}else{
		char * pointer1 = str1;
		char * pointer2 = str2;
		while(*pointer1 != 0x0){
			if(*pointer1 > *pointer2){
				return 1;
			}else if(*pointer1 < *pointer2){
				return -1;
			}
		}
		return 0;
	}
}

int checkSqua(char* targetChars, int targetLength){
    char* tempBuffer = buffer;
    // If current buffer is empty
    if(*tempBuffer == 0x00){
        return -1;
    }

    int result = 1;
    int tempLength = targetLength;

    while(tempLength != 0){
        if(*tempBuffer != *targetChars){
            return -1;
        }
        tempBuffer++;
        targetChars++;

        tempLength--;
    }

    return result;
}

int string_length(char * str){
    char * pointer = str;
    int count = 0;
    int stop = 0;

    while(stop == 0){
        count++;
        pointer++;

        if(*pointer== 0x0){
            stop++;
        }

    }
    return count;
}


int charToDecimal(char * str, int nLength){
	char * pointer = str;
	int decimalNum = 0;
	int tempNum = 0;
	int stop = 0;
	int powerStop = nLength;

	while(stop != nLength){
		tempNum = *pointer - '0';

		int power = 1;
		int i = 0;
		while(++i <powerStop){
			power *= 10;
		}

		tempNum = tempNum * power;
		decimalNum = decimalNum + tempNum;
		pointer++;
		stop++;
		powerStop--;

		if(*pointer== 0x0){
			break;
		}

	}
	return decimalNum;
}

char get_flag(char * str){
	char * pointer = str;

	if(*pointer != '-'){
		return '0';
	}

	pointer++;
	// check the 2nd character is letter
	if((((*pointer) >= 'A') && ((*pointer) <= 'Z')) || (((*pointer) >= 'a') && ((*pointer) <= 'z'))){
		//printf("%s %c \n", "the given flag is : ", (*pointer));
		if(*pointer == 'h'){
			return 'h';
		}else if(*pointer == 'e'){
			return 'e';
		}else if(*pointer == 's'){
			return 's';
		}else if(*pointer == 't'){
			return 't';
		}else if(*pointer == 'd'){
			return 'd';
		}else{
			return '0';
		}
	}

	return '0';
}


int encryption(int alphabetLength, int shiftAmout, FILE* in, FILE* out){


	char c = 0;

   	do{
      	c = fgetc(in);	// input character
      	//printf("%s %d \n", "c: ", c);



		if( feof(in) )
		{
			//printf("%s  \n", " file is end of file ");

			break ;
		}

		if(c>='a' && c<='z'){     // lower case to upper case
			c -= 32;
        }

		char * x = Alphabet;

		int count = 0;
		int isFound = 0;

		while(*x!=0x0){
			if(c == *x){	// If the input character is same with character in Alphabet
				//if(count < (sizeof(Alphabet)/sizeof(Alphabet[0]) - (n+1))){
				// count is the index number of input character  < 30 - 3
				if(count < (alphabetLength - shiftAmout)){

					for(int i =0; i < shiftAmout;i++){
						x++;
					}
					fputc(*x, out);
					isFound = 1;
				}else if(count < alphabetLength){
					x =  Alphabet;
					int backWards = count - (alphabetLength - shiftAmout); // 28 - 27 = 1
					for(int i = 0; i < backWards;i++){
						x++;
					}
					isFound = 1;
					fputc(*x, out);
				}
				break;  // if it is found, break
			}
			x++;
			count++;
		}
		if(isFound == 0){
			fputc(c, out);
		}

	}while(1);

	//fclose(in);
	//fclose(out);
	return 0;
}



int decryption(int alphabetLength, int shiftAmout, FILE* in, FILE* out){

	char c = 0;

	char * lastCharFinder = Alphabet  + sizeof(char);
	char * prevCharacter = Alphabet;

	while(*lastCharFinder!=0x0){
		lastCharFinder++;
		prevCharacter++;
	}

   	do{
      	c = fgetc(in);

		if( feof(in) )
		{
			break ;
		}

		char * x = Alphabet;
		int count = 0;
		int isFound = 0;
		while(*x!=0x0){

			if(c == *x){
				if(count >=shiftAmout ){
					for(int i =0;i <shiftAmout;i++){
						x--;
					}
					fputc(*x, out);
					isFound = 1;
				}
				else{
					x =  prevCharacter;
					for(int i = 0; i < (shiftAmout-1)-count;i++){
						x--;
					}
					isFound = 1;
					fputc(*x, out);
				}
				break;
			}
			x++;
			count++;
		}
		if(isFound == 0){
			//printf("%c", c);
			fputc(c, out);
		}
	}while(1);
	//fclose(in);
	//fclose(out);

	return 0;
}


int tutEncryption(int alphabetLength, int shiftAmout, FILE* in, FILE* out){
	char c = 0;
	int cReadUpper = 0;
	int bufferReadUpper = 0;
	char * ptrbuffer = buffer;
	int doublePrinted = 0;

   	do{
   		if(cReadUpper == 0){
   			bufferReadUpper = 0;
   		}else{
   			bufferReadUpper = 1;
   		}
   		*ptrbuffer = c;

   		c = fgetc(in);	// input character

      	if( feof(in) ){
      		if(*ptrbuffer != 0x00){
      			tutEncryptionWrite(*ptrbuffer, out, bufferReadUpper);
      		}
			break;

		}else{
			if(c>='a' && c<='z'){ 	// lower case to upper case
				cReadUpper = 0;
			}else if(c>='A' && c<='Z'){ 	// upper case to lower case
		  		cReadUpper = 1;
		  		c += 32;
			}else{
				cReadUpper = 0;
			}
		}

		////////////////////////////////////////////////////////////////////////

      	if(c == *ptrbuffer && doublePrinted == 0){

      		doublePrinted = 1;

      		if( ((c >= 'A') && (c <= 'Z')) ||  ((c >= 'a') && (c <= 'z'))  ){
      			writeOneChar(out, 's', bufferReadUpper);
	      		tutEncryptionWriteDouble(out);

	      		if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
	      			writeOneChar(out, 't', 0);
	      		}
      		}else{
	      		writeOneChar(out, *ptrbuffer, bufferReadUpper);
      		}
      	}else{
      		doublePrinted = 0;
      		if(*ptrbuffer != 0x00){
      			tutEncryptionWrite(*ptrbuffer, out, bufferReadUpper);
      		}
      	}

	}while(1);
	return 0;
}



int tutDecryption(int alphabetLength, int shiftAmout, FILE* in, FILE* out){
	char c = 0;
    char tempC = 0;
    char * ptrbuffer = buffer;
    int cReadUpper = 0;

    while(1){
        c = fgetc(in);

        if(((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z')) || c == EOF ) {

            if( feof(in) ){
                ptrbuffer = buffer;
                if(*ptrbuffer == 0x00){
                    break;
                }else{
                    int resultSquat = checkSqua("squat", 5);

                    if(resultSquat == 1){
                        // print tt case
                        *ptrbuffer = 't';

                        if(cReadUpper == 1){
                            cReadUpper = 0;

                            char lowerChar = *ptrbuffer;
                            lowerChar -= 32;

                            fputc(lowerChar, out);

                            if(c>='A' && c<='Z'){
                                cReadUpper = 0;
                                fputc(c, out);
                            }else{
                                fputc(lowerChar, out);
                            }

                        }else{

                            fputc(*ptrbuffer, out);
                            if(c>='A' && c<='Z'){
                                cReadUpper = 0;
                                fputc(c, out);
                            }else{
                                char lowerCharT = *ptrbuffer;
                                lowerCharT -= 32;

                                fputc(lowerCharT, out);
                            }
                        }
                        // save the new char into buffer
                        cleanBuffer();
                        ptrbuffer = buffer;
                    }else{
                        //printf("    ");
                        // check the buffer contains "squa"
                        int resultSqua = checkSqua("squa", 4);
                        if(resultSqua == 1 && tempC != 't'){
                            cleanBuffer();
                            ptrbuffer = buffer;
                            //printf("[[[[[[[[[[[ error ]]]]]]]]]]");
                            return 0;
                        }else{
                            // if the word is none of them, just keep saving it into buffer
                            int resultMatching = matchBufferWithArray(out);

                            if(resultMatching == 1){
                                ptrbuffer = buffer;

                                if(cReadUpper == 1){
                                    cReadUpper = 0;
                                    char lowerChar = *ptrbuffer;
                                    lowerChar -= 32;
                                    fputc(lowerChar, out);

                                }else{
                                    fputc(*ptrbuffer, out);
                                }
                                break;
                            } // end if(resultMatching == 1)


                            else if(resultMatching == -1){
                                // return error
                                //printf("[[[[[[[[[[[ error ]]]]]]]]]]");
                                return -1;
                            } // end else if(resultMatching == -1)

                            else if(resultMatching == 0){
                                // this is vowel word or other case
                                fputc(*ptrbuffer, out);
                                cleanBuffer();
                                ptrbuffer = buffer;
                            } // end else if(resultMatching == 0)

                        } // end if(resultSqua == 1 && tempC != 't')

                    } // end if(resultSquat == 1)

                    break;
                }

            }
//-------- ---------------------------------------- Lower & Upper
            if(c>='a' && c<='z'){     // lower case to upper case
                //cReadUpper = 0;
                tempC = c;
            }else if(c>='A' && c<='Z'){     // upper case to lower case
                //isCapital = true;
                if(*buffer == 0){
                    cReadUpper = 1;
                }else{
                }

                tempC = c;
                tempC += 32;
            }else{
                tempC = c;
            }
//------------------------------------------------- Lower & Upper

            int resultSquat = checkSqua("squat", 5);
            if(resultSquat == 1){
                cleanBuffer();
                ptrbuffer = buffer;
                if(tempC == 'a' || tempC == 'e' ||tempC == 'i' ||tempC == 'o' ||tempC == 'u'){
                    *ptrbuffer = tempC;

                    if(cReadUpper == 1){
                        cReadUpper = 0;

                        char lowerChar = *ptrbuffer;
                        lowerChar -= 32;

                        fputc(lowerChar, out);

                        if(c>='A' && c<='Z'){
                            cReadUpper = 0;
                            fputc(c, out);
                        }else{
                            lowerChar += 32;
                            fputc(lowerChar, out);
                        }

                    }else{

                        fputc(*ptrbuffer, out);

                        if(c>='A' && c<='Z'){
                            cReadUpper = 0;
                            fputc(c, out);
                        }else{
                            fputc(*ptrbuffer, out);
                        }

                    }
                    cleanBuffer();
                    ptrbuffer = buffer;
                }else{
                    // print tt case
                    *ptrbuffer = 't';

                    if(cReadUpper == 1){
                            cReadUpper = 0;

                            char lowerChar = *ptrbuffer;
                            lowerChar -= 32;

                            fputc(lowerChar, out);

                            if(c>='A' && c<='Z'){
                                cReadUpper = 0;
                                fputc(c, out);
                            }else{
                                lowerChar += 32;
                                fputc(lowerChar, out);
                            }

                        }else{

                            fputc(*ptrbuffer, out);
                            if(c>='A' && c<='Z'){
                                cReadUpper = 0;
                                fputc(c, out);
                            }else{
                                char lowerCharT = *ptrbuffer;
                                lowerCharT -= 32;

                                fputc(lowerCharT, out);
                            }
                        }
                    // save the new char into buffer
                    cleanBuffer();
                    ptrbuffer = buffer;
                    *ptrbuffer = tempC;
                }
            }else{
                // check the buffer contains "squa"
                int resultSqua = checkSqua("squa", 4);
                if(resultSqua == 1 && tempC != 't'){
                   	cleanBuffer();
                    ptrbuffer = buffer;

                    *ptrbuffer = tempC;

                    if(cReadUpper == 1){
                        cReadUpper = 0;
                        char lowerChar = *ptrbuffer;
                        lowerChar -= 32;
                        fputc(lowerChar, out);
                    }else{
                        fputc(*ptrbuffer, out);
                    }

                    *ptrbuffer = tempC; // save the char to check the word
                    ptrbuffer++;

                    if(c>='A' && c<='Z'){
                        cReadUpper = 1;
                    }
                }else{
                    // if the word is none of them, just keep saving it into buffer
                    int resultMatching = matchBufferWithArray(out);
                    if(resultMatching == 1){
                    	ptrbuffer = buffer;

                        if(cReadUpper == 1){
                            cReadUpper = 0;

                            char lowerChar = *ptrbuffer;
                            lowerChar -= 32;

                            fputc(lowerChar, out);
                        }else{
                            fputc(*ptrbuffer, out);
                        }

                        cleanBuffer();

                        ptrbuffer = buffer;
                        *ptrbuffer = tempC;
                        ptrbuffer++;

                        if(c>='A' && c<='Z'){
                            cReadUpper = 1;
                        }

                    } // end if(resultMatching == 1)


                    else if(resultMatching == -1){
                        // no matched any word in array
                        // so check that word is squa or squat
                                // if the word is none of them, just keep saving it into buffer
                                *ptrbuffer = tempC;
                                ptrbuffer++;

                    } // end else if(resultMatching == -1)


                    else if(resultMatching == 0){
                        // this is vowel word or other case
                        ptrbuffer = buffer;

                        if(cReadUpper == 1){
                            cReadUpper = 0;

                            char lowerChar = *ptrbuffer;
                            lowerChar -= 32;

                            fputc(lowerChar, out);
                        }else{
                            fputc(*ptrbuffer, out);
                        }

                        cleanBuffer();
                        ptrbuffer = buffer;
                        *ptrbuffer = tempC;
                        ptrbuffer++;
                    } // end else if(resultMatching == 0)

                } // end if(resultSqua == 1 && tempC != 't')

            } // end if(resultSquat == 1)
        } // end if(((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z')) || c == EOF )
        else{
            int resultSquatForSpecial = checkSqua("squat", 5);
            if(resultSquatForSpecial == 1){
                cleanBuffer();
                ptrbuffer = buffer;

                    // only tt case is available
                    *ptrbuffer = 't';

                    if(cReadUpper == 1){
                        cReadUpper = 0;

                        char lowerChar = *ptrbuffer;
                        lowerChar -= 32;

                        fputc(lowerChar, out);
                        fputc(lowerChar, out);
                    }else{
                        fputc(*ptrbuffer, out);
                        fputc(*ptrbuffer, out);
                    }

                    // save the new char into buffer
                    cleanBuffer();
                    ptrbuffer = buffer;
                    fputc(tempC,out); // print symbol

            }else{

                int resultSquaForSpecial = checkSqua("squa", 4);
                if(resultSquaForSpecial == 1){

                    return 0; // wrong case

                }else{

                    int resultMatchingForSpecial = matchBufferWithArray(out);

                    if(resultMatchingForSpecial == 1){
                      //  printf("matched word @: %c %p \n", *ptrbuffer, (void *)(ptrbuffer));
                        ptrbuffer = buffer;

                        if(cReadUpper == 1){
                            cReadUpper = 0;

                            char lowerChar = *ptrbuffer;
                            lowerChar -= 32;

                            fputc(lowerChar, out);
                        }else{
                            fputc(*ptrbuffer, out);
                        }

                        cleanBuffer();
                        ptrbuffer = buffer;
                        fputc(c,out); // print symbol
                        //checkBuffer();
                    } // end if(resultMatching == 1)


                    else if(resultMatchingForSpecial == -1){

                        fputc(c,out); // print symbol

                    } // end else if(resultMatching == -1)

                    else if(resultMatchingForSpecial == 0){

                        // this is vowel word or empty buffer
                        ptrbuffer = buffer;
                        if(*ptrbuffer != 0x00){
                            if(cReadUpper == 1){
                                cReadUpper = 0;

                                char lowerChar = tempC;
                                lowerChar -= 32;

                                fputc(lowerChar, out);
                            }else{
                                fputc(tempC, out);
                            }
                        }

                        cleanBuffer();
                        ptrbuffer = buffer;
                        fputc(c,out); // print symbol

                    } // end else if(resultMatching == 0)

                } // end if(resultSquaForSpecial == 1 && tempC != 't')

            } // end if(resultSquatForSpecial == 1)
        }
    } // end  while(1)
    //fclose(out);
    return 0;
}


int tutEncryptionWrite(char targetWrite, FILE * out, int readUpper){
	int status = 0;
	int isFoundx = 0;
	char ** ptrTutnesex = Tutnese;

	while(*ptrTutnesex != 0x00){
		if(targetWrite == **ptrTutnesex){

			char * ptrRead = *ptrTutnesex;

			while(*ptrRead !=0x00){
				//printf("%c", *ptrRead);
				if(readUpper == 1){
					char convert = *ptrRead;
					convert -= 32;
					fputc(convert, out);
					readUpper = 0;
				}else{
					fputc(*ptrRead, out);
				}
				isFoundx = 1;
				ptrRead++;
			}
		}else{
			//isFoundx = false;
			//readUpper = 0;
		}
		ptrTutnesex++;
	}

	if(isFoundx == 0){
		if(readUpper == 1){
			char convert = targetWrite;
			convert -= 32;
			fputc(convert, out);
			readUpper = 0;
		}else{
			fputc(targetWrite, out);
		}
	}

	return status;
}

int tutEncryptionWriteDouble(FILE * out){
	char* doubleQua = "qua";

	while(*doubleQua!=0x00){
		char getC = *doubleQua;
		fputc(getC, out);
		doubleQua++;
	}
	return 0;
}

int writeOneChar(FILE * out, char targetWrite, int readUpper){
	// get lower case of s. if readUpper is 1, print s as uppper
	if(readUpper == 0){
		fputc(targetWrite, out);
	}else{
		targetWrite -= 32;
		fputc(targetWrite, out);
	}
	return 0;
}

void checkBuffer(){
    char* currentbuffer = buffer;
    int count = 0;
    while(*currentbuffer != '\0'){
        count++;
        currentbuffer++;
    }
}

void cleanBuffer(){
    char * currentbuffer = buffer;
    while(*currentbuffer != '\0'){
        *currentbuffer = '\0';
        currentbuffer++;
    }
}


int matchBufferWithArray(FILE * out){
    char* ptrCurrentbuffer = buffer;
    char ** ptrTutnese = Tutnese;

    if(*ptrCurrentbuffer == 'a' || *ptrCurrentbuffer == 'e' || *ptrCurrentbuffer == 'i' || *ptrCurrentbuffer == 'o' || *ptrCurrentbuffer == 'u'){
        return 0;
    }

    if(*ptrCurrentbuffer == 0x00){
        return -1;
    }

    int result = 1;

    while(*ptrTutnese != 0x00){ // check array[i]

        if(**ptrTutnese == *ptrCurrentbuffer){

            char* ptrWordInArray = *ptrTutnese;
            int leng1 = string_length(ptrWordInArray);
            int leng2 = string_length(ptrCurrentbuffer);

            if(leng1 == leng2 ){

                char* wordArray = *ptrTutnese;
                char* wordbuffer = buffer;

                for(int i = 0; i < leng1;i++){
                //this checks character by character until the null is hit
                    if(*wordArray != *wordbuffer){
                        result = -1;
                    }
                    wordbuffer++;
                    wordArray++;
                }

                if(result == 1){
                    result = 1;
                }
                return result;
            }else{
                result = -1;
            }
        }
        ptrTutnese++;
    }
    return result;
}
