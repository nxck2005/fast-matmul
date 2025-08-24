# 24th Aug
Starting with implementing naive matmul. Using default allocator

### Plan:
Naive Baseline: 1x

Custom Allocator: 1.05x (better memory patterns)

Cache Blocking: 3x (algorithmic cache improvement)

AVX2 SIMD: 6-8x (vectorization gains)

Strassen Full: 10-50x total vs naive

# 25th August

## Profiling:
Took help from Claude to learn these:

Compile for profiling:

### For perf:
gcc -g -O3 your_code.c -o matmul

### For gprof:
gcc -pg -O3 your_code.c -o matmul_gprof
./matmul_gprof
gprof matmul_gprof gmon.out > analysis.txt

### For timing or basic profiling:
gcc -g -O3 your_code.c -o matmul
./matmul


## Steps (perf):

### Compile with debug info
gcc -g -O3 your_code.c -o matmul

### Basic timing
perf stat ./matmul

### Detailed profiling
perf record ./matmul
perf report

### Cache analysis
perf stat -e cache-misses,cache-references ./matmul


## Steps (gprof, function level profiling):
gcc -pg -O3 your_code.c -o matmul_gprof
./matmul_gprof
gprof matmul_gprof gmon.out > analysis.txt

## For built in timing:

#include <time.h>
clock_t start = clock();
// your matrix multiply code
clock_t end = clock();
double time_spent = ((double)(end - start)) / CLOCKS_PER_SEC;