==== Compile =====
$> make clean; make

==== Run tests and make diff =====
To run a specific test and diff with std (professor) output,
execute
$> make r<T><X>

where <T> is the type of test as following:
  - l: stands for list
  - q: stands for queue
  - t: stands for tree
and X is the number of the test

For example:
1. $>make rl1 executes the first list test
2. $>make rq2 executes the second queue test
3. $>make rt4 executes the fourth tree test

All the above options write STDOUT to a file suffixed
.out and diff the .out file against the .std (professor) 
output.

==== Only for binary trees =====

Replace 'autolab' option with 'dot' in Makefile if you want 
to draw the binary tree in png image format. Default option 
is autolab (write everything to STDOUT, in a format suitable
for autolab).

i.e. 
$> ./tree_test t1 students-27.txt students-5.txt autolab

replace 'autolab' with 'dot' as following

$> ./tree_test t1 students-27.txt students-5.txt dot
