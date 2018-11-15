#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

char ** parse_args( char *line) {

	// I don't want to modify line.
	char *dummy = malloc(strlen(line) * sizeof(char));
    strcpy(dummy, line);

    // At most 5 arguments of strings (array of chars / char pointers) 
	char **separated = calloc( 6 , sizeof(char*) );
	
	for (int i = 0; dummy; i++) { 
	// i is the current arg of separated, dummy keeps getting split until you hit the NULL at the end
		separated[i] = strsep(&dummy, " "); 
	}

	return separated;	
}

int main() {
	// printf("What is your command?\n");
	// char line[128];
	// scanf("%s",line);
 //  	char ** args = parse_args( line );
 //  	execvp(args[0], args);
 //  	return 0;
	printf("Doing command 'ls -l -a'\n");
	char line[100] = "ls -a -l";
  	char ** args = parse_args( line );
  	execvp(args[0], args);
  	return 0;
}