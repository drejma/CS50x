# Week 3 Algorithms

Sources: [Lecture 3](https://cs50.harvard.edu/x/2023/notes/3/) | [Linear Search](https://cdn.cs50.net/2017/fall/shorts/linear_search/linear_search.pdf) | [Binary Search](https://cdn.cs50.net/2017/fall/shorts/binary_search/binary_search.pdf) | [Selection Sort](https://cdn.cs50.net/2017/fall/shorts/selection_sort/selection_sort.pdf) | [Bubble Sort](https://cdn.cs50.net/2017/fall/shorts/bubble_sort/bubble_sort.pdf) | [Merge Sort](https://cdn.cs50.net/2017/fall/shorts/merge_sort/merge_sort.pdf) | [Recursion](https://cdn.cs50.net/2017/fall/shorts/recursion/recursion.pdf)

## Structures

- *structures* are custom data types created via `struct`

```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
	string name;
	string number;
}
person;

int main(void)
{
	person people[2];
	
	people[0].name = "Carter";
	people[0].number = "+1-617-495-1000";
	
	people[1].name = "David";
	people[1].number = "+1-949-468-2750";
	
	// Search for name
	string name = get_string("Name: ");
	for (int i = 0; i < 2; i++)
	{
		if (strcmp(people[i].name, name) == 0)
		{
			printf("Found %s\n", people[i].number);
			return 0;
		}
	}
	printf("Not found\n");
	return 1;
}
```

- in the code above:
	- `typedef struct` creates a new data type `person`
	- inside a `person` is a string called `name` and a string called `number`
	- *dot notation* such as `people[0].name` is accessing `person` at the 0th location and allows to assign that individual a `name`

## Searching Algorithms

### Linear Search

- algorithm that iterates across the array from left to right, searching for a specified element

```
For each door from left to right
	If 50 is behind door
		Return true
Return false
```

- linear search for an `int`:

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
	// An array of integers
	int numbers[] = {20, 500, 10, 5, 100, 1, 50};
	
	// Search for number
	int n = get_int("Number: ");
	for (int i = 0; i < 7; i++)
	{
		if (numbers[i] == n)
		{
			printf("Found\n");
			return 0;
		}
	}
	printf("Not found\n");
	return 1;
}
```

- linear search for a `string`:

```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	// Arrays of strings
	string names[] = {"Carter", "David"};
	string numbers[] = {"+1-617-495-1000", "+1-949-468-2750"};
	
	// Search for name
	string name = get_string("Name: ");
	for (int i = 0; i < 2; i++)
	{
		if (strcmp(names[i], name) == 0)
		{
			printf("Found %s\n", numbers[i]);
			return 0;
		}
	}
	printf("Not found\n");
	return 1;
}
```

### Binary Search

- algorithm that reduces the search area by half (divide and conquer) each time, trying to find a target number
- searched array must be sorted first

```
If there are no doors
	Return false
If 50 is behind middle door
	Return true
Else if 50 < middle door
	Search left half
Else if 50 > middle door
	Search right half
```

## Sorting Algorithms

- when a list is sorted, searching that list is far less taxing on the computer
- binary search can only be used on a sorted list
- [Comparison Sort](https://www.cs.usfca.edu/~galles/visualization/ComparisonSort.html)

### Selection Sort

- algorithm that finds the smallest unsorted element and adds it to the end of the sorted list

```
// 1st loop
5 2 7 4 1 6 3 0
^

// 2nd loop
0 | 2 7 4 1 6 3 5
    ^ 

// 3rd loop
0 1 | 7 4 2 6 3 5
      ^   

// 4th loop
0 1 2 | 4 7 6 3 5
	    ^

// 5th loop
0 1 2 3 | 7 6 4 5
		  ^

// 6th loop
0 1 2 3 4 | 6 7 5
		    ^
```

### Bubble Sort

- algorithm that moves higher valued elements towards the right and lower value elements towards the left, by comparing two neighbouring values in a "bubble" at a time

```
// 1st loop
5 2 7 4 1 6 3 0
^ ^
2 5 7 4 1 6 3 0
  ^ ^
2 5 7 4 1 6 3 0
	^ ^
2 5 4 7 1 6 3 0
	  ^ ^
2 5 4 1 7 6 3 0
		^ ^
2 5 4 1 6 7 3 0
		  ^ ^
2 5 4 1 6 3 7 0
			^ ^
2 5 4 1 6 3 0 7

// 2nd loop
2 5 4 1 6 3 0 | 7
^ ^
2 5 4 1 6 3 0 | 7
  ^ ^
2 4 5 1 6 3 0 | 7
	^ ^
2 4 1 5 6 3 0 | 7
	  ^ ^
2 4 1 5 6 3 0 | 7
		^ ^
2 4 1 5 3 6 0 | 7
		  ^ ^
2 4 1 5 3 0 6 | 7
```

### Merge Sort

- algorith that sorts smaller arrays and then combines those arrays together (merges them) in sorted order
- merge sort leverages recursion

```
If only one number
	Quit
Else
	Sort left half of number
	Sort right half of number
	Merge sorted halves
```

```
// Sort left half (72)
7 2 | 5 4
	
	// Sort left half (7)
	7 | 2
		
		// Left half sorted, go back
		7
		
	// Sort right half (2)
	7 | 2
		
		// Right half sorted, go back
		2
		
	// Merge sorted halves (7, 2)
	7 | 2
		
		// Halves merged, go back
		2 7
		
// Sort right half (54)
2 7 | 5 4
	
	// Sort left half (5)
	5 | 4
		
		// Left half sorted, go back
		5
		
	// Sort right half (4)
	5 | 4
		
		// Right half sorted, go back
		4
		
	// Merge sorted halves (5, 4)
	5 | 4
		
		// Halves merged, go back
		4 5
		
// Merge sorted halves (27, 45)
2 7 | 4 5
	
	// Halves merged, go back (exit)
	2 4 5 7
```

## Running Time

- running time involves an analysis that shows the efficiency of an algorithm

<img src="images/big-o-graphed.png" width="720px">

- *O* worst case efficiency:
	- O(n2) - Selection Sort, Bubble Sort
	- O(n log n) - Merge Sort
	- O(n) - Linear Search
	- O(log n) - Binary Search
	- O(1)
- *Ω* best case efficiency:
	- Ω(n2) - Selection Sort
	- Ω(n log n) - Merge Sort
	- Ω(n) - Bubble Sort
	- Ω(log n)
	- Ω(1) - Linear Search, Binary Search
- *Θ* efficiency, where the best case and lower case running times are the same

## Recursion

- *recursion* is a concept within programming where a function calls itself
- it has two cases that could apply, given any input:
	- *base case*, which when triggered will terminate the recursive process
	- *recursive case*, which is where the recursion will actually occur

```c
#include <cs50.h>
#include <stdio.h>

void draw(int n);

int main(void)
{
	// Get height of pyramid
	int height = get_int("Height: ");
	
	// Draw pyramid
	draw(height);
}

void draw(int n)
{
	// Base case
	// If nothing to draw
	if (n <= 0)
	{
		return;
	}
	
	// Recursive case
	// Draw pyramid of height n - 1
	draw(n - 1);
	
	// Draw one more row of width n
	for (int i = 0; i < n; i++)
	{
		printf("#");
	}
	printf("\n");
}
```
