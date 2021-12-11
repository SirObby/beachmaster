OBJS	= main.o
SOURCE	= main.c
#HEADER	= foo.h
OUT	= updater
LFLAGS	 = -lpthread
CFLAGS = -O2

all: beach

beach: $(OBJS)
	$(CC) ${CFLAGS} -o $@ $^ $(LFLAGS)

%.o: %.c #$(HEADER)
	$(CC) ${CFLAGS} -c -o $@ $< $(LFLAGS)

clean:
	rm -f $(OBJS) $(OUT)