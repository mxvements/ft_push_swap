<div align="center">
    <img src="https://img.shields.io/badge/status-wip-success?color=00ABAD&style=flat-square" />
    <img src="https://img.shields.io/badge/started-02%20%2F%2012%20%2F%202023-success?color=00ABAD&style=flat-square" />
    <img src="https://img.shields.io/badge/score-1--%20%2F%20100-success?color=00ABAD&style=flat-square" />
    <img src="https://img.shields.io/github/languages/top/mxvements/ft_push_swap?color=00ABAD&style=flat-square" />
    <img src="https://img.shields.io/github/last-commit/mxvements/ft_push_swap?color=00ABAD&style=flat-square" />
    <br>
    <a href='https://www.linkedin.com/in/luciami' target="_blank"><img alt='Linkedin' src='https://img.shields.io/badge/LinkedIn-100000?style=flat-square&logo=Linkedin&logoColor=white&labelColor=1323233&color=323233'/></a>
    <a href='https://profile.intra.42.fr/users/luciama2' target="_blank"><img alt='42' src='https://img.shields.io/badge/Madrid-100000?style=flat-square&logo=42&logoColor=white&labelColor=323233&color=323233'/></a>
    <br>
</div>

# ft_push_swap

This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed you’ll have to manipulate various types of algorithms and choose the most appropriate solution (out of many) for an optimized data sorting.

| **program name** | push_swap |
| ---------------- | --------- |
| Turn un files    | Makefile, *.h, *.c |
| Makefile         | NAME, all, clean, fclean, re |
| Arguments        | stack **a**: A list of integers |
| External functs. | read, write, malloc, free, exit, ft_printf or equivalent YOU coded |
| Libft auth.      | Yes |
| Desdescription   | Sort stacks |

Your project must comply with the following rules:
+ You have to turn in a Makefile which will compile your source files. It must not
relink.
+ Global variables are forbidden.
+ You have to write a program named push_swap that takes as an argument the stack a formatted as a list of integers. The first argument should be at the top of the stack (be careful about the order).
+ The program must display the smallest list of instructions possible to sort the stack a, the smallest number being at the top.
+ Instructions must be separated by a ’\n’ and nothing else.
+ The goal is to sort the stack with the lowest possible number of operations. During the evaluation process, the number of instructions found by your program will be compared against a limit: the maximum number of operations tolerated. If your
program either displays a longer list or if the numbers aren’t sorted properly, your grade will be 0.
+ If no parameters are specified, the program must not display anything and give the prompt back.
+ In case of error, it must display "Error" followed by a ’\n’ on the standard error. Errors include for example: some arguments aren’t integers, some arguments are bigger than an integer and/or there are duplicates.

During the evaluation process, a binary will be provided in order to properly check your program.

If the program checker_OS displays "KO", it means that your push_swap came up with a list of instructions that doesn’t sort the numbers.

# Mandatory part
You have 2 stacks named a and b.
+ At the beginning:
	+ The stack a contains a random amount of negative and/or positive numbers which cannot be duplicated.
	+ The stack b is empty.
+ The goal is to sort in ascending order numbers into stack a. To do so you have the following operations at your disposal:
	+ **sa** (swap a): Swap the first 2 elements at the top of stack a.
		+ Do nothing if there is only one or no elements.
	+ **sb** (swap b): Swap the first 2 elements at the top of stack b.
		+ Do nothing if there is only one or no elements.
	+ **ss** : sa and sb at the same time.
	+ **pa** (push a): Take the first element at the top of b and put it at the top of a.
		+ Do nothing if b is empty.
	+ **pb** (push b): Take the first element at the top of a and put it at the top of b.
		+ Do nothing if a is empty.
	+ **ra** (rotate a): Shift up all elements of stack a by 1.
		+ The first element becomes the last one.
	+ **rb** (rotate b): Shift up all elements of stack b by 1.
		+ The first element becomes the last one.
	+ **rr** : ra and rb at the same time.
	+ **rra** (reverse rotate a): Shift down all elements of stack a by 1.
		+ The last element becomes the first one.
	+ **rrb** (reverse rotate b): Shift down all elements of stack b by 1.
		+ The last element becomes the first one.
	+ **rrr** : rra and rrb at the same time.

# Bonus part

This project leaves little room for adding extra features due to its simplicity. However, how about creating your own checker?

## The checker program

| **Program use** | checker |
| --------------- | ------- |
| Turn in files   | *.h, *.c |
| Makefile        | bonus |
| Arguments       | stack **a**: A list of integers |
| External functs | read, write, malloc, free, exit, ft_printf and any equivalent YOU coded |
| Libft auth.	  | Yes |
| Description     | Execute the sorting instructions |

+ Write a program named checker that takes as an argument the stack a formatted as a list of integers. The first argument should be at the top of the stack (be careful about the order). If no argument is given, it stops and displays nothing.
+ It will then wait and read instructions on the standard input, each instruction will be followed by ’\n’. Once all the instructions have been read, the program has to execute them on the stack received as an argument.
+ If after executing those instructions, the stack a is actually sorted and the stack b is empty, then the program must display "OK" followed by a ’\n’ on the standard output.
+ In every other case, it must display "KO" followed by a ’\n’ on the standard output.
+ In case of error, you must display "Error" followed by a ’\n’ on the standard error. Errors include for example: some arguments are not integers, some arguments are bigger than an integer, there are duplicates, an instruction doesn’t exist and/or
is incorrectly formatted.

# How to use

*tbd*

# Other

## Norminete
At 42 School, it is expected that almost every project is written in accordance with the Norm, which is the coding standard of the school.

<a href="https://github.com/42School/norminette">
<a>Norminette's repository</a>

```
- No for, do...while, switch, case, goto, ternary operators and variable-length arrays are allowed
- Each function must be a maximum of 25 lines, not counting the function's curly brackets
- Each line must be at most 80 columns wide, comments included
- A function can take 4 named parameters maximum
- No assigns and declarations in the same line (unless static or const)
- You can't declare more than 5 variables per function
- ...
```
## Aknowledgments
+ [Alrgorithms in C](https://theswissbay.ch/pdf/Gentoomen%20Library/Algorithms/Algorithms%20in%20C.pdf)

# License
[MIT License](https://github.com/mxvements/ft_license/blob/main/LICENSE.txt)