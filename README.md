# Command-line utility used to search for specific text patterns within files

the aim of this project is to locate a specific word inside all files located in a given directory and its subdirectories. If the word is found in a file, it prints the file’s path.


A simple C program that recursively searches through a directory and finds files containing a specified word or text.

The project uses the `nftw()` function to walk through the directory structure and checks each file for the requested word.

## How It Works

The program takes two arguments:

```text
directory path
word to search
```

For each file in the directory, the program reads its contents line by line and checks whether the specified word is present.

If the word is found, the file path is printed.

## Usage

Compile the program:

```bash
gcc main.c -o Lab11bmmN32511
```

Run the program:

```bash
./Lab11bmmN32511 [directory path] [word to search]
```

Example:

```bash
./Lab11bmmN32511 /home/user/Documents password
```

The program will recursively search the directory and print the paths of files containing `password`.

## Options

Show help:

```bash
./Lab11bmmN32511 -h
```

Show version:

```bash
./Lab11bmmN32511 -v
```

## Technologies

* C
* `nftw()`
* File I/O
* Recursive directory traversal
* String searching


(to locate the target searching in all the system files it can be using " / " in the place holder of the path)

exmaple usage

![image](https://github.com/user-attachments/assets/dfd62a70-0d66-4899-a997-a63a66bf3585)
