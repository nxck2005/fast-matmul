#!/bin/bash

SCRIPTS=("naivematmul" "seqmatmul" "mpthreadedmatmul")

for SCRIPT in "${SCRIPTS[@]}"
do
    echo "Running perf stat for $SCRIPT..."
    perf stat "./$SCRIPT" 2> "${SCRIPT}_perf_report.txt"
    echo "Report saved to ${SCRIPT}_perf_report.txt"
    echo "------------------------------------"
done