all: main story encryption users
	gcc main.o story.o encryption.o users.o -o out
	del *.o
	./out

main: main.c
	gcc -c main.c -o main.o

story: story.c
	gcc -c story.c -o story.o

encryption: encryption.c
	gcc -c encryption.c -o encryption.o

users: users.c
	gcc -c users.c -o users.o