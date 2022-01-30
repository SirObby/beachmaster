OBJS = ${wildcard *.o} \
		${wildcard beach/*.o} \
		${wildcard updater/*.o}

all: beach updater

clean:
	rm -f ${OBJS} ./beach/beach ./updater/updater

beach:
	${MAKE} --no-print-directory -C ./beach/ clean
	${MAKE} --no-print-directory -C ./beach
	${MAKE} --no-print-directory -C ./beach/ install
.PHONY	: beach

updater:
	${MAKE} --no-print-directory -C ./updater/ clean
	${MAKE} --no-print-directory -C ./updater
	${MAKE} --no-print-directory -C ./updater/ install
.PHONY	: updater