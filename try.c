#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define RED "\033[1;31m"  // Bold Red
#define GREEN "\033[1;32m" // Bold Green
#define YELLOW "\033[1;33m" // Bold Yellow
#define RESET "\033[0m"   // Reset Color

void print_progress(int countdown) {
    printf("\r" YELLOW "[");
    for (int i = 0; i < countdown; i++) {
        printf(GREEN "#");
    }
    for (int i = countdown; i < 10; i++) {
        printf(" ");
    }
    printf(YELLOW "] " RED "%d sec" RESET, countdown);
    fflush(stdout);
}

int main() {
    system("clear");  
    printf(YELLOW "Please wait!\n" RESET);

    int delay_time;
    printf("Enter countdown time (seconds): ");
    scanf("%d", &delay_time);

    int countdown = delay_time;

    for (int i = 0; i < delay_time; i++) {
        print_progress(countdown);  
        sleep(1);
        countdown--;
    }

    printf("\n" RED "⏰ Times up! ⏰\n" RESET);

    if (system("which mpg123 > /dev/null 2>&1") == 0) {
        system("mpg123 alarm.mp3");
    } else {
        printf(RED "Error: mpg123 not found. Install it using 'sudo apt install mpg123'\n" RESET);
    }

    printf(GREEN "Output delayed by %d seconds.\n" RESET, delay_time);
    return 0;
}
