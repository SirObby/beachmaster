OBJS = ${wildcard *.o} \
		${wildcard beach/*.o} \
		${wildcard installer/*.o}

all: beach installer livecd

clean:
	rm -f ${OBJS} ./beach/beach ./installer/installer

beach:
	${MAKE} --no-print-directory -C ./beach/ clean
	${MAKE} --no-print-directory -C ./beach
.PHONY	: beach

installer:
	${MAKE} --no-print-directory -C ./installer/ clean
	${MAKE} --no-print-directory -C ./upinstallerdater
.PHONY	: updater

livecd:
	${MAKE} --no-print-directory -C ./livecd/ clean
	${MAKE} --no-print-directory -C ./livecd
.PHONY : livecd

install:
	${MAKE} --no-print-directory -C ./beach/ install
	${MAKE} --no-print-directory -C ./installer/ install
.PHONY	: install