OBJS	= main.o foo.o sys/depmap.o sys/install.o
SOURCE	= main.c foo.c sys/depmap.c sys/install.c
HEADER	= foo.h sys/depmap.h
OUT	= beach
JSON_C_DIR=../libs/json-c-build
LFLAGS	 = -lpthread -lcurl -lm -L../libs/json-c-build/ -ljson-c
CFLAGS = -O2 -I../libs/json-c/ -I../libs/json-c-build/

all: beach

beach: $(OBJS)
	$(CC) ${CFLAGS} -o $@ $^ $(LFLAGS)

%.o: %.c $(HEADER)
	$(CC) ${CFLAGS} -c -o $@ $< $(LFLAGS)

clean:
	rm -f $(OBJS) $(OUT)