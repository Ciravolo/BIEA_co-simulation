CC=gcc
CFLAGS=-I.

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)
all:
	gcc -fPIC -Wall -c fmu.c
	gcc -fPIC -Wall -c skeleton.c
	gcc -fPIC -Wall -c misraC/ShowOutput.c
	unzip -o resources/lib.zip
	gcc -shared -o ShowOutput.so skeleton.o fmu.o ShowOutput.o 
	rm -rf sources
	rm -rf binaries
	mkdir sources
	mkdir  binaries
	mkdir binaries/linux64
	cp fmu.h sources
	cp FmuGUID.h sources
	cp fmu.c sources
	cp skeleton.c sources
	rm -f misraC/main.c
	cp -r misraC sources
	cp -r fmi sources
	mv ShowOutput.so binaries/linux64/
	
	zip -r ShowOutput.fmu modelDescription.xml binaries/ resources/ sources/
	rm -rf sources
	rm -rf binaries
	

run:
	
	./fmuCheck.linux64 -h 1E-01 ShowOutput.fmu
	
run1:
	
	./fmuCheck.linux64 -h 1E-02 ShowOutput.fmu
	

clean:
	rm -rf  ShowOutput.o fmu.o skeleton.o
