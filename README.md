<a href="https://imgur.com/tJA0FHf"><img src="https://i.imgur.com/tJA0FHf.png" title="source: imgur.com" /></a>

## Table of Contents
* [Introduction](#Introduction)
* [File Structure](#file-structure)
* [Requirements](#requirements)
* [Installation](#installation)
* [Usage](#usage)
* [Example of Use](#example-of-use)
* [Bugs](#bugs)
* [Authors](#authors)
* [License](#license)

## Description
simple_shell is a command line interpreter, or shell, in the tradition of the first Unix shell written by Ken Thompson in 1971. Remember that it is the command interpretor in an operating system such as Unix or **Linux**, it executes other programs. It provides a computer user an interface to the Unix or **Linux** system, so that the user can run different commands or utilities/tools with some input data. 

So, this is really our mini shell, it  is intentionally minimalistic, but it is very reliable. Yet includes the basic functionality of a traditional Unix-like command line user interface, but we are working to improve it and to add more functionalities.   

Standard C functions  and system calls employed for this simple_shell:
 `execve, exit, fork, free, stat, getline, malloc, perror, signal, stat, wait, write.`

## File Structure
* [AUTHORS](AUTHORS) - List of contributors to this repository
* [man_simple_shell](man_simple_shell) - Manual page for the simple_shell
* [holberton.h](shell.h) - header file with fuction prototypes
* [prompt.c](prompt.c) - the main function of the program
* [_strdup.c](strdup.c) - duplicates a string
* [_strcmp.c](strcmp.c) - compares two strings
* [divide_string.c](divide_string.c) - creates an array of tokens from a buffer with a specified delimiter
* [_getenv.c](_getenv.c) - get the value of the enviroment variable
* [list_path.c](list_path.c) - create a linked list of the directories inside the PATH enviroment variable
* [divide_string.c](divide_string.c) - creates an array of tokens from a buffer with a specified delimiter

## Requirements

simple_shell is designed to run in the `Ubuntu 14.04 LTS` linux environment and to be compiled using the GNU compiler collection v. `gcc 4.8.4` with flags`-Wall, -Werror, -Wextra, and -pedantic.`

## Installation

   - Clone this repository: `git clone "https://github.com/DiegoCol93/simple_shell"`
   - Change directories into the repository: `cd simple_shell`
   - Compile: `gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`
   - Run the shell in interactive mode: `./hsh`
   - Or run the shell in non-interactive mode: example `echo "Hello world!" | ./hsh`

## Usage

The simple_shell is designed to execute commands in a similar manner to sh, however with more limited functionality. The development of this shell is ongoing. The below features will be checked as they become available (see man page for complete information on usage):

### Features
- [x] uses the PATH
- [ ] implements builtins
- [x] handles command line arguments
- [ ] custom strtok function
- [ ] uses exit status
- [ ] shell continues upon Crtl+C (**^C**)
- [ ] handles comments (#)
- [ ] handles **;**
- [ ] custom getline type function
- [ ] handles **&&** and **||**
- [ ] aliases
- [ ] variable replacement


### Builtins

- [ ] exit
- [ ] env
- [ ] setenv
- [ ] unsetenv
- [ ] cd
- [ ] help
- [ ] history

## Example of Use
Run the executable in your terminal after compiling:
```
$ ./hsh
$ # This is our rendition of the shell
$ ls -l
put a example
```
## Bugs
At this time, there are no known bugs.

## Authors
Diego Lopez | [GitHub](https://github.com/DiegoCol93) | [Twitter](https://twitter.com/LopezDfelo93)
Daniel Cortes | [GitHub](https://github.com/el-dani-cortes) | [Twitter](https://twitter.com/El_Dani_Cortes)

## License
This simple_shell is open source and therefore free to download and use without permission. Feel free to contribute to this repo. 
