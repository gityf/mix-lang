JAVA_HOME=/home/dev/tools/jdk1.8.0_144
INC = -I${JAVA_HOME}/include
INC += -I${JAVA_HOME}/include/linux

all:
	g++ -o libHelloJni.so       -shared -fPIC -g HelloJni.cpp  $(INC)
	javac HelloJni.java
clean:
	rm -rf *.so *.class *.o
