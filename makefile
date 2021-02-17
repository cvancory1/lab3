# makefile
# make clean

program: lab3.o
	g++ -g -std=c++11 lab3.o -o main
	
	

lab3.o: lab3.cpp
	g++ -g -std=c++11 -c lab3.cpp

clean:
	rm -f *.o
	rm -f main

commit:
	git add *
	git commit * -m pushing
	git push origin main
	
pull:
	git pull
	make
	./main


