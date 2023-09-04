# Week 0 Scratch

Sources: [Lecture 0](https://cs50.harvard.edu/x/2023/notes/0/)

## Computational Thinking

- input -> black box -> output
- decimal system (base-10)
	- `0 1 2 3 4 5 6 7 8 9`
	- ... + ? x 10^1 + ? x 10^0
- binary system (base-2)
	- `0 1`
	- ... + ? x 2^2 + ? x 2^1 + ? x 2^0
	- `[0 1 0]` = 2; `[1 0 1]` = 5; `[1 1 1]` = 7
	- computers generally use 8 bits to represent a number., e.g. `[0 0 0 0 0 1 0 1]` = 5

## Text

- letters are represented using binary as well
- ASCII standard (8 bits) maps specific letters to specific numbers, e.g. `[72 73 33]` = HI!

<img src="images/ascii.png" width="720px">

## Emojis

- since there were not enough digits in binary to represent all the various characters in english-language-specific ASCII standard (8 bits), world-wide Unicode standard (32 bits) was created

## RGB

- red, green and blue (RGB) is a combination of three numbers of values 0 - 255

## Pseudocode

- pseudocode is a human-readable version of a code
- it is used before creating a formal code, to think through the logic of a problem in advance

```
  1  Pick up phone book
  2  Open to middle of phone book
  3  Look at page
  4  If person is on page
  5      Call person
  6  Else if person is earlier in book
  7      Open to middle of left half of book
  8      Go back to line 3
  9  Else if person is later in book
  10     Open to middle of right half of book
  11     Go back to line 3
  12 Else
  13     Quit
```

## Scratch

- [Scratch](https://scratch.mit.edu) is a visual programming language developed by MIT
