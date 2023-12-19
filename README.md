# SEA BATTLE OOP PROJECT
To enhance my understanding of the c++ language, i chose to make a sea battle game 
This game can be played either against AI or an other player.
## System requirements
```
Operating system   : a flavour of linux
Software           : GCC compiler(g++) & cmake(minimum version = 3.22.1)
libraries          : nlohmann(for data serialization)
```
## Build manual

### disclaimer
this build manual is made for ubuntu but can also be applied to other linux distro's but commands might have to be adjusted depending on the Operating system in use.

### 1. install necessary software
before you're able to compile the program you need to make sure g++ and cmake are both installed and work correctly. 
To test if you installed the GCC compiler correctly, this can be done by writing a simple "hello world!" program and testing if it compiles.

```
sudo apt install build-essential
```
The installation of cmake is done using the following command
```
sudo apt-get -y install cmake
```
### 2. Building the project
The project is build using the "CMakeLists.txt". First start of by making a build folder inside the projects folder, This will be the destination where the executable will be generated.
```
mkdir build
```
After making the folder you will need to build the makefile using the following command.
```
cmake ..
```
Once the Makefile has been created you can now compile the project using the following command:
```
cmake --build .
```
This shoudl leave you with an executable that can be executed using the following command:
```
/.filename
```
filename is the name of the executable file
