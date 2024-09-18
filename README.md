# Get Next Line

`get_next_line` is a C implementation of a function that reads a line of text from a file descriptor efficiently. The `get_next_line` function reads input from a file descriptor and returns a complete line each time it is called, allowing large files to be handled without needing to load the entire content into memory at once.

## Project Files

- **`get_next_line.c`**: Contains the main implementation of the `get_next_line` function and helper functions for managing the buffer and reading lines.
- **`get_next_line_utils.c`**: Provides helper functions for string and memory management.
- **`get_next_line.h`**: Header file that declares the functions and defines macros used in the project.

## Features

- **`get_next_line(int fd)`**: Reads a line from the file descriptor `fd` and returns it. Returns `NULL` if the end of the file is reached or if an error occurs. It uses a static buffer to store the remaining data between function calls.

- **`read_line(int fd, char *buffer)`**: Reads data from the file descriptor `fd` into the buffer until a newline character is found or the end of the file is reached. It also handles errors and reallocates memory as needed.

- **`get_line(char *buffer)`**: Extracts and returns the line from the buffer up to and including the newline character. If there is no newline character, it returns the entire buffer content.

- **`update_buffer(char *buffer, char *line)`**: Updates the buffer by removing the portion of the buffer that has already been returned as a line. It shifts the remaining content to the beginning of the buffer and frees unnecessary memory.

## Bonus Features

The mandatory part of the project provides 100% of the required functionality. However, with the bonus, you can achieve a score of 125%.

### Bonus Objective

The bonus part of the project extends the functionality of `get_next_line` to handle multiple file descriptors simultaneously. Instead of using a single static variable to store the buffer for one file descriptor, the implementation uses an array of static buffers. Each buffer corresponds to a different file descriptor.

### Explanation

- **Handling Multiple File Descriptors**: Linux allows a maximum of 1024 file descriptors open at the same time. The bonus implementation interprets the static buffer as an array of buffers, where each index corresponds to a file descriptor. This allows `get_next_line` to track the state of multiple file descriptors in parallel, ensuring that each file descriptor retains its own buffer.
  
- **Practical Use**: This feature is useful when you need to read from multiple files or inputs simultaneously without losing the state of any of them. Each call to `get_next_line_bonus` will return the correct line from the appropriate file.
