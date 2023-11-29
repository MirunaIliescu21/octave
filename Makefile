CC=gcc
CFLAGS=-Wall -Wextra -std=c99
SRC=my_octave.c Validate.c Collection.c Matrix.c Radix.c PowerMatrix.c strassenMultiply.c MultiplicateMatrix.c
EXE=my_octave

build: $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(EXE)

pack:
	zip -FSr 3XYCA_FirstnameLastname_Tema2.zip README Makefile *.c *.h

clean:
	rm -f $(EXE)

.PHONY: pack clean
