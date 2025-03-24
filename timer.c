#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>



// Show time
void display_time(){

	bool reading_time = true;
	int count = 0;
	
	while(reading_time){
		time_t now = time(NULL); // Get system time in unreadable format
		struct tm *time_info = localtime(&now); // Local time structure
			
		char current_time[50];
		strftime(current_time, sizeof(current_time), "%I:%M:%S %p", time_info); // Format readable format to buffer
			
		printf("\rIt's %s", current_time);
		fflush(stdout); // Force output
		count++;
		sleep(1);

		// Read for three seconds
		if(count == 3){
			printf("\n");
			break;
			
		}
					
	}
	

}


// Manage timer
void set_timer(){
	int time_in_seconds;
	bool getting_time = true;


	printf("Configuring timer\n");
	printf(".................\n");
	// Act as switch
	while(getting_time){
		printf("Input time in seconds: ");

		char sniff_enter = getchar();
		char enter = '\n';
		
		if(sniff_enter == enter){
			printf("You pressed enter!\n");
			printf("\n");
			continue;
					
		}
		
		// If not otherwise
		ungetc(sniff_enter, stdin);
				
		// Invalid data type
		if(scanf("%d", &time_in_seconds) != 1 || time_in_seconds <= 0){
			printf("Invalid data type!\n");
			printf("\n");
			while(getchar() != '\n'); // Clear till new line is read
			continue;
		}

		

		while(getchar() != '\n'); // Clear buffer
		printf("Duration %d seconds.\n", time_in_seconds);
		getting_time = false;
		
	}

	printf("\n");
	printf("Timer started!\n");
	printf("..............\n");

	int temp_time = time_in_seconds;

	// Start timer
	for(int i = 0; i < time_in_seconds; i++){
		printf("\rTime left: %d", temp_time);
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
				printf("Feel free to time yourself again!\n");
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

// Control Dashboard
void control_dashboard(){
	printf("+++++++++++++++++++++++\n");
	printf("1. Display current time\n");
	printf("2. Set alarm\n");
	printf("3. Exit application\n");
	printf("+++++++++++++++++++++++\n");
	


	bool collecting_choice = true;

	while(collecting_choice){
		printf("\n");
		printf("Choose an option from the dashboard: ");

		int choice;
		char enter = '\n';
		char read_input = getchar();
		

		if(read_input == enter){
			printf("You pressed enter!\n");
			//printf("\n");
			continue;
			
		}

		ungetc(read_input, stdin); // Put back
				
		if(scanf("%d", &choice) != 1 || choice == '\n' ){
				printf("Invalid input!\n");
				while(getchar() != '\n'); // Clear buffer
				continue;
			}


		if(choice == 1){
			getchar(); // Remove newline
			//printf("\n");
			display_time();
			
		}

		else if(choice == 2){
			getchar();
			printf("\n");
			set_timer();
		}

		else if(choice == 3){
			getchar();
			printf("See you soon!\n");
			break;
		}


			 	
		
		}

	
}



void welcome_user(){
	printf("Hello there welcome to your terminal clock system!\n");
	printf("\n");

	control_dashboard(); // Display dashboard
	
	

}


// Entry point
int main(){
	welcome_user();;

	return 0;
}
