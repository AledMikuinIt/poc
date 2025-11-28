# Pointer-Chasing Project – Microarchitecture Analysis
## Disclaimer

This project is still a work in progress. Please check the work branch for ongoing development.

## Description

This project explores pointer-chasing patterns in memory to study CPU microarchitecture effects, such as cache behavior and TLB misses. It implements two different memory layouts to benchmark how memory access patterns affect performance.

## Main Functionalities

- Linear dispatch: memory allocated contiguously.
- Randomized dispatch: memory allocated with 4KB alignment and shuffled using Fisher-Yates.
- Python script for analysis: visualize and analyze benchmark results.

# Goals

- Compare CPU performance (cache misses, TLB behavior) between predictable and random memory layouts.
- Demonstrate knowledge in low-level C programming, memory management, and performance measurement.
- Explore microarchitecture effects in a hands-on, experimental way.
