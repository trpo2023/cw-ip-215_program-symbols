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

.PHONY: clean
clean:
	rm bin/main
	rm obj/src/course/*.o
	rm obj/src/course/*.d
	rm obj/src/lib/*.d
	rm obj/src/lib/*.o
	rm obj/src/lib/*.a

