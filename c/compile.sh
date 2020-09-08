#!/bin/bash
# compile c++ file

# compile source
g++ $1 -o test

# output results
echo "OK"

# execuate
./test
