all:
	g++ main.cpp -I ../../include -O3 -std=c++17 -o pgen

clean:
	rm -f ./pgen

install:
	@if command -v pgen; then \
		exit 1; \
	else \
		cp pgen /usr/bin/pgen; \
	fi;
