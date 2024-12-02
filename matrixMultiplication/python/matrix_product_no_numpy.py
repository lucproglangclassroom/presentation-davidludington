import random
import time

def allocate_and_fill(n):
    A = [[random.random() for _ in range(n)] for _ in range(n)]
    B = [[random.random() for _ in range(n)] for _ in range(n)]
    C = [[0.0 for _ in range(n)] for _ in range(n)]
    return A, B, C

def matrix_multiply(A, B, C, n):
    for i in range(n):
        for j in range(n):
            C[i][j] = 0.0
            for k in range(n):
                C[i][j] += A[i][k] * B[k][j]
    return C

# Matrix sizes
n_large = 500
n_small = 100

# Timing for large matrix
A, B, C = allocate_and_fill(n_large)
start = time.time()
C = matrix_multiply(A, B, C, n_large)
finish = time.time()
elapsed_large = finish - start
print(f"Time taken for {n_large}x{n_large} matrix: {elapsed_large:.6f} seconds")

# Timing for small matrix
A, B, C = allocate_and_fill(n_small)
start = time.time()
C = matrix_multiply(A, B, C, n_small)
finish = time.time()
elapsed_small = finish - start
print(f"Time taken for {n_small}x{n_small} matrix: {elapsed_small:.6f} seconds")
