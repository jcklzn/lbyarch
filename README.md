# Dot Product in C and Assembly
by: Jack Elinzano

## Average Execution Time 
| Kernel          | C Implementation | Assembly Implementation |
|-----------------|------------------|-------------------------|
| Debug Mode (2^20) | 0.0023458        | 0.0010892                |
| Release Mode (2^20) | 0.0015138         | 0.0015682                |
| Debug Mode (2^24) | 0.0360498         | 0.0168895                |
| Release Mode (2^24) | 0.0149568         | 0.0153126               |
| Debug Mode (2^28) | 4.3060264         | 1.6599135                |
| Release Mode (2^28) | 3.032059         | 2.0692571                |

## Analysis of Results
ASM is faster for any implementation and any run for Debug mode. However, for Release mode, C implementation became drastically faster while assembly became quite inconsistent and was even slower than C in some tests. 
