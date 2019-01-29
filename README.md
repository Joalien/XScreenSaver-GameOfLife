# XScreenSaver-GameOfLife
New XScreenSaver based on John Conway's Game of Life. It currently provides only two hyperparameters : size and noise.

This programm is created in order to be a submodule of [XScreenSaver](https://github.com/porridge/xscreensaver) and its goal is to provide customizable screensaver for users.

## How to run ?

* Clone the repository  
 ```
git clone https://github.com/Joalien/XScreenSaver-GameOfLife.git
 ```
 
 * Move inside the repository  
``` 
cd XScreenSaver-GameOfLife 
```

 * Create a makefile  
 ```
 cmake .
 ```
 
 * Create an executable  
 ```
 make
 ```
 
 * Launch the screensaver :)
 ```
 ./GameOfLife
 ```

## Note  

This project has been tested only on a 64 bit mageia:6 distribution.  
**This might be not running on other architectures or distribution !**  

if any problems occur, contact Josquin CORNEC <josquin64@laposte.net>
