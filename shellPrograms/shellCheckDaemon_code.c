#include "shellPrograms.h"

/*  A program that prints how many summoned daemons are currently alive */
int shellCheckDaemon_code()
{

	/* TASK 8 */
	//Create a command that trawl through output of ps -efj and contains "summond"
	char *command = malloc(sizeof(char) * 256);
	sprintf(command, "ps -efj | grep summond  | grep -v tty > output.txt");

	// TODO: Execute the command using system(command) and check its return value
	int ret_val = system(command);
	if (ret_val == -1){exit(1);}
	free(command);

	int live_daemons = 0;
	// TODO: Analyse the file output.txt, wherever you set it to be. You can reuse your code for countline program
	// 1. Open the file
	FILE* fp = fopen("output.txt", "r");
	
	// Check if file exists
	if (fp == NULL){
		printf("Output file does not exist!\n");
		exit(1);
	}
	
	// 2. Fetch line by line using getline()
	char* buffer;
	size_t bufsize = 256;
	buffer = (char *)malloc(bufsize * sizeof(char));
    if( buffer == NULL)
    {
        perror("Unable to allocate buffer.\n");
        exit(1);
    }
	size_t line;
	line = getline(&buffer,&bufsize,fp);
	
	// 3. Increase the daemon count whenever we encounter a line
	while(line != -1){
		live_daemons++;
		line = getline(&buffer,&bufsize,fp);
	}
	
	// 4. Close the file
	fclose(fp);
	
	// 5. print your result
	if (live_daemons == 0)
	  printf("No daemon is alive right now\n");
	else
	{
	  printf("There are in total of %d live daemons \n", live_daemons);
	}


	// TODO: close any file pointers and free any statically allocated memory 
	fclose(fp);
	free(buffer);
	return 1;
}

int main(int argc, char **args)
{
   return shellCheckDaemon_code();
}