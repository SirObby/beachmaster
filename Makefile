all: beach updater

beach:
	${MAKE} --no-print-directory -C ./beach/ clean
	${MAKE} --no-print-directory -C ./beach
.PHONY	: beach

updater:
	${MAKE} --no-print-directory -C ./updater/ clean
	${MAKE} --no-print-directory -C ./updater
.PHONY	: updater