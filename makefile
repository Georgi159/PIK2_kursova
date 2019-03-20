jpeg_parser.out : jpeg_parser.c
	gcc jpeg_parser.c -o jpeg_parser.out -std=c11 -Wall -pedantic -Wextra

clear : 
	rm jpeg_parser.out