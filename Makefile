main_dir = "E:/GUI Projects/SFML/GUI"
default:
	g++ $(main_dir)/src/*.cpp -o build/core.exe -O2 -Wall -Wno-missing-braces -I$(main_dir)/headers -I$(main_dir)/Scenes -IC:/SFML-2.5.1/include/ -LC:/SFML-2.5.1/lib/ -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio