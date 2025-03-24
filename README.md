# Terminal Clock System

## Description
This is a simple terminal-based clock system written in C. It allows users to display the current time, set a countdown timer, and receive an audio alert when the timer expires. The application runs in a loop, letting users choose actions from a menu.

## Features
- **Display Current Time**: Shows the real-time clock in a formatted manner (HH:MM:SS AM/PM) and updates it every second.
- **Set Countdown Timer**: Users can input a duration in seconds, and the program will count down until it reaches zero.
- **Audio Notification**: If `mpg123` is installed, an audio alert is played when the timer expires.
- **User-Friendly Interface**: Provides a clear menu-driven interface for ease of use.

## Requirements
- Linux-based system
- GCC compiler for building the program
- `mpg123` package (optional, for playing sound alerts)

## Installation
1. Clone the repository or copy the source code.
   ```sh
   git clone <repository-url>
   cd terminal-clock-system
   ```
2. Compile the program using GCC:
   ```sh
   gcc -o run.exe timer.c -Wall
   ```
3. Run the program:
   ```sh
   ./run.exe
   ```

## Usage
1. Upon running, you are greeted with a menu:
   - Press `1` to display the current time.
   - Press `2` to set a countdown timer.
   - Press `3` to exit the application.
2. If selecting the timer option, input the number of seconds for the countdown.
3. If `mpg123` is installed, an alarm sound will play when the timer reaches zero.

## Dependencies
- Standard C libraries (`stdio.h`, `stdlib.h`, `string.h`, `stdbool.h`, `unistd.h`, `time.h`)
- `mpg123` (optional, for playing alarm sound)

## Notes
- The application ensures user-friendly input handling and validates data types.
- If `mpg123` is not installed, the user is prompted to install it for sound playback.

## Future Enhancements
- Add support for customizing alarm sounds.
- Implement a stopwatch feature.
- Improve UI with ANSI escape codes for better visuals.

## License
This project is licensed under the MIT License.

