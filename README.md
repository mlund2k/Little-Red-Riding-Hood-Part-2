# Little-Red-Riding-Hood-Part-2


The following program implements classes and objects of type Person, Thing, Location, Time, and 
Record to describe the following chronological events laid throughout the Little Red Riding Hood 
story:


1. Little Red Riding Hood wore the Cap
2. Her mom gave her the cake and wine
3. Little Red met the wolf at a particular spot in the wood
4. Grandma was at her own home right outside of the wood and there were three large oak trees 
nearby


This rendition of the program utilizes servers and clients to move People/Thing objects across different programs.
There are three programs that have this function: "hw5Home.cpp", "hw5Forest.cpp", and "hw5GrandmaHome.cpp"

As before, there will be four records that are printed out. Records 1 and 2 are printed in the home,
record 3 is printed in the forest, and record 4 is printed in the grandmather's home.

Instead of recreating Little Red Riding Hood and her things (Cap, Cake, and Wine) these objects are first 
moved from hw5Home.cpp to hw5Forest.cpp through a server. These same objects are then moved again from hw5Forest.cpp to 
"hw5GrandmaHome.cpp". 

**How to run:**
Have your terminal open
Open three tabs, all of them on the directory "hw5"
enter "make" in one of the tabs
In one of your tabs (preferrably the third) run ./grandma
In another tab run ./forest (preferrably in the second tab)
Then in the last open tab run ./house

After completing these steps you will have to close the servers in the other tabs in order to see the created records.
(This is done by just pressing enter without having typed anything)


This program was compiled using Mac and Linux and runs perfectly in such environments.
The program can be run through the terminal using the 'make' command to build and './hw5' to
run the program. If the 'make' command is not properly building, try 'make clean' and then 'make' 
again.


If compiling raises a fatal error on ```#include <json/json.h>```, make sure to run the following commands to install json on your computer:
```sudo apt-get install libjsoncpp-dev```
```sudo ln -s /usr/include/jsoncpp/json/ /usr/include/json```
Credits: https://github.com/stardust95/TinyCompiler/issues/2#issuecomment-410946235
