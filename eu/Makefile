
#CC=g++
CC=gcc
RM=rm
#CFLAGS = -g -Wall -O2
CFLAGS = -g 
MYLIB=libmylib
MYLIBRARY=mylib
MYLIB_DIR=lib
OUTPUT=out
MKDIR=mkdir
MAKE=make
SRC=src



all : $(TARGET)

$(TARGET) : $(MYLIB)
	$(RM) -vrf $(TARGET) $(TARGET).o
	if [ ! -d $(OUTPUT) ]; then \
		$(MKDIR) $(OUTPUT); \
	fi
	$(CC) $(CFLAGS) -o $(OUTPUT)/$(TARGET) $(SRC)/$(TARGET).c -ldl

$(MYLIB): 
	$(RM) -vrf $(MYLIB_DIR)/$(MYLIB).so*.
	$(CC) $(CFLAGS) -fPIC -Wall -c $(MYLIB_DIR)/libmylib.c -o $(MYLIB_DIR)/libmylib.o
	$(CC) $(CFLAGS) -shared -Wl,-soname,$(MYLIB_DIR)/libmylib.so.0 -o $(MYLIB_DIR)/libmylib.so.0.0 $(MYLIB_DIR)/libmylib.o -lc
	/sbin/ldconfig -n .
	ln -sf libmylib.so.0.0 $(MYLIB_DIR)/libmylib.so

clean :
	$(MAKE) -C $(MYLIB_DIR) clean
	rm -rf *.o $(OUTPUT)

