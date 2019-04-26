CC=gcc
STD=-std=gnu99
#pipe 通过管道生成目标文件 O2优化级别 Wall生成更多警告 Werror 把警告当错误
FLAGS=-pipe -O2 -Wall
OBJ=admin.o main.o sams.o student.o teacher.o tools.o
BIN=sams

all:$(OBJ)
	$(CC) $(OBJ) -o $(BIN)

%.o:%.c
	$(CC) $(STD) $(FLAGS) -c $< -o $@

clean:
	rm $(OBJ) $(BIN)
