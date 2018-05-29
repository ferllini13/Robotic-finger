APP = roboticFinger
CONF = code.conf
CC = gcc -o


all: driver
	$(CC) Interpreter/$(APP) Interpreter/$(APP).c
	@cd driver/ && make
	rm -rf *.o


install:
	@cd driver/ && make load
	sudo cp Interpreter/$(APP) /usr/bin/
	sudo chmod +x /usr/bin/$(APP)


runServer:
	@cd test_app && hostname -I
	@cd test_app && live-server --port=8000

run:
	python2 gui/screen.py


runInterpreter:
	$(APP) -c $(CONF)


remove:
	rm -rf Interpreter/$(APP)
	@cd driver/ && make unload
	@cd driver/ && make clean
	sudo rm /usr/bin/$(APP)