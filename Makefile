PROG = blinky

CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
CP = arm-none-eabi-objcopy
RM = rm -f

OBJDIR = build
DEPDIR = .deps

CFLAGS = -g -mcpu=cortex-m4 -mthumb -Wall -O0
LFAGS = -nostdlib -T stm32f411-flash.ld
DEPFLAGS = -MMD -MP -MF $(DEPDIR)/$*.d

SRCS = $(wildcard *.c)

#SRCS = startup.c \
			 main.c
#\ faz somente a quebra da linha

#OBJS = $(OBJDIR)/startup.o $(OBJDIR)/main.o
#OBJS = $(addprefix $(OBJDIR)/, $(addsuffix .o, $(baseneame $(SRCS))))
OBJS = $(patsubst %, $(OBJDIR)/%.o, $(baseneame $(SRCS)))
DEPS = $(patsubst %, $(DEPDIR)/%.d, $(baseneame $(SRCS)))

$(shell mkdir -p $(dir $(OBJS)) > /dev/null)
$(shell mkdir -p $(dir $(DEPS)) > /dev/null)

all: $(PROG).elf

$(PROG).elf: $(OBJS)
	$(LD) $(LFAGS) $^ -O $@
	$(CP) $@ binary $(PROG).bin

$(OBJDIR)/%.o: %.c $(DEPDIR)/%.d
	$(CC) -c $(CFLAGS) $(DEPFLAGS) $< -o $@

# Cria um novo target para cada arquivo de dependencia possivel

$(DEPS):

# Inclui conteudo dos arquivos de dependencia

-include $(DEPS):

#$(OBJDIR)/main.o: main.c config.h

.PHONY: clean
clean:
	$(RM) $(OBJDIR) $(DEPDIR) $(PROG).elf $(PROG).BIN

