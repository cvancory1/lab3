# makefile

program: lab3.o
	g++ -g -std=c++11 lab3.o -o main

lab3.o: lab3.cpp
	g++ -g -std=c++11 -c lab3.cpp

clean:
	rm -f *.o

commit:
	git add *
	git commit * -m pushing
	git push origin main