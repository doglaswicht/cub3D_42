
Estructure du cub3D

´´´
cub3D/
├── Makefile
├── include/
│   ├── cub3d.h
│   ├── parse.h
│   ├── render.h
│   └── utils.h
├── libft/
│   ├── (tua libft completa aqui)
│   └── Makefile
├── src/
│   ├── main.c
│   ├── init/
│   │   ├── init_mlx.c
│   │   └── init_data.c
│   ├── parser/
│   │   ├── parse_map.c
│   │   ├── parse_file.c
│   │   └── check_errors.c
│   ├── render/
│   │   ├── draw.c
│   │   └── raycaster.c
│   └── utils/
│       ├── error.c
│       └── free.c
└── maps/
    └── map.cub

´´´
