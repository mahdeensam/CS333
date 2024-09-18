import time
from threading import Thread

# Function to simulate the idea of threads working on tasks
def write_poem_line(line, delay):
    time.sleep(delay)  # Simulate the time taken by a thread to process
    print(line)

# Poem lines representing tasks done by different threads
poem_lines = [
    "Threads, in silken bytes, weave through the core,",
    "Each a lifeline cast in silicon seas.",
    "Swift they race, the humming looms' soft roar,",
    "Twisting data strands with nimble ease.",
    "Mutex gates guard the sacred shared lore,",
    "Locks and keys in digital decrees.",
    "Memory’s keep, where cached dreams are stored,",
    "Writ in code, the craft of minds at peace.",
    "Parallel paths in logic's deep maze,",
    "Converge where thoughts and threads entwine.",
    "A symphony in silicon's blaze,",
    "Each note a byte in flawless design.",
    "In the mesh of minds, our fates are cast,",
    "Threads of thought, in time's vast web vast."
]

# Create and start threads
threads = []
for index, line in enumerate(poem_lines):
    # Creating a thread for each line of the poem
    thread = Thread(target=write_poem_line, args=(line, index * 0.5))
    threads.append(thread)
    thread.start()

# Wait for all threads to finish
for thread in threads:
    thread.join()

print("\nPoem complete!")
