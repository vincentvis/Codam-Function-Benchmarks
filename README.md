# Benchmarking some semi-stupid string length functions

We are restricted by "The Norm" at all 42 schools for code written in C.
Which limits us, among other things, in number of lines per function block and line length.

Even though the "need-for-speed" is not really a thing in our early Codam projects, I wanted to dive some deeper in how to create a faster function to determine the length of a string.

The glibc version does something with magic numbers and bitmasking/shifting. Which I kinda understand, but not fully. Especially not how to got to those numbers exactly. And since another requirement at Codam is that you have to be able to explain each line of code, I did not feel comfortable implementing that method.
So these are my experiments with other ways of making a faster string length function in C, within the bounds of the Norm. I also included a few assembly versions, since in later projects I wrote some x86 assembly.
