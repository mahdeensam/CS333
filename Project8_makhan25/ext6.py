import numpy as np
import threading
import time

# Define matrix dimensions
M, N, P = 500, 500, 500

# Initialize matrices A and B with random values
A = np.random.randint(10, size=(M, N))
B = np.random.randint(10, size=(N, P))
C = np.zeros((M, P))

# Function to perform matrix multiplication for a range of rows
def matrix_multiply(start_row, end_row):
    global A, B, C
    for i in range(start_row, end_row):
        for j in range(P):
            C[i][j] = sum(A[i][k] * B[k][j] for k in range(N))

# Function to create and manage threads
def parallel_matrix_multiplication(num_threads):
    threads = []
    rows_per_thread = M // num_threads

    for i in range(num_threads):
        start_row = i * rows_per_thread
        end_row = (i + 1) * rows_per_thread if i != num_threads - 1 else M
        thread = threading.Thread(target=matrix_multiply, args=(start_row, end_row))
        threads.append(thread)
        thread.start()

    for thread in threads:
        thread.join()

if __name__ == "__main__":
    num_threads_list = [1, 2, 4, 8]

    for num_threads in num_threads_list:
        # Reset matrix C
        C.fill(0)

        start_time = time.time()
        parallel_matrix_multiplication(num_threads)
        end_time = time.time()

        print(f"Time taken with {num_threads} threads: {end_time - start_time:.6f} seconds")

    # Uncomment below lines to verify the result
    # C_serial = np.dot(A, B)
    # print("Is the parallel result correct?", np.allclose(C, C_serial))
