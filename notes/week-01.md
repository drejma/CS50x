# Week 1 C

Sources: [Lecture 1](https://cs50.harvard.edu/x/2023/notes/1/) | [Data Types](https://cdn.cs50.net/2017/fall/shorts/data_types/data_types.pdf) | [Operators](https://cdn.cs50.net/2017/fall/shorts/operators/operators.pdf) | [Conditional Statements](https://cdn.cs50.net/2017/fall/shorts/conditional_statements/conditional_statements.pdf) | [Loops](https://cdn.cs50.net/2017/fall/shorts/loops/loops.pdf) | [Command Line](https://cdn.cs50.net/2017/fall/shorts/command_line/command_line.pdf) | [Magic Numbers](https://cdn.cs50.net/2017/fall/shorts/magic_numbers/magic_numbers.pdf)

## VS Code UI

- this course uses its own [VS Code](https://code.cs50.io/) workspace

<img src="images/ide.png" width="720px">

- in the image above:
	- on the left side, there is a *file explorer* 
	- in the right upper part, there is a *text editor*
	- in the right lower part, there is a *command line interface (CLI)*

## Command Line

- `code hello.c` (CS50-only) creates or opens hello.c
- `make hello` (CS50-only) compiles hello.c into hello
- `./hello` executes hello program
- `ARROW UP/DOWN` switches between previous/next terminal commands
- `CTRL + L` clears terminal
- `CTRL + C` terminates running program
- `pwd` (present working directory)
- `ls` gives readout of all the files and folders in `pwd`
- `mkdir <name>` (make directory) creates a new directory in `pwd`
- `cd <relative-path>` (change directory) changes `pwd`
	- `cd ..` jumps to parent directory
- `cp <source> <destination>` makes a copy of a file, or directory
	- e.g. `cp hello.txt hi.txt`
	- `cp -r dir1 dir2` makes a copy of a directory, including files inside
- `mv <source> <destination>` moves (renames) a file, or directory
- `rm <file>` deletes a file
	- `rm -f <file>` deletes without confirmation
	- `rm -r <directory>` deletes a directory

## Hello World

```c
#include <stdio.h>

int main(void)
{
	printf("Hello, world\n");
}
```

- in the code above:
	- `#include <stdio.h>` imports `stdio.h` library
	- `printf()` is a function that displays its arguments (in brackets) on the screen
	- `\n` is an [escape sequence](https://en.wikipedia.org/wiki/Escape_sequences_in_C) for a new line
- for more information, see [CS50x: Manual Pages](https://manual.cs50.io/)

## Data Types

- types refer to the possible data that can be stored within a variable:
	- `int`, integers -2 billions to +2 billions (32 bits)
	- `unsigned int`, positive integers 0 to +4 billions
	- `long`, integers with more bits
	- `char`, single ASCII character (8 bits)
	- `float`, floating-point value (32 bits)
	- `double`, floating-point value (64 bits)
	- `void`, placeholder for “nothing”
	- `bool`, true or false (`cs50.h` library only); in C, every nonzero value is considered `true`, zero is `false`
	- `string`, string of characters (`cs50.h` library only)

## Variables

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
	string answer = get_string("What's your name? ");
	printf("Hello, %s\n", answer);
}
```

- in the code above:
	- `get_string()` is a `cs50.h` library function
	- `answer` is a string variable
	- `%s` is a string placeholder for `printf` function

## Operators

- assignment operators:
	- `=` assigns value to a variable
- logical operators:
	- `&&` (AND) is true if both operands are true
	- `||` (OR) is true if at least one operand is true
	- `!` (NOT) inverts the value of its operand, e.g. if `x` = true, then `!x` = false
- relational operators:
	- `==` tests for equality of two variables
	- `!=` tests for inequality of two variables
- arithmetic operators:
	- `+` addition, `-` subtraction, `*` multiplication, `/` division
	- `%` modulo (remainder)

## Comments

- comments are issued by `//`, followed by a comment

## Conditionals

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
	// Prompt user to agree
	char c = get_char("Do you agree? ");
	
	// Check whether agreed
	if (c == 'Y' || c == 'y')
	{
		printf("Agreed\n");
	}
	else if (c == 'N' || c == 'n')
	{
		printf("Not agreed\n");
	}
}
```

### Conditional Statements

- if statement

```c
if /* bool_expression */
{
	/* do_something */;
}
else 
{
	/* do_something */;
}
```

- switch

```c
int var_name = get_int();
switch(var_name)
{
	case /* checked_value_1 */:
		/* do_something */;
		break;
		
	case /* checked_value_2 */:
		/* do_something */;
		break;
		
	default:
		/* do_something */;
}
```

- ?: ternary operator

```c
int var_name = /* bool_expression */ ? 5 : 6;
```

## Loops

```c
#include <stdio.h>

int main(void)
{
	for (int i = 0; i < 3; i++)
	{
		printf("Meow\n");
	}
}
```

- in the code above:
	- `int i = 0` initializes `i` with a value 0
	- `i < 3` tells the loop to run as long as `i` is less than 3
	- `i++` tells the loop to increment `i` after every loop cycle
- other methods to increment a value of a variable:
	- `i = i + 1`
	- `i += 1`

### Loop Statements

- while

```c
while /* bool_expression */
{
	/* do_something */
}
```

- do while

```c
do
{
	/* do_something */;
}
while /* bool_expression */;
```

- for loop

```c
for (int var_name = 0; var_name < 10; var_name++)
{
	/* do_something */;
}
```

## Abstraction

- abstraction is the act of simplifying a problem into smaller problems
- complete or repeated blocks of code can be (and should be) abstracted into separate functions

```c
#include <cs50.h>
#include <stdio.h>

int get_size(void);
void print_grid(int n);

int main(void)
{
	int n = get_size();
	print_grid(n);
}

int get_size(void)
{
	int n;
	do
	{
		n = get_int("Size: ");
	}
	while (n < 1);
	return n;
}

void print_grid(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("#");
		}
		printf("\n");
	}
}
```

- in the code above, `main()` is the main function that calls two (abstracted) functions `get_size()` a `print_grid()`

## Magic Numbers

- C provides a preprocessor directive (also called a macro) for creating symbolic constants, which goes through a code and replaces `NAME` with `REPLACEMENT` at the time program is compiled
- `#define NAME REPLACEMENT`
	- `#define PI 3.14159265`
	- `#define COURSE “CS50”`
	- `#define DECKSIZE 52`

```c
#define DECKSIZE 52

card deal_cards(deck name)
{
	for (int i = 0; i < DECKSIZE; i++)
	{
		/* do_something */;
	}	
}
```
