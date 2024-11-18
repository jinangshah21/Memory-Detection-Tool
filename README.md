# Memory-Detection-Tool

**Overview**
This repository contains a Memory Leak Detection Tool implemented in C. It provides functionalities to track memory allocations and deallocations across processes using shared memory and offers an interactive monitor to display memory usage, detect potential memory leaks, and visualize their severity using color-coded output.

**Features**
- Tracks memory allocation and deallocation of processes in real-time.
- Detects and calculates memory leaks for each process.
- Displays memory leak severity with color-coded output:
    Green: Low memory leak percentage (<10%)
    Yellow: Moderate memory leak percentage (10% - 50%)
    Red: High memory leak percentage (>50%)
- Periodically updates and displays memory usage statistics.
- Supports the monitoring of up to 1024 processes simultaneously.

**File Structure**
1. `my_mem.h`
- Defines the ProcessMemoryInfo struct to store memory information.
- Implements shared memory management to track process data.
- Provides custom memory allocation functions (my_malloc, my_free, my_realloc, my_calloc) for tracking memory usage.
- Utility functions for:
- Initializing shared memory.
- Tracking processes and memory usage.
- Displaying memory usage statistics in a tabular format with date and time.
  
2. `monitor.c`
- The main program that runs the Memory Leak Monitor.
- Continuously updates and displays memory statistics.
- Detects and removes terminated processes from the shared memory.
- Provides a real-time view of memory leak statuses.

**Prerequisites**
- GCC compiler
- POSIX-compliant operating system (Linux/Unix-based)
- ncurses library for terminal management (optional)

**Usage**
- Include my_mem.h in your C programs to track memory allocations.
- Replace standard memory functions (malloc, free, realloc, calloc) with custom functions (my_malloc, my_free, my_realloc, my_calloc) to enable memory tracking.
- Run the Monitor to observe memory usage statistics.

**How It Works**
- Shared Memory: Uses shmget and shmat to maintain a shared memory segment for storing process memory information.
- Process Tracking: Tracks each process using its PID and maintains statistics such as allocated and deallocated memory, memory leaks, and timestamps.
- Custom Allocators: Overrides standard memory functions to log allocation/deallocation sizes to shared memory.
- Monitor: Periodically reads shared memory to display updated memory statistics.
- Color-codes memory leaks for better visualization.

**Error Handling**
- Handles failures in shared memory initialization or access with descriptive error messages.
- Automatically removes terminated processes to prevent stale entries.

**Reference** 
- https://youtu.be/a1_FyEh9Efs?si=HSypwPzPsCLzjQ91
- https://www.geeksforgeeks.org/ipc-shared-memory/
