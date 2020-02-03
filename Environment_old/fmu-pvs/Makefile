CC=gcc
CFLAGS=-I.

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)
all:
	gcc -fPIC -Wall -c fmu.c
	gcc -fPIC -Wall -c skeleton.c
	gcc -fPIC -Wall -c misraC/Environment_old.c
	unzip -o resources/libWS.zip
	gcc -fPIC -shared -o Environment_old.so skeleton.o fmu.o Environment_old.o -Wl,-rpath,. -L. -lwebsockets -lm
	
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
	mv Environment_old.so binaries/linux64/
	cp libWS/libwebsockets.* binaries/linux64/
	cp libWS/libcrypto.so.* binaries/linux64/
	cp libWS/libssl.so.* binaries/linux64/
	zip -r Environment_old.fmu modelDescription.xml binaries/ resources/ sources/
	rm -rf sources
	rm -rf binaries
	rm -rf libWS/
	rm -rf  Environment_old.o fmu.o skeleton.o
run:
	unzip -o resources/libWS.zip
	mv libWS/fmuCheck.linux64 ../fmu-pvs/
	./fmuCheck.linux64 -h 1E-01 Environment_old.fmu
	rm -rf libWS/
run1:
	unzip -o resources/libWS.zip
	mv libWS/fmuCheck.linux64 ../fmu-pvs/
	./fmuCheck.linux64 -h 1E-02 Environment_old.fmu
	rm -rf libWS/
