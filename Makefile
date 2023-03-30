all:
	g++ -std=c++11 -Wall -Wextra -Werror -pedantic -O3 -c hashmap.cpp
	g++ -std=c++11 -Wall -Wextra -Werror -pedantic -O3 -c test1.cpp
	g++ -std=c++11 -Wall -Wextra -Werror -pedantic -O3 -c test2.cpp
	g++ -std=c++11 -Wall -Wextra -Werror -pedantic -O3 -c test3.cpp
	g++ -o test1 hashmap.o test1.o
	g++ -o test2 hashmap.o test2.o
	g++ -o test3 hashmap.o test3.o
	
clean:
	rm -rf *.o test1 test2 test3
