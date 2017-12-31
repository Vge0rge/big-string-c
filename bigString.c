//Set the buffersize, this the amount of bytes that will be allocated when you initialize a big string
unsigned int BUFFSIZE = 512;

typedef struct bigString{
    char *text; // The contents of the string
    unsigned long textCounter;// The actual size of the string, excluding the null character 
    unsigned int numOfBuffs; // The number of buffers that the strings consists of 
}bigString;

// Initializes a bigString object and it returns a pointer to that object or NULL if unsucessful
struct bigString* initializeString(void){
    struct bigString *myBigString;

    myBigString = malloc(sizeof(struct bigString));
    if( myBigString == NULL ){
        return NULL;
    }

    myBigString->text = malloc(BUFFSIZE * sizeof(char));
    if( myBigString->text == NULL ){
	free(myBigString);
        return NULL;
    }

    myBigString->text[0] = '\0';
    myBigString->textCounter = 0;
    myBigString->numOfBuffs = 1;

    return myBigString;
}

// Adds a character to the big string, returns a pointer to the new object or NULL on failure
struct bigString* addCharacter(struct bigString *myBigString, char newChar){
    char *tempPnt;
    // Check if the textCounter (including the null temrinator, thus the +1) is greater than our buffer size
    if ( (myBigString->textCounter + 1) < (myBigString->numOfBuffs * BUFFSIZE) ){
	    myBigString->text[myBigString->textCounter] = newChar;
	    myBigString->textCounter++;
	    myBigString->text[myBigString->textCounter] = '\0';
    }else{
	    myBigString->numOfBuffs++;
	    tempPnt = realloc( myBigString->text , (myBigString->numOfBuffs*BUFFSIZE) * sizeof(char) );
	    if ( tempPnt == NULL ){
		    free(myBigString->text);
		    free(myBigString);
		    return NULL;
	    }

	    myBigString->text = tempPnt;
	    myBigString->text[myBigString->textCounter] = newChar;
	    myBigString->textCounter++;
	    myBigString->text[myBigString->textCounter] = '\0';
    }

    return  myBigString;
}


