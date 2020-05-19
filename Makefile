all:
	@(cd front-end/Syntax-Tree/src/ && make 2>/dev/null)
	@(cd front-end/Intermediate-Code-Generator/src/ && make 2>/dev/null)
	@(cd back-end/Syntax-Analyser/src/ && make 2>/dev/null)
	@chmod +x front-end/Syntax-Tree/src/strucitfe
	@chmod +x front-end/Intermediate-Code-Generator//src/strucitfe
	@chmod +x back-end/Syntax-Analyser/src/strucitbe
	@chmod +x welcome.sh
	@./welcome.sh

clean:
	@(cd front-end/Syntax-Tree/src/ && make clean)
	@(cd front-end/Intermediate-Code-Generator/src/ && make clean)
	@(cd back-end/Syntax-Analyser/src/ && make clean)

install:
	sudo apt-get update -y
	sudo apt-get install -y build-essential
	sudo apt-get install -y flex bison
