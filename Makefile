# Compilador e flags
CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -O2
LDFLAGS = -lncurses

# Diretórios
SRCDIR = src
OBJDIR = obj
BINDIR = bin

# Arquivos
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))
TARGET = $(BINDIR)/compiled

# Regras principais
all: prepare $(TARGET)

# Criação do binário final
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDFLAGS)

# Compilação de cada arquivo-fonte
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Preparação de diretórios necessários
prepare:
	mkdir -p $(OBJDIR) $(BINDIR)

# Limpeza
clean:
	rm -rf $(OBJDIR) $(BINDIR)

# Regra para depuração (recompila do zero)
rebuild: clean all
