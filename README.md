# HYDRUS 1-D with gfortran 

## Introduction
The program numerically solves the Richards' equation for saturated-unsaturated water flow and Fickian-based advection dispersion equations for heat and solute transport.

- The Flow equation incorporates a sink term to account for water uptake by plant roots.
- The Heat transport equation considers conduction as well as convection with flowing water.
- The Solute transport equations consider advective-dispersive transport in the liquid phase, and diffusion in the gaseous phase

excerpt from [official website](https://www.pc-progress.com/en/Default.aspx?h1d-description)

## Disclaimer

This repository __only__ is small modification which make source code running on linux machine. If you have any problem about compuation model itself, post your question on [official forum](http://www.pc-progress.com/forum/viewforum.php?f=4)


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



