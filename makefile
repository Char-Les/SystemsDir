all: dirstat.c
	gcc dirstat.c -o dirstat.exe

run: all
	./dirstat.exe

clean:
	rm foo
	rm *.out
	rm *~
