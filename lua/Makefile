
LUAJIT_INC = /usr/local/openresty/luajit/include/luajit-2.1
LUAJIT_LIB = /usr/local/openresty/luajit/lib
all:
	gcc -o libluatest.so -shared -fPIC -g luatest.c -I$(LUAJIT_INC)
clean:
	rm -rf *.so *.o
