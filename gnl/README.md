# get_next_line
get_next_line project from the 42-core-curriculum

## Table of contents

1. [About](#about)
2. [Description](#description)

## About

get_next_line is one of the first projects a student will encounter while studying at 42. 
The goal of the project is to write to discover satic variables and to learn about filedescriptors.

| Prototype | Description | Used functions |
| :---      | :--         | :---           |
| ```int get_next_line(int fd, char **fd)```| reads one line from open fd, returns -1 on error 0 on EOF and 1 if a line has been read | malloc, free |

**How to use:**

Clone the repository:
```bash
git clone https://github.com/ayeCaptainJack/get_next_line.git
```

include get_next_line.h in your programm
```c
#include "get_next_line.h"
```

compile your programm with the .c files and the -D BUFFER_SIZE=X option with X being the read size
```bash
gcc -YOURFLAGS -D BUFFER_SIZE=x YOUR_C_FILES get_next_line.c get_next_line_utils.c
```
## Description

**usage:**

get_next_line gets called with a filedescriptor (fd) and a pointer to a string in which it will store the read-line. The string is allocated and needs to be proplery freed to avoid leaks. The function saves read characters in a buffer if it read more than one line. Therefor not reading a file to the end could produce
leaks.

**return values:**

get_next_line returns 1 if it succesfully read a line. It will return 0 if it found the end of the file and -1 on error. An error happens if it can't read from the
fd, a heap allocation-error occurs or if the BUFFER_SIZE is below 1. 

**BUFFER_SIZE:**

get_next_line uses the define BUFFER_SIZE to read from the files. For perfomance you would use a large BUFFER_SIZE because read-calls are slow and the larger the BUFFER_SIZE the less read-calss get_next_line does.
If you want to use less memory you would use a small BUFFER_SIZE because get_next_line will allocate less unused memory on the heap.

**multiple fd reading:**

because I finished the bonus part it is possible to read from different files without finishing reading one first. But be carefull if you dont read a file to the end
get_next_line could produce some leaks.
