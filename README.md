# Simple Shell Project

**A simple Unix command line interpreter**

****
## Table of contents
 - **What is the shell?**
 - **About this project**
 - **Essential Functionalities of the Simple Shell**
 - **File description**
 - **List of allowed functions and system calls for this project**
 - **USAGE**
 - **Example of Usage**
 - **Bugs**
 - **TEAM**
 ****

## What is the shell?
The shell is a program that takes commands from the keyboard via the terminal, and gives them to the operating system to perform.

## About this project
This project is a simple version of the linux shell made for [ALX School] taking part of the "Low-level programming & Algorithm - Linux and Unix system programming" projects.\
It is created using the **C programming Language** and it can do many functionalities that a real shell does.

## Essential Functionalities of the Simple Shell:
> Displays a prompt "#cisfun$ " and waits for user input.\
> Runs all commands of type "executable program" (ls and /bin/ls).\
> Runs the following build_in commands: **exit**, **env**, **setenv** and **unsetenv**.\
> Handles commands with arguments.\
> Handles the PATH global variable.\
> Handles The EOF (End Of File) condition.\
> Handles the Ctrl + C signal -> It doesn't exit the shell

## Files description
 - **AUTHORS** -> List of contributors to this repository
 - **main.h** -> Header file
 - **main.c** -> main function
	- **_atoi.c** -> converts a string to number
	- **get_builtin** -> Get the builtin func object
	- **_getline** -> reads a line from the standard input
	- **_realloc** -> resizes a string created with malloc
 - **_strtok.c**
 	- **count_until_delim** -> returns the number of chars until
 	- **skip_delim** -> skips repeated delimiters
 	- **_strtok** -> returns the next token in the string delimited
 
 - **arry_helpers.c**
	- **str_ary_dup** -> duplicates an array of strings
	- **free_str_ary** -> free an array of strings
	- **str_to_ary** -> splits a string to an array of strings
	- **count_tokens** -> gets the numer of tokens in a string
 - **builtins.c**
	- **exit_shell** -> exit's the shell
	- **print_env** -> prints the current environment variables
	- **set_env** -> sets an environment variable
	- **unset_env** -> unsets an environment variable
	- **_chdir** -> changes the current working directory
 - **env_helpers.c**
	- **print_env_list** -> print the allocated memory for an env_list
	- **free_env_list** -> frees the allocated memory for an env_list
	- **env_list_to_ary** -> convert environment list to array
	- **_getenv** -> finds an environment variable by key
	- **get_c_args** -> constructs a null terminated array of strings

 - **enviroment.c**
	- **build_env_list** -> converts an array of env vars to list
	- **_set_env** -> sets an environment variable
	- **set_env_key_value** -> copies key and value to an environment variable
	- **set_env_value** -> sets value to an environment variable
	- **_unset_env** -> removes an environment variable

****
## List of allowed functions and system calls for this project
 - access (man 2 access)
 - chdir (man 2 chdir)
 - close (man 2 close)
 - closedir (man 3 closedir)
 - execve (man 2 execve)
 - exit (man 3 exit)
 - _exit (man 2 _exit)
 - fflush (man 3 fflush)
 - fork (man 2 fork)
 - free (man 3 free)
 - getcwd (man 3 getcwd)
 - getline (man 3 getline)
 - isatty (man 3 isatty)
 - kill (man 2 kill)
 - malloc (man 3 malloc)
 - open (man 2 open)
 - opendir (man 3 opendir)
 - perror (man 3 perror)
 - read (man 2 read)
 - readdir (man 3 readdir)
 - signal (man 2 signal)
 - stat (__xstat) (man 2 stat)
 - lstat (__lxstat) (man 2 lstat)
 - fstat (__fxstat) (man 2 fstat)
 - strtok (man 3 strtok)
 - wait (man 2 wait)
 - waitpid (man 2 waitpid)
 - wait3 (man 2 wait3)
 - wait4 (man 2 wait4)
 - write (man 2 write)
****

## USAGE
You can try our shell by following these steps:
> **Step 1:** Clone our repository using this command, (you need to have git installed on your machine first)
````
git clone https://github.com/kalbetre-alx/simple_shell.git
````
> **Step 2:** Change directory to simple_shell:
````
cd simple_shell
````
> **Step 3:** Compile the C files in this way:
````
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
````
> **Step 4:** Run the shell
````
./hsh
````
**Exiting the shell**
When you want to exit the shell, you can use one of the following methods:
> **1: Type the command "exit"**
````
exit
````
> **2: Press on Ctrl + D**

## Example of Usage
````
ubunto@ubuntu:~/Bureau/simple_shell$ gcc -Wall -Wextra -Werror -pedantic *.c -o hsh
ubunto@ubuntu:~/Bureau/simple_shell$ ./hsh
#cisfun$ echo Hello, This is an example
Hello, This is an example
#cisfun$ ls
README.md  checkbuild.c  line_exec.c  shell.c  string.c
buildin.c  hsh		 linkpath.c   shell.h
#cisfun$ ^C
#cisfun$ ls -l
total 52
-rw-r--r-- 1 ubunto ubunto  3067 Nov 26 04:22 README.md
-rw-r--r-- 1 ubunto ubunto  2183 Nov 24 16:17 buildin.c
-rw-r--r-- 1 ubunto ubunto   574 Nov 24 15:59 checkbuild.c
-rwxr-xr-x 1 ubunto ubunto 18144 Nov 26 04:22 hsh
-rw-r--r-- 1 ubunto ubunto  2091 Nov 24 14:49 line_exec.c
-rw-r--r-- 1 ubunto ubunto  1926 Nov 24 14:30 linkpath.c
-rw-r--r-- 1 ubunto ubunto   951 Nov 24 16:09 shell.c
-rw-r--r-- 1 ubunto ubunto  1351 Nov 24 15:58 shell.h
-rw-r--r-- 1 ubunto ubunto  1727 Nov 24 14:30 string.c
#cisfun$ exit
ubunto@ubuntu:~/Bureau/simple_shell$
````
## Bugs
No known Bugs.

## TEAM
Kalkidan Betre <kalbetre@icloud.com>
olana korma uki <olikorma@gmail.com>
