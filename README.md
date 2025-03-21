# MMN 11

This repository contains two C programs implemented as part of the first programming assignment:

1. **Palindrome Detector**
2. **Count Zero Bits**

## Folder Structure

```
.
├── palindrome/
│   ├── palindrome.c
│   ├── Makefile
│   └── data/
│       ├── input1.txt
│       └── ...
├── count_zero_bits/
│   ├── count_zero_bits.c
│   ├── Makefile
│   └── data/
│       ├── input1.txt
│       └── ...
└── do_it.sh
```

## Palindrome Detector

### Description
The palindrome program checks whether a given string is a palindrome. A palindrome is a sequence of characters that reads the same forward and backward (ignoring spaces and tabs).

### Implementation Details
- Located in `palindrome.c`
- Using pointers for cleaner code
- Ignores spaces and tabs
- Returns 1 if the input is a palindrome, 0 otherwise
- Maximum input line size is 80 characters

```c
int palindrome(char s[], int length) {
    char *start = s;
    char *end = s + length - 1;
    while (start < end) {
        if (*start == ' ' || *start == '\t') {
            start++;
            continue;
        }
        if (*end == ' ' || *end == '\t') {
            end--;
            continue;
        }
        if (*start != *end) return 0;
        start++;
        end--;
    }
    return 1;
}
```

## Count Zero Bits

### Description
The count zero bits program counts the number of bits with value 0 in the binary representation of a given positive integer.

### Implementation Details
- Located in `count_zero_bits.c`
- Inverting bits for easier implementation
- Efficient implementation using bit manipulation
- Returns the count of zero bits

```c
int count_zero_bits(int x) {
    unsigned int inverted = ~x;
    int zero_bits = 0;
    while (inverted > 0) {
        inverted &= (inverted - 1);
        zero_bits++;
    }
    return zero_bits;
}
```

## How to Build and Run

Each program can be built using the included Makefile:

```bash
cd palindrome
make
```

Or:

```bash
cd count_zero_bits
make
```

To run a program:

```bash
./palindrome
# or
./count_zero_bits
```

## Testing

The repository includes an automated testing system implemented as a bash script (`do_it.sh`). The script:

1. Compiles each program using its Makefile
2. Runs each program against test inputs stored in the respective `data/` directory
3. Displays the results of each test

To run all tests:

```bash
bash do_it.sh
```

## Author

Yaniv Tsvi Schweitzer
Open University of Israel