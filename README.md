### SETUP

## Description of the project
The main goal of this project was to develop an linux utility program for monitoring the system. The key concepts is that the system should work from terminal and display the CPU utilization, RAM usage and so on.

## How to run a project
Open the project
```bash
mkdir build
```
```bash
cmake .. && make
```
write
```bash
./monitoring
```
to start the project.

### Additional information if you have any problems

If any error occurs, make sure you have installed the ncurses library.

Or detele build folder:
```bash
rm -rf build
```
and run the following command again:
```bash
mkdir build && cd build && cmake .. && make
```

Also make sure if you have ncurses library installed on your system. If not, you can install it by running the following command:
```bash
sudo apt-get install libncurses5-dev libncursesw5-dev
```


## More details about the project [check the following link](top_monitor.md)



    


# Reference

- [ncurses](https://opensource.com/article/21/8/ncurses-linux)
- [ncurses tutorial](https://tldp.org/HOWTO/NCURSES-Programming-HOWTO/)
- [ncurses text](https://www.linuxjournal.com/content/programming-text-windows-ncurses)

