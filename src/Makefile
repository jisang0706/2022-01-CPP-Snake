CC = g++
CFLAGS = -std=c++14 -fshort-wchar

LDFLAGS =
LDLIBS = -lncursesw

OBJS = Point.o kbhit.o Snake.o SnakeMap.o UserData.o GameData.o Game.o GameFlow.o GameManager.o SnakeGame.o GateManager.o Renderable.o UserData.o Mission.o Item.o ItemManager.o

TARGET = SnakeGameExe

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) -o $@ $^ $(LDLIBS) $(CFLAGS)

UserData.o : UserData.cpp UserData.h
	$(CC) -c UserData.cpp

Mission.o : Mission.cpp Mission.h UserData.h
	$(CC) -c Mission.cpp

Renderable.o : Renderable.cpp Renderable.h
	$(CC) -c Renderable.cpp

Point.o : Point.cpp Point.h
	$(CC) -c Point.cpp

kbhit.o : kbhit.cpp kbhit.h
	$(CC) -c kbhit.cpp

Snake.o : Snake.cpp Snake.h Point.h GameSettings.h
	$(CC) -c Snake.cpp

SnakeMap.o: SnakeMap.h SnakeMap.cpp Point.h
	$(CC) -c SnakeMap.cpp

GameData.o: GameData.cpp GameData.h Point.h SnakeMap.h GameSettings.h Renderable.h kbhit.h
	$(CC) -c GameData.cpp

Game.o : Game.cpp Game.h Snake.h GameSettings.h GameData.h UserData.h GateManager.h ItemManager.h Mission.h
	$(CC) -c Game.cpp

GameFlow.o : GameFlow.cpp GameFlow.h kbhit.h
	$(CC) -c GameFlow.cpp

GameManager.o : GameManager.cpp GameManager.h Game.h GameSettings.h
	$(CC) -c GameManager.cpp

SnakeGame.o : SnakeGame.cpp GameManager.h NcursesSetting.h GameFlow.h
	$(CC) -c SnakeGame.cpp

GateManager.o : GateManager.cpp GateManager.h Point.h GameData.h GameSettings.h UserData.h
	$(CC) -c GateManager.cpp

Item.o: Item.cpp Item.h Point.h 
	$(CC) -c Item.cpp

ItemManager.o: ItemManager.cpp ItemManager.h Item.h Point.h UserData.h GameData.h GameSettings.h
	$(CC) -c ItemManager.cpp

clean :
	rm -rf $(TARGET) $(OBJS)
run :
	./$(TARGET)