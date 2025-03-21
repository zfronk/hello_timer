#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
	system("clear");
    printf("Please wait!\n");
    int delay_time = 3;
    int countdown = delay_time;

    // Countdown loop
    for (int i = 0; i < delay_time; i++) {
        printf("%d ", countdown);
        fflush(stdout);  // Ensure immediate output
        sleep(1);
        countdown--; // Decrease after  printing

        // Move the check after countdown reaches 0
        if (countdown == 0) {
            printf("\nTimes up!\n");
            system("mpg123 alarm.mp3 "); // play music
            break;
        }
    }

	sleep(1); // Wait a second
	printf("\n");
	printf("Output delayed by %d seconds.\n", delay_time);
	sleep(5);
	system("clear");
    return 0;
}
