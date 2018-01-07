# undone
# raw command for compile 
# gfortran HYDRUS.FOR  HYSTER.FOR  INPUT.FOR  MATERIAL.FOR  OUTPUT.FOR  SINK.FOR  SOLUTE.FOR  TEMPER.FOR  TIME.FOR WATFLOW.FOR -o hydrus
# use some makefile variables

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
	CC = /usr/local/bin/gfortran
endif
ifeq ($(UNAME_S),Linux)
	CC = /usr/bin/gfortran
endif

objects = HYDRUS.o  HYSTER.o  INPUT.o  MATERIAL.o  OUTPUT.o  SINK.o  SOLUTE.o  TEMPER.o  TIME.o  WATFLOW.o
FFLAGS = -g
hydrus: HYDRUS.o  HYSTER.o  INPUT.o  MATERIAL.o  OUTPUT.o  SINK.o  SOLUTE.o  TEMPER.o  TIME.o  WATFLOW.o
	$(CC) -o hydrus $(objects)
%.o : %.FOR
	$(CC) ${FLAGS} -c $<
clean : 
	rm $(objects)
