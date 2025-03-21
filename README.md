# ⚡ Countdown Timer with Alarm

## 🛠️ Overview
This is a simple C program that runs a countdown timer and plays an alarm when the time is up. The terminal is cleared before and after execution for a clean display.

## 🔥 Features
- Countdown timer (default: 3 seconds, adjustable).
- Plays an alarm sound when time is up.
- Clears the terminal before and after execution.

## 🖥️ System Requirements
- Linux-based system (or WSL on Windows).
- `mpg123` installed for playing the alarm sound.
- `alarm.mp3` file in the same directory as the program.

## 🚀 Setup & Installation
1. Install `mpg123` if not already installed:
   ```sh
   sudo apt install mpg123  # Debian/Ubuntu
   sudo dnf install mpg123  # Fedora
   sudo pacman -S mpg123    # Arch
   ```

2. Compile the program:
   ```sh
   gcc timer.c -o run.exe
   ```

## ⚡ Running the Timer
1. Ensure `alarm.mp3` is in the same directory.
2. Run the program:
   ```sh
   ./run.exe  # On Linux
   run.exe    # On Windows (if compiled with MinGW)
   ```
3. The program will count down and play the alarm.

## 🎛️ Customization
- Change the countdown duration by modifying:
  ```c
  int delay_time = 3; // Adjust seconds
  ```
- Modify the alarm playback method if needed:
  ```c
  system("mpg123 alarm.mp3");
  ```

## ⚠️ Notes
- The terminal is cleared at the start and end of the program.
- If `mpg123` isn’t installed or `alarm.mp3` is missing, the alarm won’t play.

## 🎖️ License
This project is open-source and free to use.

