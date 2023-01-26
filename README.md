### Here we try to explain the structure of the source code.

## Description of the project
The main goal of this project was to develop an linux utility program for monitoring the system. The key concepts is that the system should work from terminal and display the CPU utilization, RAM usage and so on.

## How to run a project
Open the project
```
mkdir build
```
```
cmake .. && make
```
```
write  ./monitoring to run program
```
Also make sure if you have ncurses library installed on your system. If not, you can install it by running the following command:
```
sudo apt-get install libncurses5-dev libncursesw5-dev
```


## System overview
The system presented in 

# Reference

-[ncurses](https://opensource.com/article/21/8/ncurses-linux)

-[ncurses tutorial](https://tldp.org/HOWTO/NCURSES-Programming-HOWTO/)

-[ncurses text](https://www.linuxjournal.com/content/programming-text-windows-ncurses)

