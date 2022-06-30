OBJECTS = main_test.o print.o input.o
SRCS = main_test.c print.c input.c
CFLAGS = -g
TARGET = test

$(TARGET) : $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS)

clean :
	rm -f $(OBJECTS) $(TARGET) core


#
#test: $(OBJECTS)
#	gcc -o test $(OBJECTS)
#

main_test.o : main_test.c common.h
	gcc -c main_test.c

print.o : print.c common.h
	gcc -c print.c

input.o : input.c common.h
	gcc -c input.c

