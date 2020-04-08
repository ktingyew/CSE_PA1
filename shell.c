#include "shell.h"

/*
 List all files matching the name in args[1] under current directory and subdirectories
*/
int shellFind(char **args)
{

	printf("shellFind is called!\n");

	/** TASK 4 **/
	// 1. Execute the binary program 'find' in shellPrograms using execvp system call
	// 2. Check if execvp is successful by checking its return value
	// 3. A successful execvp never returns, while a failed execvp returns -1
	// 4. Print some kind of error message if it returns -1
	// 5. return 1 to the caller of shellFind if execvp fails to allow loop to continue
	int ret_val = execvp("/mnt/c/Users/kting/Desktop/PA1/shellPrograms/find", args);
	if (ret_val == -1){
		printf("There is error in using find!\n");
		return 1;
	}

}

/**
 Allows one to display the content of the file
 */
int shellDisplayFile(char **args)
{
	printf("shellDisplayFile is called!\n");

	/** TASK 4 **/
	// 1. Execute the binary program 'display' in shellPrograms using execvp system call
	// 2. Check if execvp is successful by checking its return value
	// 3. A successful execvp never returns, while a failed execvp returns -1
	// 4. Print some kind of error message if it returns -1
	// 5. return 1 to the caller of shellDisplayFile if execvp fails to allow loop to continue
	int ret_val = execvp("/mnt/c/Users/kting/Desktop/PA1/shellPrograms/display", args);
	if (ret_val == -1){
		printf("There is error in using display!\n");
		return 1;
	}

}

/*
	List the items in the directory and subdirectory
*/
int shellListDirAll(char **args)
{

	printf("shellListDirAll is called!\n");

	/** TASK 4 **/
	// 1. Execute the binary program 'listdirall' in shellPrograms using execvp system call
	// 2. Check if execvp is successful by checking its return value
	// 3. A successful execvp never returns, while a failed execvp returns -1
	// 4. Print some kind of error message if it returns -1
	// 5. return 1 to the caller of shellListDirAll if execvp fails to allow loop to continue
	
	int ret_val = execvp("/mnt/c/Users/kting/Desktop/PA1/shellPrograms/listdirall", args);
	if (ret_val == -1){
		printf("There is error in using listdirall!\n");
		return 1;
	}
	
}

/*
	List the items in the directory
*/
int shellListDir(char **args)
{
	printf("shellListDir is called!\n");

	/** TASK 4 **/
	// 1. Execute the binary program 'listdir' in shellPrograms using execvp system call
	// 2. Check if execvp is successful by checking its return value
	// 3. A successful execvp never returns, while a failed execvp returns -1
	// 4. Print some kind of error message if it returns -1
	// 5. return 1 to the caller of shellListDir

	int ret_val = execvp("/mnt/c/Users/kting/Desktop/PA1/shellPrograms/listdir", args);
	if (ret_val == -1){
		printf("There is error in using listdir!\n");
		return 1;
	}
}

/**
   Counts how many lines are there in a text file. 
   A line is terminated by \n character
**/
int shellCountLine(char **args)
{
	printf("shellCountLine is called!\n");

	/** TASK 4 **/
	// 1. Execute the binary program 'countline' in shellPrograms using execvp system call
	// 2. Check if execvp is successful by checking its return value
	// 3. A successful execvp never returns, while a failed execvp returns -1
	// 4. Print some kind of error message if it returns -1
	// 5. return 1 to the caller of shellCountLine if execvp fails to allow loop to continue

	int ret_val = execvp("/mnt/c/Users/kting/Desktop/PA1/shellPrograms/countline", args);
	if (ret_val == -1){
		printf("There is error in using countline!\n");
		return 1;
	}
}

/**
 * Allows one to create a daemon process
 */
int shellSummond(char **args)
{
	printf("shellDaemonize is called!\n");

	/** TASK 4 **/
	// 1. Execute the binary program 'summond' in shellPrograms using execvp system call
	// 2. Check if execvp is successful by checking its return value
	// 3. A successful execvp never returns, while a failed execvp returns -1
	// 4. Print some kind of error message if it returns -1
	// 5. return 1 to the caller of shellDaemonize if execvp fails to allow loop to continue

	int ret_val = execvp("/mnt/c/Users/kting/Desktop/PA1/shellPrograms/summond", args);
	if (ret_val == -1){
		printf("There is error in using summond!\n");
		return 1;
	}

}


/**
 * Allows one to check daemon process
 * 
 */
int shellCheckDaemon(char **args)
{
	printf("shellCheckDaemon is called!\n");

	/** TASK 4 **/
	// 1. Execute the binary program 'checkdaemon' in shellPrograms using execvp system call
	// 2. Check if execvp is successful by checking its return value
	// 3. A successful execvp never returns, while a failed execvp returns -1
	// 4. Print some kind of error message if it returns -1
	// 5. return 1 to the caller of shellCheckDaemon if execvp fails to allow loop to continue
	int ret_val = execvp("/mnt/c/Users/kting/Desktop/PA1/shellPrograms/checkdaemon", args);
	if (ret_val == -1){
		printf("There is error in using checkdaemon!\n");
		return 1;
	}
	
}

/**
   Allows one to change directory 
 */
int shellCD(char **args)
{
  printf("shellCD is called! \n");
  if (args[1] == NULL)
  {
    fprintf(stderr, "CSEShell: expected argument to \"cd\"\n");
  }
  else
  {
    // chdir() changes the current working directory of the calling process
    // to the directory specified in path.
    if (chdir(args[1]) != 0)
    { //use chdir
      perror("CSEShell:");
    }
  }

  return 1;
}

/**
   Prints out the usage and
   list of commands implemented
 */
int shellHelp(char **args)
{
  printf("shellHelp is called! \n");
  int i;
  printf("CSE Shell Interface\n");
  printf("Usage: command arguments\n");
  printf("The following commands are implemented:\n");

  for (i = 0; i < numOfBuiltinFunctions(); i++)
  {
    printf("  %s\n", builtin_commands[i]); //print all the commands that have been implemented in the shell program
  }

  return 1;
}

/**
  Returns 0, to terminate execution from the shellLoop
 */
int shellExit(char **args)
{
  return 0;
}


/*
  Builtin function implementations.
*/
int shellUsage(char **args)
{
  int functionIndex = -1;

  // Check if the commands exist in the command list
  for (int i = 0; i < numOfBuiltinFunctions(); i++)
  {
    if (strcmp(args[1], builtin_commands[i]) == 0)
    {
      //pass it to the functions
      functionIndex = i;
    }
  }

  switch (functionIndex)
  {
  case 0:
    printf("Type: cd directory_name\n");
    break;
  case 1:
    printf("Type: help\n");
    break;
  case 2:
    printf("Type: exit\n");
    break;
  case 3:
    printf("Type: usage command\n");
    break;
  case 4:
    printf("Type: display filename\n");
    break;
  case 5:
    printf("Type: countline filename\n");
    break;
  case 6:
    printf("Type: listdir\n");
    printf("Type: listdir -a to list all contents in the current dir and its subdirs\n");
    break;
  case 7:
    printf("Type: listdirall\n");
    break;
  case 8:
    printf("Type: find filename_keyword\n");
    break;
  case 9:
    printf("Type: summond \n");
    break;
  case 10:
    printf("Type: checkdaemon \n");
    break;
  default:
    printf("Command %s not found\n", args[0]);
    break;
  }

  return 1;
}
/*
  End of builtin function implementations.
*/

/**
   Execute inputs when its in the default functions
   Otherwise, print error message and return to loop
 */
int shellExecuteInput(char **args)
{
	/** TASK 3 **/

	// 1. Check if args[0] is NULL. If it is, an empty command is entered, return 1
	// 2. Otherwise, check if args[0] is in any of our builtin_commands, and that it is NOT cd, help, exit, or usage.
	// 3. If conditions in (2) are satisfied, perform fork(). Check if fork() is successful.
	// 4. For the child process, execute the appropriate functions depending on the command in args[0]. Pass char ** args to the function.
	// 5. For the parent process, wait for the child process to complete and fetch the child's return value.
	// 6. Return the child's return value to the caller of shellExecuteInput
	// 7. If args[0] is not in builtin_command, print out an error message to tell the user that command doesn't exist and return 1

	if (args[0] == NULL){
		printf("Empty Command.\n");
		return 1;
	}
	
	int num_of_fn = numOfBuiltinFunctions();
	int stat_loc;

	for (int i = 0; i < num_of_fn; i++){
		if (strcmp(args[0], builtin_commands[i]) == 0){ // identical string
			if (i >= 4){ // 5th command and onwards
				pid_t child = fork();
				if (child < 0){
					printf("Fork unsuccessful.\n");
					return 1;
				}
				if (child > 0){	// parent process
					printf("Fork works, waiting for child\n");	
					waitpid(child, &stat_loc, WUNTRACED); //wait
					
					int exit_status = 0;
					if (WIFEXITED(stat_loc)){
						 exit_status = WEXITSTATUS(stat_loc);
					}
					return exit_status; // There's a possiblity where shellExit() is called, thus returning 0 and not 1.
					
				}
				if (child == 0){ // in child process
					(*builtin_commandFunc[i])(args);
					exit(1); // This is the exit status that will be read by the parent
				}
			}
			
			return (*builtin_commandFunc[i])(args);
			
		} 
	}		
	
	printf("Invalid command received. Type help to see what commands are implemented.\n");
	return 1;
	
	
	
}

/**
   Read line from stdin, return it to the Loop function to tokenize it
 */
char *shellReadLine(void)
{
  /** TASK 1 **/
  // read one line from stdin using getline()

  // 1. Allocate a memory space to contain the string of input from stdin using malloc. Malloc should return a char* that persists even after this function terminates.
  // 2. Check that the char* returned by malloc is not NULL
  // 3. Fetch an entire line from input stream stdin using getline() function. getline() will store user input onto the memory location allocated in (1)
  // 4. Return the char*

	char* buffer;
	size_t bufsize = SHELL_BUFFERSIZE;
	buffer = (char *)malloc(bufsize * sizeof(char));
	size_t characters;
    if (buffer == NULL)
    {
        perror("Unable to allocate buffer for shellReadLine");
		characters = getline(&buffer,&bufsize,stdin);
        return buffer;
    }
	
	characters = getline(&buffer,&bufsize,stdin);

	return buffer;
}

/**
 Receives the *line, and return char** that tokenize the line
**/

char **shellTokenizeInput(char *line)
{

	/** TASK 2 **/
	// 1. Allocate a memory space to contain pointers (addresses) to the first character of each word in *line. Malloc should return char** that persists after the function terminates.
	// 2. Check that char ** that is returend by malloc is not NULL
	// 3. Tokenize the *line using strtok() function
	// 4. Return the char **

	char **token_positions = malloc(sizeof(char *) * 8);
	if (token_positions == NULL)
	{
		return token_positions;
	}
	
	
	char *token = strtok(line, SHELL_INPUT_DELIM);
	int index = 0;
	
	
	token_positions[index] = token;
	index++;
	while (token != NULL)
	{
	   // Tokenize the rest of the command
	   token = strtok(NULL, SHELL_INPUT_DELIM);      //continue finding the next token
	   token_positions[index] = token; //store the position
	   index++;
	}

	token_positions[index] = NULL; //dont forget to NULL terminate.

	return token_positions;

}

/**
  The main loop where one reads line,
  tokenize it, and then executes the command
 */
void shellLoop(void)
{
	//instantiate local variables
	char *line;  // to accept the line of string from user
	char **args; // to tokenize them as arguments separated by spaces
	int status;  // to tell the shell program whether to terminate shell or not


	/** TASK 5 **/
	//write a loop where you do the following: 
	while(1){
		// 1. print the message prompt
		printf("CSEShell> ");

		// 2. clear the buffer and move the output to the console using fflush
		// 3. invoke shellReadLine() and store the output at line
		line = shellReadLine();
		// printf("The fetched line is : %s \n", line);
		
		// 4. invoke shellTokenizeInput(line) and store the output at args**
		args = shellTokenizeInput(line);
		/*
		printf("The first token is %s \n", args[0]);
		printf("The second token is %s \n", args[1]);
		*/
		if ((strcmp(args[0], builtin_commands[3]) == 0) && args[1] == NULL)
		{
			printf("Invalid - empty second argument. Valid use of usage is e.g. 'usage countline'. Type 'help' to see list of available commands.\n");
			printf("The second token is %s \n", args[1]);
		}
		
		else
		{
			// 5. execute the tokens using shellExecuteInput(args)
			int ret_val = shellExecuteInput(args);

			// 6. free memory location containing the strings of characters
			free(line);
			
			// 7. free memory location containing char* to the first letter of each word in the input string
			free(args);
			
			// 8. check if shellExecuteInput returns 1. If yes, loop back to Step 1 and prompt user with new input. Otherwise, exit the shell. 
			if (ret_val != 1){
				break;
			}
		}
	}

}

int main(int argc, char **argv)
{

	printf("Shell Run successful. Running now: \n");

	// Run command loop
	shellLoop();
	return 0;

}
