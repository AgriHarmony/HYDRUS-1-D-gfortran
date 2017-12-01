# HYDRUS 1-D with gfortran 

## Environment
- ubunut 16.04
- gfortran(gcc version 5.4.0)

## Usage

1. Copy exmaple related data folder from 
    - data/Examples/Direct
    - data/Exmaples/HP1
    - data/Exmaples/Inverse
    - data/Exmaples/Unstach
If you want to run Direct/TEST10, then
```
cp -r data/Examples/Direct/Test10 input_output/.
```
Optional: Set path in LEVEL_01.DIR  

Compile the HYDRUS source code then run
```
make;make clean;./hydrus;
```
## Directory
- original_file : the original source file directly download from website content ( for backup/recover)
- input_output : hydrus executable will read computation data (parameter/data ..etc)
- LEVEL_01.DIR : Set input/output directory. Default setup is __input_output__. 



