# main: main.cpp
# 	g++ -std=c++11 main.cpp -g -o ____ -Wformat=0 -Wpointer-arith
FLAGS = -std=c++11 -fpermissive
default: program

main.o: VMGlobals.hpp  ViewerFiles§Exibidor.hpp  \
ClassFileStructures§ClassFile.hpp  ReaderFiles§ClassLoader.hpp 
	g++ $(FLAGS) -fpermissive -c main.cpp

VMGlobals.o: UsingUs.hpp ClassFileStructures§ClassFile.hpp ClassFileStructures§ClassFile.cpp
	g++ $(FLAGS) -fpermissive -c VMGlobals.cpp


ViewerFiles§Exibidor.o: UsingUs.hpp VMGlobals.hpp ClassFileStructures§ClassFile.hpp \
ClassFileStructures§cp_info.hpp ClassFileStructures§attribute_info.hpp
	g++ $(FLAGS) -fpermissive -c ViewerFiles§Exibidor.cpp

# ClassFileStructures§
ClassFileStructures§attribute_info.o: UsingUs.hpp ReaderFiles§read_us.hpp ClassFileStructures§attribute_info.hpp 
	g++ $(FLAGS) -fpermissive -c ClassFileStructures§attribute_info.cpp

ClassFileStructures§ClassFile.o: ClassFileStructures§field_info.hpp ClassFileStructures§attribute_info.hpp \
ClassFileStructures§method_info.hpp ClassFileStructures§cp_info.hpp 
	g++ $(FLAGS) -fpermissive -c ClassFileStructures§ClassFile.cpp


ClassFileStructures§cp_info.o: UsingUs.hpp ReaderFiles§read_us.hpp
	g++ $(FLAGS) -fpermissive -c  ClassFileStructures§cp_info.cpp

ClassFileStructures§field_info.o: 
	g++ $(FLAGS) -fpermissive -c ClassFileStructures§field_info.cpp

ReaderFiles§ClassLoader.o: ClassFileStructures§ClassFile.hpp ReaderFiles§read_us.hpp \
VMGlobals.hpp ReaderFiles§ClassLoader.hpp
	g++ $(FLAGS) -fpermissive -c ReaderFiles§ClassLoader.cpp

ReaderFiles§read_us.o: ReaderFiles§read_us.hpp
	g++ $(FLAGS) -fpermissive -c ReaderFiles§read_us.cpp

UsingUs.o: UsingUs.hpp
	g++ $(FLAGS) -fpermissive -c UsingUs.cpp

program: main.o  VMGlobals.o ViewerFiles§Exibidor.o ClassFileStructures§ClassFile.o ReaderFiles§ClassLoader.o
	g++ $(FLAGS) -fpermissive main.o  VMGlobals.o ViewerFiles§Exibidor.o \
	ClassFileStructures§ClassFile.o ReaderFiles§ClassLoader.o -o ____

cl:
	rm -f *.o