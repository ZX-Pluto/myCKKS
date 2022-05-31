OBJS = nwc_NTT_copy.o my_hexl.o
main: $(OBJS)
		g++ -o my_cfntt $(OBJS)
nwc_NTT_copy.o: nwc_NTT_copy.cpp my_hexl.h
		g++ -c nwc_NTT_copy.cpp
my_hexl.o: my_hexl.cpp my_hexl.h
		g++ -c my_hexl.cpp
clean:
		rm my_cfntt $(OBJS)