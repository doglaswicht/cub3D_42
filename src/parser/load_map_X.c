#include "cub3d.h"

// attention ceci c est le parsing
int load_map_simple(t_world *w, const char *path)
{
	int   fd;
	char  *line;
	int   cap = 8;      // capacité initiale du tableau
	int   count = 0;

	w->map = malloc(sizeof(char *) * cap);
	if (!w->map)
		return (1);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (free(w->map), 1);
	while ((line = get_next_line(fd)) != NULL) // tu pluggeras ton gnl ici
	{
		// enlever '\n' à la fin si présent
		int len = 0;
		while (line[len] && line[len] != '\n')
			len++;
		line[len] = '\0';

		// vérifier que c'est que '0' ou '1' (pour l'instant)
		for (int i = 0; i < len; i++)
			if (line[i] != '0' && line[i] != '1') {
				/* error → free et return 1 plus tard */
			}

		// agrandir le tableau si besoin
		if (count >= cap)
		{
			cap *= 2;
			/* réallocation à faire ici plus tard */
		}
		w->map[count] = line; // on garde la ligne telle quelle
		count++;
	}
	close(fd);
	w->map_h = count;
	w->map_w = (count > 0) ? (int)ft_strlen(w->map[0]) : 0;

	return (0);
}
