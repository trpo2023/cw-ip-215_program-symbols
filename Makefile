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
	rm test/*.d
	rm test/*.o
	rm test/test

.PHONY: test
test: test/test

test/test: test/test_help_func.o test/main.o
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ $^
	@echo ---------------------------; cd test/ && ./test

test/test_help_func.o: test/test_help_func.c thirdparty/ctest.h
	$(CC) -c $(CFLAGS) $< $(CPPFLAGS) -o $@ -I thirdparty -I src/lib

test/main.o: test/main.c test/test_help_func.o thirdparty/ctest.h
	$(CC) -c $(CFLAGS) $< $(CPPFLAGS) -o $@ -I thirdparty -I src/lib


