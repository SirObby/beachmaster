OBJS	= main.o
SOURCE	= main.c
#HEADER	= foo.h
OUT	= updater
LFLAGS	 = -lpthread
CFLAGS = -O2

all: updater

<<<<<<< HEAD
updater: $(OBJS)
=======
beach: $(OBJS)
>>>>>>> 85433a94da06581740b388c2f416ce1383dea164
	$(CC) ${CFLAGS} -o $@ $^ $(LFLAGS)

%.o: %.c #$(HEADER)
	$(CC) ${CFLAGS} -c -o $@ $< $(LFLAGS)

clean:
	rm -f $(OBJS) $(OUT)