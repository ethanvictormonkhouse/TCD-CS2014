TEST_STACK_CASES=1 2
TEST_POSTFIX_CASES=1 2 3 4 5 6 7 8
TEST_INFIX_CASES=1 2 3 4 5 6
pass=PASSED
fail=FAILED

all: build-prep test_stack run_all_stack_tests test_postfix run_all_postfix_tests test_infix run_all_infix_tests

test_stack: test_files/test_sources/test_stack.c stack.c stack.h
	echo "Compiling stack tests"
	echo "gcc -Wall -g -o test_files/build/test_stack test_files/test_sources/test_stack.c stack.c -I."
	gcc -Wall -g -o test_files/build/test_stack test_files/test_sources/test_stack.c stack.c -I. \
	&& a="PASSED" || a="FAILED";\
	echo "Compilation Stack "$$a;
#	bash -c "if [[ $$a == PASSED ]]; then echo Test 1.1 1 >> test_files/result/results.txt; else echo Test 1.1 0 >> test_files/result/results.txt; fi"

test_postfix: test_files/test_sources/test_postfix.c postfix.c stack.c postfix.h stack.h
	echo "Compiling postfix tests"
	echo "gcc -Wall -g -o test_files/build/test_postfix test_files/test_sources/test_postfix.c postfix.c stack.c -I. -lm"
	gcc -Wall -g -o test_files/build/test_postfix test_files/test_sources/test_postfix.c postfix.c stack.c -I. -lm \
	&& a="PASSED" || a="FAILED";\
	echo "Compilation Postfix "$$a;
#	bash -c "if [[ $$a == PASSED ]]; then echo Test 3.1 1 >> test_files/result/results.txt; else echo Test 3.1 0 >> test_files/result/results.txt; fi"

test_infix: test_files/test_sources/test_infix.c infix.c postfix.c stack.c infix.h postfix.h stack.h
	echo "Compiling infix tests"
	echo "gcc -Wall -g -o test_files/build/test_infix test_files/test_sources/test_infix.c infix.c postfix.c stack.c -I. -lm"
	gcc -Wall -g -o test_files/build/test_infix test_files/test_sources/test_infix.c infix.c postfix.c stack.c -I. -lm \
	&& a="PASSED" || a="FAILED";\
	echo "Compilation infix "$$a;\
	bash -c "if [[ $$a == PASSED ]]; then echo Test 4.1 4 >> test_files/result/results.txt; else echo Test 4.1 0 >> test_files/result/results.txt; fi"

run_all_stack_tests : $(foreach test,$(TEST_STACK_CASES),run_test_stack$(test))

run_all_postfix_tests : $(foreach test,$(TEST_POSTFIX_CASES),run_test_postfix$(test))

run_all_infix_tests : $(foreach test,$(TEST_INFIX_CASES),run_test_infix$(test))

run_test_stack%:
	echo
	echo -n "Run stack test $* "
	bash -c "./test_files/build/test_stack `cat test_files/test_inputs/test_stack_$*.txt`" && a="PASSED" || a="FAILED" ;\
	echo $$a;\
	bash -c "if [[ $$a == PASSED ]]; then echo Test 2.$* 1 >> test_files/result/results.txt; else echo Test 2.$* 0 >> test_files/result/results.txt; fi"

run_test_postfix%:
	echo 
	echo -n "Run postfix test $* "
	./test_files/build/test_postfix postfix `cat test_files/test_inputs/test_postfix_$*.txt` | tail -n 1 > test_files/build/test_postfix_output_$*.txt \
  && a="PASSED" || a="FAILED"; \
  bash -c "if diff -eq test_files/test_outputs/test_postfix_$*.txt test_files/build/test_postfix_output_$*.txt; \
  then if [[ $$a == PASSED ]]; then echo PASSED; echo Test 3.$* 1 >> test_files/result/results.txt; else echo PARTIAL; echo Test 3.$* 0.5 >> test_files/result/results.txt; fi; \
  else echo FAILED; echo Test 3.$* 0 >> test_files/result/results.txt; fi"

run_test_infix%:
	echo 
	echo -n "Run infix test $* "
	./test_files/build/test_infix infix `cat test_files/test_inputs/test_infix_$*.txt` | tail -n 1 > test_files/build/test_infix_output_$*.txt \
  && a="PASSED" || a="FAILED"; \
  bash -c "if diff -eq test_files/test_outputs/test_infix_$*.txt test_files/build/test_infix_output_$*.txt; \
  then if [[ $$a == PASSED ]]; then echo PASSED; echo Test 4.$* 1 >> test_files/result/results.txt; else echo PARTIAL; echo Test 4.$* 0.5 >> test_files/result/results.txt; fi; \
  else echo FAILED; echo Test 4.$* 0 >> test_files/result/results.txt; fi"

build-prep: clean
	mkdir -p test_files/build
	mkdir -p test_files/result
	touch test_files/result/results.txt

clean:
	rm -rf test_files/build
	rm -rf test_files/result

submission_archive:
	tar -cvf lab4_submission.tar *.h *.c

.SILENT: 

