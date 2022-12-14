# **Simple Shell Project**

## **Introduction to Project:**
This simple shell project its a collaboration between Luis Baute and Rodrigo Olivera, two computer software engineering students.
This repository contains every file required to make this projects possible. Which consists of developing our own UNIX command interpreter (Simple Shell).


## What is a Shell
The **shell** is a program that interacts with the user through a terminal or takes the input from a file and executes a sequence of commands that are passed to the Operating System. 
 
## About our Project
The aim of this project, presented to every group of Cohort 18 is to face and learn how the real shell works, by going through the creation of its simple version and also by using some of our own created functions.

## Allowed functions and System calls
-   `access`  (man 2 access)
-   `chdir`  (man 2 chdir)
-   `close`  (man 2 close)
-   `closedir`  (man 3 closedir)
-   `execve`  (man 2 execve)
-   `exit`  (man 3 exit)
-   `_exit`  (man 2 _exit)
-   `fflush`  (man 3 fflush)
-   `fork`  (man 2 fork)
-   `free`  (man 3 free)
-   `getcwd`  (man 3 getcwd)
-   `getline`  (man 3 getline)
-   `getpid`  (man 2 getpid)
-   `isatty`  (man 3 isatty)
-   `kill`  (man 2 kill)
-   `malloc`  (man 3 malloc)
-   `open`  (man 2 open)
-   `opendir`  (man 3 opendir)
-   `perror`  (man 3 perror)
-   `read`  (man 2 read)
-   `readdir`  (man 3 readdir)
-   `signal`  (man 2 signal)
-   `stat`  (__xstat) (man 2 stat)
-   `lstat`  (__lxstat) (man 2 lstat)
-   `fstat`  (__fxstat) (man 2 fstat)
-   `strtok`  (man 3 strtok)
-   `wait`  (man 2 wait)
-   `waitpid`  (man 2 waitpid)
-   `wait3`  (man 2 wait3)
-   `wait4`  (man 2 wait4)
-   `write`  (man 2 write)## Switch to another file

## What our Shell can Handle
- It handles interactive mode
- A non interactive mode
- Handles Built-in commands
- env (built-in)
- exit [arguments] (built-in)
- Executes any command with its arguments
- Commands with or without flags
- Handles 'Ctrl+d' (end of program)
- It can Handle errors too

## Files
- AUTHORS
- man.simple_shell
- main.h (The header file)
- shell.c
- functions.c
- aux_functions.c
## Compiling 

Our Shell will be compiled this way: 
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
# Example of usage

![](https://i.imgur.com/955zGDO.png)
