# Terminal Clock System++

## Description
The **Terminal Clock System++** is a C-based console application that provides various time-related functionalities, including:
- Displaying the current time
- Setting a countdown timer with an alarm
- Running a stopwatch

This application runs in the terminal and requires a Linux-based system with `mpg123` installed to play alarm sounds.

## Features
1. **Display Current Time**: Shows the current local time in a formatted manner.
2. **Set Alarm (Countdown Timer)**: Allows users to input a duration (in seconds) and counts down to zero, optionally playing an alarm sound if `mpg123` is installed.
3. **Stopwatch**: Lets users start and stop a stopwatch to measure elapsed time.
4. **User-Friendly Control Dashboard**: Provides an interactive menu to navigate between different features.

## Installation & Requirements
### Prerequisites
- A Linux-based system
- `gcc` compiler to compile the program
- (Optional) `mpg123` for playing alarm sounds

### Installing `mpg123`
To enable sound playback when the timer ends, install `mpg123` by running:
```sh
sudo apt install mpg123
```

## Compilation
To compile the program, use:
```sh
gcc terminal.c -o run.exe -Wall
```

## Running the Program
After compilation, run the program using:
```sh
./run.exe
```

## Usage
Once launched, the program displays a menu with options:
1. Display the current time
2. Set an alarm
3. Initiate a stopwatch
4. Exit the application

### Setting a Timer
- Enter the time in seconds when prompted.
- The timer counts down until it reaches 0.
- If `mpg123` is installed, it will play an alarm sound.

### Stopwatch Usage
- Type `start` to begin timing.
- Type `stop` to stop and display the elapsed time.
- Type `exit` to leave the stopwatch session.

## Troubleshooting
### Timer Sound Not Playing?
- Ensure `mpg123` is installed (`which mpg123` should return a path).
- Check if the `run_baby_run.mp3` file exists in the same directory as the executable.
- If missing, replace it with another `.mp3` file and update the filename in the `set_timer()` function.

## Future Improvements
- Add support for custom alarm sounds.
- Implement a graphical interface.
- Add stopwatch lap functionality.

## License
This project is open-source and available for modification and distribution under the MIT License.

---
Developed by **zfronk**

