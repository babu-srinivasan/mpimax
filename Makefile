PROGS=mpimax

all: ${PROGS}

mpimax: src/${PROGS}.c
	mpicc -o bin/${PROGS} src/${PROGS}.c

clean: 
	rm -f bin/${PROGS}