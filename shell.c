#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

//start an infinite loop
int main(){
printf("changedShell Project\n");
char buffer[512];
char *token_array[512];
char *token;
int index;
pid_t pid;

while(1){
	
	//print your current working directory (e.g. shahira@myshell:[cwd]:) you can use getcwd() and printf()
	printf("\nuser@theshell:[%s]: ", getcwd(NULL, 0));
	//read the command from user; this could be done by starting another loop which is broke when user presses Enter
	while((strcmp(fgets(buffer, 512, stdin), "\n")) == 0){
		if(strcmp(buffer, "\n") == 0){
			printf("\nuser@theshell:[%s]: ", getcwd(NULL, 0));
		}
	}
	//Now that we have the command that the user entered, we need to parse the command and handle it
	//split your command into arguments (separator is whitespace ‘ ‘); you can use strtok()
	//check the first argument to see what command was entered and decide how to handle it
	index = 0;
	token = strtok(buffer, " ");
	while(token != NULL){
		token_array[index] = token;
		index++;
		token = strtok(NULL, " ");
	}
	printf("broke loop\n");
	if(strcmp(token_array[0], "shell\n") == 0){
		printf("BATCH MODE\n");	
		//fp = fopen(token_array[1], r);
	}
	else if((strcmp(token_array[0], "ls\n") == 0)||(strcmp(token_array[0], "cat\n") == 0)||(strcmp(token_array[0], "grep\n") == 0)){
		pid = fork();
		if(pid==-1){
			printf("Error creating child process\n");
		}
		else if(pid==0){/*child process executes the command; use execvp()*/
			printf("ls\n");
			execvp(token_array[0], token_array);
		}
		else{/*parent process will wait for child to execute the command and return its exit code; use waitpid()*/
			waitpid(pid, NULL, 0);
		}
	}
	else{printf("%s",token_array[0]);}
}
return 0;
}
