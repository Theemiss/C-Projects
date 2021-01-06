# C-Projects

## SUM
program that use fork and pipe to sum input

 * Child Process - get input from user transfert to the parent using (pipe)

 * Parent process - Sum the number from the Child and printed every time

### Example:

```
> ./sum
> 10
10
>5
15
>x
```

## FACT
program that use thrads and mutex to fact with given input and given number of threads

* every thread calculate a part from the factoriel
### Example:
```
>./fact 5 2
5 != 120
```
calculate the fact of five with 2 thread 
the first thread will do [1,2] the second thread will do [3,5] and join them togther print the result
## FileReader
Program that open a file with parent process and read it send the data to a child process that created using 

(fork and pipe)

### counter 
Program that add (n) to a global varibale intialized as 0 using x threads every thread add (n) to the global 

varibale (using mutex and pthreads)

```
>./count 5 2
0
4
8
Last count is 10
```
n is 2 and x is 5

compiled using gcc count.c -lpthread -o count