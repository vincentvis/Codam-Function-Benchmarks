# Benchmarking some semi-stupid function optimizations

We are restricted by "The Norm" at all 42 schools for code written in C.
Which limits us, among other things, in number of lines per function block and line length.

Even though the "need-for-speed" is not really a thing in our early Codam projects, I wanted to dive deeper in how to make some functions faster.

## Strlen - count the length of a string

The glibc version does something with magic numbers and bitmasking/shifting. Which I kinda understand, but not fully. Especially not how to got to those numbers exactly. And since another requirement at Codam is that you have to be able to explain each line of code, I did not feel comfortable implementing that method.
So these are my experiments with other ways of making a faster string length function in C, within the bounds of the Norm. I also included a few assembly versions, since in later projects I wrote some x86 assembly.

## nbrlen - count the amount of digits in a number

The easy and naive approach that I saw everywhere is a while loop and divide by the base (usually 10). The simple optimization comes from removing the loop and just keeping the comparision done in the loop. So basically a whole bunch of if statements. Turns out to be quite a bit faster.

## number to string - convert a number to it's ASCII representation

The usual approach is to get the modulus of the base (usually 10) and take that from a table of characters. 
So `423 % 10 = 3`, `"0123456789"[3] -> '3'`.
This can be optimized by having a character bigger table and a larger modulo value (modulo 100 instead of 10) to process more characters per iteration.

## string to number - convert a ASCII representation of a string to a number

If you take the last character of a string `"325"[0] -> '5'` you can easily convert from ascii value to actual numeric value.
If you manipulate the type of pointer, you can also get either a `short` (2 bytes) or an `int` (4 bytes) and use a lookup table to determine the value. For the 4 byte version this adds a lookup table of 40KB, which on modern computers isn't a big deal. 
