# Detect architecture
ARCH := $(shell uname -m)

# Required flags
RFLAGS = -Wall -ansi -pedantic

# Architecture-specific settings
ifeq ($(ARCH),aarch64)
	# ARM 64-bit
	RFLAGS += -m32
endif

# Main target
palindrome: palindrome.c
	gcc $(RFLAGS) -o palindrome palindrome.c

# Clean target
clean:
	rm -f palindrome
