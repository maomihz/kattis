# CSCE489-501

Competitive Programming Template

## Introduction

This is a template and a Makefile that makes competitive programming super easy!

## Usage

Usually on kattis, each program has an unique problem ID:

> **Problem ID**: wheresmyinternet
>
> **CPU Time limit**: 1 second
>
> **Memory limit**: 1024 MB
>
> **Download:**  
> [Sample data files](#)


Let's solve the [carrots](https://open.kattis.com/problems/carrots) problem as an example.

First of all, create source code and test case files:

```
$ make carrots
```

It creates the following files:

```
src
├── carrots/
│   ├── carrots.cpp
│   ├── carrots1.txt
│   ├── carrots2.txt
│   ├── carrots3.txt
│   ├── carrots4.txt
│   ├── carrots5.txt
│   ├── carrots6.txt
│   ├── carrots7.txt
│   ├── carrots8.txt
│   └── carrots9.txt
```

Modify `carrots.cpp` in your favorite editor. Then, copy each test case into the text files. There are no need to fill in all of the files. To run the program:

```
$ make runcarrots
```

It runs the program while accepting standard input. It is not recommended to use the run command to test sample inputs.

To test the program against sample inputs:

```
$ make testcarrots
```

It runs the program against all test case text files.

To clean the executables:

```
make clean
```

