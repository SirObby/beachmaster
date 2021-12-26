OBJS	= main.o foo.o csv.o
SOURCE	= main.c foo.c csv.c
HEADER	= foo.h
OUT	= beach
LFLAGS	 = -lpthread -lcurl -lm
CFLAGS = -O2

all: beach

beach: $(OBJS)
	$(CC) ${CFLAGS} -o $@ $^ $(LFLAGS)

%.o: %.c $(HEADER)
	$(CC) ${CFLAGS} -c -o $@ $< $(LFLAGS)

clean:
	rm -f $(OBJS) $(OUT)