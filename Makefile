SRC = src/main.c

PROJECT_NAME = testfinal.out

$(PROJECT_NAME): $(SRC)
	gcc $(SRC) -o $(PROJECT_NAME)

run:$(PROJECT_NAME)
	./${PROJECT_NAME}