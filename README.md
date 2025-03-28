# Terminal Clock System++

## Overview
Terminal Clock System++ is a simple command-line utility that provides three main functionalities:
1. **Display Current Time** - Shows the real-time system clock for a few seconds.
2. **Set a Timer** - Allows the user to set a countdown timer with an optional alarm.
3. **Stopwatch** - A stopwatch that can be started and stopped manually.

This program is written in **C** and runs in a terminal environment.

---

## Features
- **Real-time clock display**
- **Configurable countdown timer** with a sound notification (requires `mpg123` for audio playback)
- **Stopwatch functionality**
- **Simple and interactive menu-driven interface**
- **Error handling for user input validation**

---

## Prerequisites
- **Operating System:** Linux (Tested on Linux Mint)
- **Compiler:** GCC
- **Audio Package:** `mpg123` (Optional, required for alarm sound playback)

To install `mpg123` on Debian-based systems:
```sh
sudo apt install mpg123
```

---

## Installation & Compilation
1. Clone the repository or copy the source code.
2. Open a terminal and navigate to the source directory.
3. Compile the program using GCC:
   ```sh
   gcc -o terminal_clock terminal_clock.c -Wall
   ```
4. Run the compiled executable:
   ```sh
   ./terminal_clock
   ```

---

## Usage
Once the program is launched, follow the on-screen menu options:

1. **Display Current Time:**
   - Shows the real-time system clock for 3 seconds.
2. **Set Timer:**
   - Enter hours, minutes, and seconds.
   - The countdown will be displayed in HH:MM:SS format.
   - If `mpg123` is installed, an alarm sound will play when the timer reaches zero.
3. **Stopwatch:**
   - Start the stopwatch by entering `start`.
   - Stop it by entering `stop` to see the elapsed time.
4. **Exit:**
   - Close the program.

---

## Example Run
```
TERMINAL CLOCK SYSTEM++
-----------------------
1. Display current time
2. Set alarm
3. Initiate stopwatch
4. Exit application
-----------------------
Choose an option from the dashboard: 2

Configuring timer
.................
Input number of hours: 0
Hours recorded!

Input number of minutes: 0
Minutes recorded!

Input number of seconds: 5
Seconds recorded!

Timer set: 00:00:05
5 total seconds recorded!

Timer started!
..............
Time left: 00:00:05
Time left: 00:00:04
Time left: 00:00:03
Time left: 00:00:02
Time left: 00:00:01
Time left: 00:00:00
Time's up!
```

---

## Future Enhancements
- Add a pause/resume feature for the timer and stopwatch.
- Implement a more interactive UI with ncurses.
- Improve audio playback by supporting additional formats.

---

## License
This project is open-source and free to use.

