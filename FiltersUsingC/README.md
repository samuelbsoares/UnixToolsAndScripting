<b>Tasks</b>

Use the existing main.c as the driver for your filters.

<b>Makefile</b>

Your makefile should:

build all of the filters as its default target
have a clean target that removes all build files and created executables
have the correct dependencies listed such that things are rebuilt when necessary, and only when necessary

<b>blanks</b>

executable	source	function	argument
blanks	blanks.c	adjusts vertical spacing in files

1: number of newlines

argument	input   	output
0	        hi\nbye\n	hibye
1	        hi\nbye\n	hi\nbye\n
2	        hi\nbye\n	hi\n\nbye\n\n
2	        yo!\n\n	        yo!\n\n\n\n

<b>tr</b>

executable	source	function	argument
tr	tr.c	transliterate character	

1: the character to be replaced
2: the character to replace it

argument	input	 	output
l i	        Hello World 	Heiio Worid
H h	        Hello World 	hello World
W x	        Hellow World	Hellow xorld

<b>head</b>

executable	source	function	argument
head	head.c	prints only the first n lines

1: number of lines

argument	input		 output
0	        hi\nbye\n	 	
1	        hi\nbye\n	 hi\n
2	        hi\nbye\n	 hi\nbye\n
3	        hi\nbye\n	 hi\nbye\n
count how many lines you've printed
if not done, print and increment
if done, alter num to indicate that there is nothing to print

<b>rev</b>

executable	source	function	argument
rev	        rev.c	reverses a line	

argument	input	 	output
                hi\nbye\n	ih\neyb\n
                Forward	 	drawroF
                tacocat	 	tacocat

make a swap function

<b>double</b>

executable	source	        function	argument
double	        double.c	repeats each character on a line	
argument	input	 	output
                hi\nbye\n	hhii\nbbyyee\n
                Forward	 	FFoorrwwaarrdd
                tacocat	 	ttaaccooccaatt

<b>tail</b>

executable	source	function	argument
tail	        tail.c	prints only the last n lines	1: number of lines
argument	input	 	output
0	        hi\nbye\n	 	
1	        hi\nbye\n	bye\n
2	        hi\nbye\n	hi\nbye\n
3	        hi\nbye\n	hi\nbye\n
