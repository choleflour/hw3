CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

# all: llrec-test

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------
# llrec-test: llrec-test.o llrec.o
# 	$(CXX) $(CXXFLAGS) -o $@ $^
# llrec-test.o: llrec-test.cpp llrec.h
# 	$(CXX) $(CXXFLAGS) -o $@ -c llrec-test.cpp
# llrec.o: llrec.cpp llrec.h
# 	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c llrec.cpp

all: heap-test
heap-test: heap-test.o 
	$(CXX) $(CXXFLAGS) -o $@ $^
heap-test.o: heap-test.cpp heap.h
	$(CXX) $(CXXFLAGS) -o $@ -c heap-test.cpp


clean:
	rm -f *.o rh heap-test *~

.PHONY: clean 