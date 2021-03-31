
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<readline/readline.h>
#include<readline/history.h>


char *parsed[100];

// Function where the system command is executed
void execArgs()
{
	// Forking a child
	pid_t pid = fork();

	if (pid == -1) {
		printf("\nFailed forking child..");
		return;
	} else if (pid == 0) {
		if (execvp(parsed[0], parsed) < 0) {
			printf("\nCould not execute command..");
		}
		exit(0);
	} else {
		wait(NULL);
		return;
	}
}


void take_input() 
{
	int i,j=0,k=0;

	for(i=0;i<100;i++) 
	{
		parsed[i] = (char *)malloc(10 * sizeof(char));
	}

	char in[100];

	fgets(in,sizeof in,stdin);

	if(in[0]=='q'&&in[1]=='u'&&in[2]=='i'&&in[3]=='t') exit(1);

	for(i=0;in[i]!='\n';i++) {

		if(in[i]==' ') {
			parsed[j][k] = '\0';
			j++;
			k=0;
			continue;
		}

		parsed[j][k++] = in[i];

	}



	for(j=j+1;j<100;j++) 
	{
		parsed[j] = NULL;
	}
	


}


int main()
{
	

	while (1) {
	
		printf(">>> ");

		take_input();

		execArgs();

		printf("\n\n");

		

	}

	return 0;
}
