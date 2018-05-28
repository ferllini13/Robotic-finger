all:
	@cd driver/ && make
	@cd driver/ && make load
	@cd Interpreter && make

runInterpreter:
	@cd Interpreter/ && sudo ./roboticFinger -c code.conf

runGUI:
	@cd gui/ && make

clean:
	@cd driver/ && make unload
	@cd driver/ && make clean
	@cd Interpreter/ && make clean