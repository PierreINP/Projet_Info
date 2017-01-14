
CFLAGS=-g

all : monExe 

monExe : Lexeme.o testLexeme.o 
	g++ -o monExe $^ $(LDFLAGS)

%.o:%.cc
	g++ $(CFLAGS) -c -g $^

clean:
	rm -f *.o *~ test testLexeme
