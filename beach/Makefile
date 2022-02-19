OBJS	= main.o foo.o work.o
SOURCE	= main.c foo.c work.c
OUT	= beach
JSON_C_DIR=../libs/json-c-build
LFLAGS	 = -lpthread -lcurl -lm -L../libs/json-c-build/ -ljson-c -ldialog
CFLAGS = -O2 -I../libs/json-c/ -I../libs/json-c-build/

all: beach

beach: $(OBJS)
	$(CC) ${CFLAGS} -o $@ $^ $(LFLAGS)

%.o: %.c $(HEADER)
	$(CC) ${CFLAGS} -c -o $@ $< $(LFLAGS)

clean:
	rm -f $(OBJS) $(OUT)

# Create a install rule
install:
	cp $(OUT) /usr/local/bin/