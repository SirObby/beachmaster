<<<<<<< HEAD
OBJS = ${wildcard *.o} \
		${wildcard beach/*.o} \
		${wildcard updater/*.o}

all: beach updater

clean:
	rm -f ${OBJS} ./beach/beach ./updater/updater

=======
all: beach updater

>>>>>>> 85433a94da06581740b388c2f416ce1383dea164
beach:
	${MAKE} --no-print-directory -C ./beach/ clean
	${MAKE} --no-print-directory -C ./beach
.PHONY	: beach

updater:
	${MAKE} --no-print-directory -C ./updater/ clean
	${MAKE} --no-print-directory -C ./updater
.PHONY	: updater