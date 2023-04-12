#
#

NOM=libmlx.a
AR=ar -r
RANLIB=ranlib
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
SRC+= mlx_png.c mlx_mouse.m
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2 -Wno-deprecated-declarations

# add to match string put with X11 in size and position
CFLAGS+= -DSTRINGPUTX11

.SILENT: = $(OBJ1) $(OBJ) $(CFLAGS) $(NOM) $(AR) $(RANLIB)

all: $(NOM)

$(NOM):	$(OBJ)
	@$(AR) $(NOM) $(OBJ)
	@$(RANLIB) $(NOM)

clean:
	@rm -f $(NOM) $(OBJ) *~
	@rm -f mlx_app

re: clean all
