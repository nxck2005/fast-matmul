## 24th Aug
Starting with implementing naive matmul. Using default allocator

### Plan:
Naive Baseline: 1x

Custom Allocator: 1.05x (better memory patterns)

Cache Blocking: 3x (algorithmic cache improvement)

AVX2 SIMD: 6-8x (vectorization gains)

Strassen Full: 10-50x total vs naive