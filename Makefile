PROGS=mpimax

all: ${PROGS}

mpimax: src/${PROGS}.c
	rm -rf bin 
	mkdir bin
	mpicc -o bin/${PROGS} src/${PROGS}.c

clean: 
	rm -rf bin/${PROGS}