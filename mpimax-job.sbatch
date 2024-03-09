#!/bin/bash
#SBATCH --job-name=mpi-max-demo
#SBATCH --ntasks=3
#SBATCH --output=%x_%j.out
mpirun ./bin/mpimax