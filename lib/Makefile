
#CC=g++
CC=gcc
RM=rm
CFLAGS = -g -Wall -O2
CFLAGS = -g 
MYLIB=libmylib
MYLIBRARY=mylib
MYLIB_DIR=lib



all : $(MYLIB)

$(TARGET) : $(MYLIB)

$(MYLIB): 
	$(RM) -vrf *.so*.
#$(CC) $(CFLAGS) -fPIC -c $(MYLIB_DIR)/libmylib.c -o $(MYLIB_DIR)/libmylib.o
	$(CC) $(CFLAGS) -fPIC -c libmylib.c
	$(CC) $(CFLAGS) -shared -Wl,-soname,libmylib.so.0 -o libmylib.so.0.0 libmylib.o -lc

#$(CC) $(CFLAGS) -shared -Wl,-soname,$(MYLIB_DIR)/libmylib.so.0 -o $(MYLIB_DIR)/libmylib.so.0.0 $(MYLIB_DIR)/libmylib.o -lc
#	$(CC) $(CFLAGS) -shared -Wl,-soname,libmylib.so.0 -o libmylib.so.0.0 $(MYLIB_DIR)/libmylib.o -lc
	/sbin/ldconfig -n .
#cd $(MYLIB_DIR);ln -sf libmylib.so.0 libmylib.so 
#ln -sf $(MYLIB_DIR)/libmylib.so.0 libmylib.so
	ln -sf libmylib.so.0 libmylib.so

clean :
	rm -rvf *.o *.so*

