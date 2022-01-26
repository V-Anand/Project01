CC = g++ -std=c++17

all : server

clean:
	@echo Cleaning
	@rm -rf *.o server

server : Server.o Main.o
	$(CC) $? -o $@

.cpp.o:
	$(CC) -c $<

.PHONY : all clean
