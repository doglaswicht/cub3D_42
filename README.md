```
.
├── Makefile
├── README.md
├── clean_x11.supp
├── include
│   └── cub3d.h
├── libft
│   ├── Makefile
│   ├── documentation.txt
│   ├── ft_atoi.c
│   ├── ft_bzero.c
│   ├── ft_calloc.c
│   ├── ft_isalnum.c
│   ├── ft_isalpha.c
│   ├── ft_isascii.c
│   ├── ft_isdigit.c
│   ├── ft_isprint.c
│   ├── ft_itoa.c
│   ├── ft_memchr.c
│   ├── ft_memcmp.c
│   ├── ft_memcpy.c
│   ├── ft_memmove.c
│   ├── ft_memset.c
│   ├── ft_putchar_fd.c
│   ├── ft_putendl_fd.c
│   ├── ft_putnbr_fd.c
│   ├── ft_putstr_fd.c
│   ├── ft_split.c
│   ├── ft_strchr.c
│   ├── ft_strdup.c
│   ├── ft_striteri.c
│   ├── ft_strjoin.c
│   ├── ft_strlcat.c
│   ├── ft_strlcpy.c
│   ├── ft_strlen.c
│   ├── ft_strmapi.c
│   ├── ft_strncmp.c
│   ├── ft_strnstr.c
│   ├── ft_strrchr.c
│   ├── ft_strtrim.c
│   ├── ft_substr.c
│   ├── ft_tolower.c
│   ├── ft_toupper.c
│   ├── get_next_line.c
│   ├── get_next_line.h
│   └── libft.h
├── map_senario
│   ├── error
│   │   ├── test_big_hole.cub
│   │   ├── test_color_invalid_ok.cub
│   │   ├── test_color_trailing_a_corriger.cub
│   │   ├── test_duplicate_texture_ok.cub
│   │   ├── test_empty_line_in_map_ok.cub
│   │   ├── test_invalid_char_ko_message.cub
│   │   ├── test_missing_texture_ok.cub
│   │   ├── test_multiple_spawns_ok.cub
│   │   ├── test_open_map_left_ok.cub
│   │   ├── test_open_map_top_ok.cub
│   │   ├── test_spaces_hole_verifier.cub
│   │   ├── test_spawn_all_dirs.cub
│   │   └── test_trailing_spaces_acorriger.cub
│   ├── test_10_10.cub
│   ├── test_angle.cub
│   ├── test_angle_error.cub
│   ├── test_big_room.cub
│   ├── test_box_center.cub
│   ├── test_corridor_EW.cub
│   ├── test_corridor_NS.cub
│   ├── test_corridor_ew_error.cub
│   └── test_near_wall.cub
├── maps
│   ├── map.cub
│   ├── simple.cub
│   └── test.map
├── maps_autres
│   ├── error
│   │   ├── empty.cub
│   │   ├── empty_lines.cub
│   │   ├── maxi_map.cub
│   │   ├── maxi_maps2.cub
│   │   ├── rgb_error.cub
│   │   ├── unvalid_floor.cub
│   │   ├── unvalid_id.cub
│   │   ├── unvalid_id2.cub
│   │   ├── unvalid_player.cub
│   │   └── unvalid_player2.cub
│   ├── fun.cub
│   ├── map_intra_subject.cub
│   ├── map_intra_subject_copy.cub
│   ├── test1.cub
│   ├── test5.cub
│   ├── test6.cub
│   ├── testE.cub
│   ├── testN.cub
│   ├── testS.cub
│   └── testW.cub
├── src
│   ├── core
│   │   └── main.c
│   ├── game
│   │   ├── game_destroy.c
│   │   ├── game_init.c
│   │   └── game_loop.c
│   ├── init
│   │   └── init_player_from_spawn.c
│   ├── input
│   │   ├── collision.c
│   │   ├── handle_input.c
│   │   ├── handle_move.c
│   │   ├── move_player.c
│   │   └── rotate_player.c
│   ├── mlx
│   │   ├── init_images.c
│   │   └── mlx_init.c
│   ├── parser
│   │   ├── find_spawn.c
│   │   ├── parse_cub.c
│   │   ├── parse_line.c
│   │   ├── parse_map_line.c
│   │   ├── parse_rgb.c
│   │   ├── read_line.c
│   │   └── validate_map.c
│   ├── render
│   │   ├── cast_rays.c
│   │   ├── color_shading.c
│   │   ├── compute_dda_params.c
│   │   ├── draw_columns.c
│   │   ├── fill_column_rendering.c
│   │   ├── get_face.c
│   │   ├── render.c
│   │   ├── render_background.c
│   │   └── run_dda.c
│   ├── textures
│   │   ├── init_tex.c
│   │   ├── tex_utils.c
│   │   └── wall_tex_coords.c
│   └── utils
│       ├── free_world.c
│       ├── utils.c
│       └── utils.time.c
├── textures
│   ├── Wall1.xpm
│   ├── Wall2.xpm
│   ├── Wall3.xpm
│   ├── Wall4.xpm
│   ├── fun1.xpm
│   ├── fun2.xpm
│   ├── fun3.xpm
│   ├── fun4.xpm
│   ├── testE.png
│   ├── testE.xpm
│   ├── testN.png
│   ├── testN.xpm
│   ├── testS.png
│   ├── testS.xpm
│   ├── testW.png
│   └── testW.xpm
└── valgrind.suppresion

19 directories, 139 files
```
leaks:
Sans suppression X11:
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./cub3d maps_autres/map_intra_subject.cub

Avec suppression X11 V1:
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --suppressions=valgrind.suppresion ./cub3d maps_autres/map_intra_subject.cub

Optimisation avec callgrind:
1:
valgrind --tool=callgrind ./cub3d map_senario/test_big_room.cub
2:
callgrind_annotate callgrind.out.*
3 - info juste basique:
callgrind_annotate --auto=yes callgrind.out.8681 | less