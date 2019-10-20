
DLIST_TEST_FILES=dlist_t1.h dlist_t2.h dlist_t3.h dlist_t4.h dlist_t5.h dlist_test.c

DEQUEUE_TEST_FILES=dequeue_t1.h dequeue_t2.h dequeue_test.c

TREE_TEST_FILES=tree_t1.h tree_t2.h tree_t3.h tree_test.c

all: dlist_test dequeue_test tree_test

type_t.o: type_t.c type_t.h
	gcc -Wall -g type_t.c -c

dlist_test: $(DLIST_TEST_FILES) type_t.o dlist.o dlist_test.c
	gcc -Wall -g dlist.o type_t.o dlist_test.c -o dlist_test

dequeue_test: $(DLIST_TEST_FILES) type_t.o dequeue.o dlist.o dequeue_test.c
	gcc -Wall -g dequeue.o dlist.o type_t.o dequeue_test.c -o dequeue_test

tree_test: $(TREE_TEST_FILES) tree.o common.o type_t.o tree_test.c
	gcc -Wall -g type_t.o common.o tree.o tree_test.c -o tree_test

tree.o: tree.h tree.c
	gcc -Wall -g tree.c -c

dlist.o: dlist.h dlist.c
	gcc -Wall -g dlist.c -c
	
dequeue.o: dequeue.h dequeue.c
	gcc -Wall -g dequeue.c -c

common.o: common.c common.h
	gcc -Wall -g common.c -c

clean:
	-rm *.o dlist_test dequeue_test tree_test *.out
	-rm -rf dot/
	mkdir dot

run: rl1 rl2 rl3 rl4 rl5 rq1 rq2 rq3 rt1 rt2 rt3

rl1:
	./dlist_test t1 students-27.txt students-27.txt > dlist_t1.out
	diff dlist_t1.std dlist_t1.out
rl2:
	./dlist_test t2 students-27.txt students-27.txt > dlist_t2.out
	diff dlist_t2.std dlist_t2.out
rl3:
	./dlist_test t3 students-27.txt students-27.txt > dlist_t3.out
	diff dlist_t3.std dlist_t3.out
rl4:
	./dlist_test t4 students-27.txt students-27.txt > dlist_t4.out
	diff dlist_t4.std dlist_t4.out
rl5:
	./dlist_test t5 students-27.txt students-27.txt > dlist_t5.out
	diff dlist_t5.std dlist_t5.out

rq1:
	./dequeue_test t1 students-10.txt > dequeue_t1.out
	diff dequeue_t1.std dequeue_t1.out
rq2:
	./dequeue_test t2 students-10.txt > dequeue_t2.out
	diff dequeue_t2.std dequeue_t2.out

# Replace 'autolab' parameter with 'dot' if you want to print output in dot format.
rt1:
	./tree_test t1 students-27.txt students-5.txt autolab > tree_t1.out
	diff tree_t1.std tree_t1.out
# Replace 'autolab' parameter with 'dot' if you want to print output in dot format.
rt2:
	./tree_test t2 students-27.txt students-5.txt autolab > tree_t2.out
	diff tree_t2.std tree_t2.out
# Replace 'autolab' parameter with 'dot' if you want to print output in dot format.
rt3:
	./tree_test t3 students-27.txt students-5.txt autolab > tree_t3.out
	diff tree_t3.std tree_t3.out
# Replace 'autolab' parameter with 'dot' if you want to print output in dot format.
rt4:
	./tree_test t4 students-27.txt students-5.txt autolab > tree_t4.out
	diff tree_t4.std tree_t4.out

std:
	./dlist_test t1 students-27.txt students-27.txt > dlist_t1.std
	./dlist_test t2 students-27.txt students-27.txt > dlist_t2.std
	./dlist_test t3 students-27.txt students-27.txt > dlist_t3.std
	./dlist_test t4 students-27.txt students-27.txt > dlist_t4.std
	./dlist_test t5 students-27.txt students-27.txt > dlist_t5.std
	./tree_test t1 students-27.txt students-5.txt autolab > tree_t1.std
	./tree_test t2 students-27.txt students-5.txt autolab > tree_t2.std
	./tree_test t3 students-27.txt students-5.txt autolab > tree_t3.std
	./tree_test t4 students-27.txt students-5.txt autolab > tree_t4.std
	./dequeue_test t1 students-10.txt > dequeue_t1.std
	./dequeue_test t2 students-10.txt > dequeue_t2.std
