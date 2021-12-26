<<<<<<< HEAD
OBJS	= main.o foo.o csv.o
SOURCE	= main.c foo.c csv.c
HEADER	= foo.h
OUT	= beach
LFLAGS	 = -lpthread -lcurl -lm
=======
OBJS	= main.o foo.o
SOURCE	= main.c foo.c
HEADER	= foo.h
OUT	= beach
LFLAGS	 = -lpthread
>>>>>>> 85433a94da06581740b388c2f416ce1383dea164
CFLAGS = -O2

all: beach

beach: $(OBJS)
	$(CC) ${CFLAGS} -o $@ $^ $(LFLAGS)

%.o: %.c $(HEADER)
	$(CC) ${CFLAGS} -c -o $@ $< $(LFLAGS)

clean:
	rm -f $(OBJS) $(OUT)