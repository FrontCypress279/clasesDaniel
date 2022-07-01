TARGET = main
FLAGS = -std=c99 -Wall -pedantic
HEADERS = #src/lib.h

$(TARGET).out: src/$(TARGET).c $(HEADERS)
	clang src/$(TARGET).c $(HEADERS) $(FLAGS) -o target/$(TARGET).out

run: $(TARGET).out
	./target/$(TARGET).out

clear: 
	rm -f target/*.out
