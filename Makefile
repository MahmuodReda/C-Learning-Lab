build: 
	g++ .\main.cpp -o main.exe 
run:
	.\main.exe 
clean:
	del .\main.exe
	
all: build run clean