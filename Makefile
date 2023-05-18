CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -MMD
CC = gcc

bin/main: obj/src/course/course.o obj/src/lib/lib.a
	$(CC) $(CFLAGS) -o $@ $^

obj/src/lib/lib.a: obj/src/lib/help_func.o
	ar rcs $@ $^

obj/src/course/course.o: src/course/course.c
	$(CC) -c $(CFLAGS) $< $(CPPFLAGS) -o $@ -I src/lib

obj/src/lib/help_func.o: src/lib/help_func.c src/lib/help_func.h
	$(CC) -c $(CFLAGS) $< $(CPPFLAGS) -o $@ -I src/lib

