#!/bin/bash
#SBATCH --job-name=mpi-max-demo
#SBATCH --ntasks=3
#SBATCH --output=mpimaxdemo.out
mpirun ./bin/mpimax 5