#!/bin/bash


TESTCASE=(helloworld helloworld2 helloworld3 quine sieve)

for i in ${TESTCASE[*]}
do
	timeout 1 ./befunge tests/testcases/$i.bf | diff tests/output/$i.out -
done
