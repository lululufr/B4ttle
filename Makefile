CC= gcc        # compilateur
CFLAGS= -Wall  # options de compilation pour les sources C


sources= blob.c tga.c tri_blob.c
objets= $(sources:.c=.o)


    $(CC) -o $@ $^ -lcurses
