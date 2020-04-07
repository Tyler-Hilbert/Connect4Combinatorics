DEPS = Main.cpp Board.cpp

C4Comb: $(DEPS)
	g++ -std=c++17 -o c4comb $(DEPS)
