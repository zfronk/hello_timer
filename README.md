# Terminal Clock System++

A simple terminal-based utility providing basic clock functionalities for Linux.

## Features

* **Display Current Time:** Shows the current system time, updating every second for a brief period.
* **Set Timer:** Allows you to configure a countdown timer by inputting hours, minutes, and seconds. The timer displays the remaining time and plays a sound (if `mpg123` is installed) upon completion.
* **Initiate Stopwatch:** Starts a simple stopwatch. Enter `<stop>` to record the elapsed time.
* **Control Dashboard:** A menu-driven interface to access all the features.

## Getting Started

### Prerequisites

* A C compiler (like GCC), typically available on most Linux distributions.
* (Optional for sound) `mpg123` - a command-line MPEG audio player. You can install it using your distribution's package manager:
    * **Debian/Ubuntu:**
      ```bash
      sudo apt-get update
      sudo apt-get install mpg123
      ```
    * **Fedora/CentOS/RHEL:**
      ```bash
      sudo dnf install mpg123
      # or
      sudo yum install mpg123
      ```
    * **Arch Linux:**
      ```bash
      sudo pacman -S mpg123
      ```

### Compilation

1.  Save the provided C code as `timer.c`.
2.  Open your terminal.
3.  Navigate to the directory where you saved `timer.c`.
4.  Compile the code using GCC:
    ```bash
    gcc timer.c -o run.exe
    ```

### Running the Application

1.  In the same terminal, execute the compiled program:
    ```bash
    ./run.exe
    ```
2.  The "TERMINAL CLOCK SYSTEM++" dashboard will appear. Choose an option by entering the corresponding number and pressing Enter.

## Usage

### Display Current Time (Option 1)

* Select `1` from the dashboard.
* The current time will be displayed, updating every second for three seconds.

### Set Timer (Option 2)

* Select `2` from the dashboard.
* Follow the prompts to input the desired hours, minutes, and seconds for the timer.
* The timer will count down, showing the remaining time.
* Upon completion:
    * If `mpg123` is installed, it will attempt to play `run_baby_run.mp3` (ensure this file is in the same directory as `run.exe`).
    * If `mpg123` is not found, a message will suggest installing it.

### Initiate Stopwatch (Option 3)

* Select `3` from the dashboard.
* The stopwatch will start.
* Type `stop` (case-insensitive) and press Enter to stop it.
* The elapsed time in seconds will be displayed.

### Exit Application (Option 4)

* Select `4` to quit the application.

## Notes

* The sound functionality relies on the `mpg123` package being installed on your Linux system. Also, make sure `run_baby_run.mp3` is in the same directory as the executable.
* Input validation is in place to handle incorrect input types and out-of-range time values.
* The stopwatch provides elapsed time in whole seconds.

## Contributing

Contributions are welcome! Please submit pull requests or suggest improvements.

## License

This project is open-source and available under a permissive license (e.g., MIT License). See the `LICENSE` file for details.
