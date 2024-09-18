import threading
import time

# Shared counter variable
counter = 0

# Mutex lock to control access to the critical section
mutex = threading.Lock()

# Function to be run by each thread
def increment_counter(thread_id):
    global counter
    for i in range(3):
        # Acquire the mutex lock before entering the critical section
        mutex.acquire()
        try:
            # Critical section: increment the counter
            counter += 1
            print(f"Thread {thread_id}: Counter value after increment {i + 1}: {counter}")
        finally:
            # Release the mutex lock
            mutex.release()
        # Simulate some work with a sleep
        time.sleep(0.1)

# Number of threads
NUM_THREADS = 4

# Create and start threads
threads = []
for i in range(NUM_THREADS):
    thread = threading.Thread(target=increment_counter, args=(i,))
    threads.append(thread)
    thread.start()

# Wait for all threads to finish
for thread in threads:
    thread.join()

print(f"\nFinal counter value: {counter}")
