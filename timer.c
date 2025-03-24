#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>


// Set timer
void set_timer(){
	int time_in_seconds;
	bool getting_time = true;

	// Act as switch
	while(getting_time){
		printf("Input seconds: ");

		// Invalid data type
		if(scanf("%d", &time_in_seconds) != 1 || time_in_seconds <= 0){
			printf("Invalid data type!\n");
			printf("\n");
			while(getchar() != '\n'); // Clear till new line is read
			continue;
		}

		while(getchar() != '\n'); // Clear buffer
		printf("Time taken %d seconds\n", time_in_seconds);
		getting_time = false;
		
	}

	printf("\n");
	printf("Timer started!\n");
	printf("++++++++++++++\n");

	int temp_time = time_in_seconds;

	// Start timer
	for(int i = 0; i < time_in_seconds; i++){
		printf("Time left: %d\n", temp_time);
		fflush(stdout); // Immediate feedback
		temp_time--;
		sleep(1); // simulate a second

		// Ding dong! Time's up
		if(temp_time == 0){
			printf("\n");
			printf("Time's up!\n");

			printf("\n");

			// Check if package is installed
			if(system("which mpg123 > /dev/null 2>&1") == 0){ // return zero if present
				printf("Package to play sound available!\n");
				printf("\n");

				system("mpg123 run_baby_run.mp3"); // Play sound

				printf("Music terminated!\n");
				break;
				
			}

			// Ask user to download the package
			else{
				printf("Package to play audio unavailable! Please sudo install mpg123, and try again!\n");
				break;
			}

			
		}
		
	}

	

}

// Entry point
int main(){
	set_timer();
	return 0;
}
