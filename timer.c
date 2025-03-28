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
	bool getting_time = true;

	printf("Configuring timer\n");
	printf(".................\n");

	// Act as switch

	// Get hours
	int hours;
	
	while(getting_time){
		printf("Input number of hours: ");


		char input = getchar();
		char new_line = '\n';

		// Read enter
		if(input == new_line){
			printf("You pressed enter\n");
			printf("\n");
			continue;
					
		}
		
		ungetc(input, stdin); // Return input when charcter not newline for processing
		
		// Invalid data type
		if(scanf("%d", &hours) != 1 || hours < 0){
			printf("Invalid data type!\n");
			while(getchar() != '\n'); // Remove till new line character
			continue;

		}
		
		else{
			while(getchar() != '\n');
			printf("Hours recorded!\n");
			printf("\n");
			getting_time = false;

		}
		
		
	}

	getting_time = true; // Make true to rerun loop!

	// Get minutes
	int minutes; // Variable to store minutes 
	
	while(getting_time){
		printf("Input number of minutes: ");

		char input = getchar();
		char new_line = '\n';

		if(input == new_line){
			printf("You pressed enter\n");
			printf("\n");
			continue;
			
		}

		ungetc(input, stdin); // Return input when charcter not newline for processing

		// Invalid data type
		if(scanf("%d", &minutes) != 1 || minutes >= 60 || minutes < 0){
			printf("Invalid data type!\n");
			while(getchar() != '\n'); // Remove till new line character
			printf("\n");
			continue;
		}

		else{
			while(getchar()!= '\n'); // Clear the buffer
			printf("Minutes recorded!\n");
			printf("\n");
			getting_time = false;
		}
		
	}

	getting_time = true; // Make true to rerun loop!



	// Get seconds
	int seconds;

	while(getting_time){
		printf("Input number of seconds: ");

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
		if(scanf("%d", &seconds) != 1 || seconds < 0 || seconds >= 60){
			printf("Invalid data type!\n");
			printf("\n");
			while(getchar() != '\n'); // Clear till new line is read
			continue;
		}

		
		else{
			while(getchar() != '\n'); // Clear buffer
			printf("Seconds recorded!\n");
			getting_time = false;
			
		}
		
	}

		printf("\n");
		printf("..............\n");
		printf("Timer set: %02d:%02d:%02d\n", hours, minutes,seconds);

		int total_seconds = (seconds + (minutes * 60) + (hours * 3600));
		printf("%d total seconds recorded!\n", total_seconds);
		int temp_time = total_seconds;
		
		printf("\n");

		printf("Timer started!\n");
		printf("..............\n");

		// Start timer
		for(int i = 0; i < total_seconds; i++ ){
			int temp_hours = temp_time / 3600; // For example i have 150 seconds divided by 3600 int stands as zero
			int temp_minutes = (temp_time % 3600)/ 60; // Take mod(150, 3600) gives 150 but need minutes (150 / 60) gives me int one;
			int temp_seconds = temp_time % 60; // What's left

			printf("\rTime left: %02d:%02d:%02d ", temp_hours, temp_minutes, temp_seconds);
			fflush(stdout); // Immediate feedback
			sleep(1); // simulate a second
			temp_time--;
			

			
			// Ding dong! Time's up
			if(temp_time == 0){
				printf("\rTime left: 00:00:00");
				printf("\n");
				printf("Time's up!\n");

				printf("\n");

			// Check if package is installed
			if(system("which mpg123 > /dev/null 2>&1") == 0){ // return zero if present
				printf("Package to play sound available!\n");
				printf("\n");

				system("mpg123 run_baby_run.mp3"); // Play sound

				// On finish
				printf("Music terminated!\n");
				printf("Feel free to time yourself again!\n");
				printf("................................\n");
				printf("\n");
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



void initiate_stopwatch(){
	printf("Stopwatch\n");
	printf(".........\n");
	printf("Enter <start> to start stopwatch || <exit> to exit stopwatch session!\n");

	while(true){
		
		printf("Enter command: ");

		char command[50]; // Buffer to store command
		fgets(command, sizeof(command), stdin); // Get input

		command[strcspn(command, "\n")] = 0; // Remove newline taken

		if(strcasecmp(command, "start") == 0){
			printf("Timer running!\n");
			printf("\n");

			time_t start = time(NULL); // initiate time in unreadable format

			printf("Enter command <stop> to stop the stopwatch: ");
			char timer_command[50];
			fgets(timer_command, sizeof(command), stdin);

			if(strcasecmp(timer_command, "stop") == 0){
				printf("Timer stopped!\n");
				time_t end = time(NULL); // End time in uneradble format

				//printf("\n");
				int elapsed_time = end - start;
				printf("Time elapsed %d seconds\n", elapsed_time);
				break;
			
			
			}
		
		
		}

		// If exit
		else if(strcasecmp(command, "exit") == 0){
			printf("Exited stopwatch session!\n");
			break;
		
		}

		// Invalid input
		else{
			printf("Invalid input!\n");
			printf("\n");
			command[strcspn(command,"\n")] = 0; // Remove new line from the buffer
			continue;
		}
		
		
	}

	
}

// Control Dashboard
void control_dashboard(){
	printf("TERMINAL CLOCK SYSTEM++\n");
	printf("-----------------------\n");
	printf("1. Display current time\n");
	printf("2. Set alarm\n");
	printf("3. Initiate stopwatch\n");
	printf("4. Exit application\n");
	printf("-----------------------\n");
	


	bool collecting_choice = true;

	while(collecting_choice){
		printf("Choose an option from the dashboard: ");
		int choice;

		char enter = '\n';
		char read_input = getchar();
		

		if(read_input == enter){
			printf("You pressed enter!\n");
			printf("\n");
			continue;
			
		}

		ungetc(read_input, stdin); // Put back
				
		if(scanf("%d", &choice) != 1){
			printf("Invalid input!\n");
			while(getchar() != '\n'); // Clear buffer
			printf("\n");
			continue;

		}


		if(choice == 1){
			getchar(); // Remove newline
			display_time();
			
		}

		else if(choice == 2){
			getchar();
			printf("\n");
			set_timer();
		}

		else if(choice == 3){
			getchar();
			printf("\n");
			initiate_stopwatch();
		}

		else if(choice == 4){
			getchar();
			printf("Have a nice time buddy!\n");
			printf("\n");
			break;
		}

		else{
			while(getchar() != '\n'); // Remove new line
			printf("Choose valid options!\n");
			printf("\n");
			continue;
		}


			 	
		
		}

	
}



void welcome_user(){
	printf("Welcome user!\n");
	printf("\n");

	control_dashboard(); // Display dashboard
	
	

}


// Entry point
int main(){
	welcome_user();;

	return 0;
}
