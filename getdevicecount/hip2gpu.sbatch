#!/bin/bash
#SBATCH -J OneFLOW
#SBATCH -p kshdtest
#SBATCH -N 1
#SBATCH -n 16
#SBATCH --gres=dcu:2
#SBATCH -t 00:01:00
#SBATCH -o %j
#SBATCH -e %j

date
hostname
./main
date
