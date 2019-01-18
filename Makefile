# Brett Henry 01017222
# # CS 262, 202
# # Project 1
CFLAGS = -g -Wall -lm

all:	OTPEncryptor.c
	gcc ${CFLAGS} -o OTPEncryptor OTPEncryptor.c
clean:
		rm OTPEncryptor

