bin/test : src/tui_test.cpp
	g++ src/tui_test.cpp -o bin/test -std=c++2a -lftxui-screen -lftxui-component -lftxui-dom -Iinclude       

bin/space : src/main.cpp
	g++ src/main.cpp -o bin/space -std=c++2a -lftxui-screen -lftxui-component -lftxui-dom -Iinclude      

bin/ventana : src/ventana.cpp include/*
	g++ src/ventana.cpp -o bin/ventana -std=c++2a -lftxui-screen -lftxui-component -lftxui-dom -Iinclude      

run : bin/space
	./bin/space

runTest : bin/test
	./bin/test

runVentana : bin/ventana
	./bin/ventana