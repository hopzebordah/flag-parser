// i wanted to work through the process of finding command line arguments
// in traditional c, without using the likes of getopt as a challenge to 
// myself. it turned out okay, not very pretty or efficient but it gets
// the job done. i use the method strcpy(), the strings are NOT 
// dynamically allocated, and the program does not check for the validity 
// of filenames and such --- so i wouldn't use this for anything unless you 
// plan on fixing this yourself. let me know if you have any suggestions
// that i can implement. thx
// 	https://github.com/hopzebordah/flag-parser

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
	int numberOfKnownFlags = 3;
	
	//known flags
	int help = 0;
	int input = 0;
	char inputFilename[50];
	int output = 0;
	char outputFilename[50];
	
	int i = 1;
	for (i; i<argc; ++i)
	{
		if (argv[i][0] == '-')
		{
			if (strcmp(argv[i], "-h") == 0) {
				help = 1;
				printf("YOU ASKED FOR THE HELPSCREEN\n"); 
				exit(0);
			}
			else if (strcmp(argv[i], "-o") == 0) {
				if (!output) {
					output = 1;
					strcpy(outputFilename, argv[i + 1]);
				}
				else {
					printf("Error: duplicate flag %s\n", argv[i]);
					exit(1);
				}
			}
			else if (strcmp(argv[i], "-i") == 0) {
				if (!input) {
					input = 1;
					strcpy(inputFilename, argv[i + 1]);
				}
				else {
					printf("Error: duplicate flag %s\n", argv[i]);
					exit(1);
				}
			}
			else {
				printf("Error: Unknown option %s\n", argv[i]); 
				exit(2);
			}
		}
	}
	if (!input)
	{
		printf("Error: no input supplied\n");
		exit(3);
	}
	if (!output)
	{
		strcpy(outputFilename, "default.txt");
	}
		
	printf("input filename: %s\n", inputFilename);
	printf("output filename: %s\n", outputFilename);

	return 0;
}
