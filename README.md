# Big string in C 
This c code implements a dynamic string object in C. Using the custom object bigString and the given methods someone can create a dynamic string without doing the allocation of the memmory manually. Tfe freeing of the memmory should be done manually with free.

## Usage 
```C
bigString *myBigString;
myBigString = initializeString();
myBigString = addCharacter(myBigString, 'a');
myBigString = addCharacter(myBigString, 'b');

printf("Print the bigstring content:%s\n", myBigString->text);
free(myBigString->text);
free(myBigString);
```


## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details
