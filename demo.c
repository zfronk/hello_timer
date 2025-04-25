#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(){

	time_t unreadable_time = time(NULL); // Unreadable format
	char time_buffer[40]; // Buffer to store time

	ctime_r(&unreadable_time, time_buffer); // Thread safe

	// Show time!
	printf("Its %s", time_buffer);
	printf("\n");

	// Countdown!
	printf("Timer started!\n");

	time_t start_timer = time(NULL);
	sleep(5); // Sleep for 5 seconds
	time_t stop_timer = time(NULL);

	int time_elapsed = start_timer - stop_timer;
	printf("%d seconds elapsed...\n", time_elapsed); // Print time elapsed

	
	return 0;
}
