import matplotlib.pyplot as plt
import numpy as np

# Initialize lists to store the data
memory_sizes = []
time_chunks = []
stddev_chunks = []
time_atonce = []
stddev_atonce = []

# Read data from the results file
with open('results.txt', 'r') as file:
    for line in file:
        size, chunks, chunks_std, atonce, atonce_std = map(float, line.split())
        memory_sizes.append(size)
        time_chunks.append(chunks)
        stddev_chunks.append(chunks_std)
        time_atonce.append(atonce)
        stddev_atonce.append(atonce_std)

# Convert lists to numpy arrays for better handling
memory_sizes = np.array(memory_sizes)
time_chunks = np.array(time_chunks)
stddev_chunks = np.array(stddev_chunks)
time_atonce = np.array(time_atonce)
stddev_atonce = np.array(stddev_atonce)

# Plot 1: Comparison of Average Time
plt.figure(figsize=(12, 6))
plt.plot(memory_sizes, time_atonce, 'o-', label='All at once')
plt.plot(memory_sizes, time_chunks, 'o-', label='Chunks')
plt.xlabel('Memory Size (integers)')
plt.ylabel('Average Time Taken (ns)')
plt.title('Comparison of Average Time Taken')
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.show()

# Plot 2: Comparison of Standard Deviation
bar_width = 0.35
index = np.arange(len(memory_sizes))

plt.figure(figsize=(12, 6))
plt.bar(index, stddev_atonce, bar_width, label='All at once')
plt.bar(index + bar_width, stddev_chunks, bar_width, label='Chunks')
plt.xlabel('Memory Size (integers)')
plt.ylabel('Standard Deviation (ns)')
plt.title('Comparison of Standard Deviation')
plt.xticks(index + bar_width / 2, memory_sizes)
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.show()

# Plot 3: Combined Plot
fig, ax1 = plt.subplots(figsize=(12, 6))

color = 'tab:blue'
ax1.set_xlabel('Memory Size (integers)')
ax1.set_ylabel('Average Time Taken (ns)', color=color)
ax1.plot(memory_sizes, time_atonce, 'o-', label='All at once', color=color)
ax1.plot(memory_sizes, time_chunks, 'o-', label='Chunks', color='tab:orange')
ax1.tick_params(axis='y', labelcolor=color)

ax2 = ax1.twinx()  # Instantiate a second y-axis that shares the same x-axis
color = 'tab:green'
ax2.set_ylabel('Standard Deviation (ns)', color=color)
ax2.plot(memory_sizes, stddev_atonce, 's--', label='Stddev All at once', color=color)
ax2.plot(memory_sizes, stddev_chunks, 's--', label='Stddev Chunks', color='tab:red')
ax2.tick_params(axis='y', labelcolor=color)

fig.tight_layout()
plt.title('Combined Plot: Average Time and Standard Deviation')
fig.legend(loc='upper left', bbox_to_anchor=(0.1,0.9))
plt.grid(True)
plt.show()

# Plot 4: Scatter Plot with Standard Deviation as Point Size
plt.figure(figsize=(12, 6))
sizes_atonce = stddev_atonce * 10  # Scale sizes for better visibility
sizes_chunks = stddev_chunks * 10  # Scale sizes for better visibility
plt.scatter(memory_sizes, time_atonce, s=sizes_atonce, alpha=0.5, label='All at once')
plt.scatter(memory_sizes, time_chunks, s=sizes_chunks, alpha=0.5, label='Chunks')
plt.xlabel('Memory Size (integers)')
plt.ylabel('Average Time Taken (ns)')
plt.title('Scatter Plot with Standard Deviation as Point Size')
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.show()
