ostype=$(shell uname -s)
CFLAGS = -D_POSIX_PTHREAD_SEMANTICS -D_REENTRANT

ifeq (${ostype}, AIX)
	CC=xlC -g -O3 -DAIX $(CFLAGS)
	SHARED_FLAG = -G -brtl
endif

ifeq (${ostype}, Linux)
	CC=gcc -g -O3 $(CFLAGS) -DLINUX -w
	SHARED_FLAG = -fPIC -shared
endif

ifeq (${ostype}, HP-UX)
	CC=aCC +Z -Wl,+s +u4 -ext -mt -w -AA +z -O +W67,829,749 -DHPUX -D_GNUC_STL_ -D_LARGEFILE64_SOURCE -D_THREAD_SAFE $(CFLAGS)
	SHARED_FLAG = -b -Wl,+s
endif

ifeq (${ostype}, SunOS)
	CC=gcc -g -O3 $(CFLAGS) -DSunOS
	SHARED_FLAG = -G
endif

%.o : %.cpp
	$(CC) $(SHARED_FLAG) -c $< $(INC)
%.o : %.c
	$(CC) $(SHARED_FLAG) -c $< $(INC)
%.o : %.cc
	$(CC) $(SHARED_FLAG) -c $< $(INC)

PROJECT = libtesttcl.so

INC += -I./
INC += -I$(TCL_HOME)/include

OBJ = 

MODULE = -L$(TCL_HOME)/lib -ltcl8.5 -lstdc++

all : $(PROJECT)

$(PROJECT) : $(OBJ)
	$(CC) testtcl.cpp ${SHARED_FLAG} -o $(PROJECT) $(INC) $(MODULE) $(OBJ)
	@echo ""
	@echo "+--------------------------------------------+"
	@echo "|            Finish compilation              |"
	@echo "+--------------------------------------------+"
	@echo "|         Thanks using libtesttcl.so         |"
	@echo "|   copyright(c)Wang Yaofu  voipman@qq.com   |"
	@echo "+--------------------------------------------+"

clean:
	rm -rf *.o *.a *.so

