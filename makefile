# undone
# raw command for compile 
# gfortran HYDRUS.FOR  HYSTER.FOR  INPUT.FOR  MATERIAL.FOR  OUTPUT.FOR  SINK.FOR  SOLUTE.FOR  TEMPER.FOR  TIME.FOR WATFLOW.FOR -o hydrus
# use some makefile variables
objects = HYDRUS.o  HYSTER.o  INPUT.o  MATERIAL.o  OUTPUT.o  SINK.o  SOLUTE.o  TEMPER.o  TIME.o  WATFLOW.o
CC = /usr/bin/gfortran
FFLAGS = -g -ffpe-trap=zero,invalid,overflow,underflow
hydrus: HYDRUS.o  HYSTER.o  INPUT.o  MATERIAL.o  OUTPUT.o  SINK.o  SOLUTE.o  TEMPER.o  TIME.o  WATFLOW.o
	$(CC) -o hydrus $(objects)
%.o : %.FOR
	$(CC) $(FFLAGS) -c $<


clean : 
	rm $(objects)
