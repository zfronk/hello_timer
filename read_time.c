#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int main(){
	time_t now = time(NULL); // Unreadable format

	if(now == (time_t)-1){
		printf("Fetching time failed!\n");
		
	}

	printf("Timer started...\n");
	printf("Input <stop> to stop timer\n");
	printf("\n");

	char buffer[20]; // To store input
	printf("Input: ");

	fgets(buffer, sizeof(buffer), stdin); // Assign the input to buffer

	if(strcasecmp(buffer, "stop")){
		time_t then = time(NULL); // Current time
		int time_elapsed = then - now;
		char *time_as_string = ctime(&then);


		printf("%d seconds elapsed!\n", time_elapsed);
		printf("Time stopped at: %s", time_as_string);
		printf("\n");
	}

	
	return 0;
}
