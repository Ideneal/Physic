CC = g++
LIBRERIE = -lSDL -lSDL_image

ifeq ($(NAME), )
	NAME = physic
endif

compile: $(NAME)

%.o: %.cpp
	$(CC) -c $< -o $@

$(NAME): ball.o control.o image.o vettore.o view.o main.o
	@echo "inizio compilazione..."
	$(CC) -o $@ $^ $(LIBRERIE)

clear: ball.o control.o image.o vettore.o view.o main.o
	rm $^

