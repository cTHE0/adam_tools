#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/leon_the_god.h"
#include "../include/comp_datas.h"

const char *holy_sayings = 
	"Au commencement, Dieu créa le ciel et la terre. Genèse 1:1\n"
"Et Dieu dit : Que la lumière soit ! Et la lumière fut. Genèse 1:3\n"
"Dieu vit tout ce qu'il avait fait : cela était très bon. Genèse 1:31\n"
"Dieu bénit Noé et ses fils, et leur dit : Soyez féconds, multipliez, et remplissez la terre. Genèse 9:1\n"
"Aimez-vous les uns les autres ; comme je vous ai aimés, vous aussi, aimez-vous les uns les autres. Jean 13:34\n"
"Car Dieu a tant aimé le monde qu'il a donné son Fils unique, afin que quiconque croit en lui ne périsse point, mais qu'il ait la vie éternelle. Jean 3:16\n"
"Ne vous conformez pas au siècle présent, mais soyez transformés par le renouvellement de l'intelligence. Romains 12:2\n"
"Que votre lumière luise ainsi devant les hommes, afin qu'ils voient vos bonnes œuvres, et qu'ils glorifient votre Père qui est dans les cieux. Matthieu 5:16\n"
"Dieu est amour ; et celui qui demeure dans l'amour demeure en Dieu, et Dieu demeure en lui. 1 Jean 4:16\n"
"Au nom d'Allah, le Tout Miséricordieux, le Très Miséricordieux. Coran 1:1\n"
"Louange à Allah, Seigneur de l'univers. Coran 1:2\n"
"Le Très Miséricordieux, le Très Miséricordieux, le Maître du Jour de la rétribution. Coran 1:3-4\n"
"C'est Toi Dieu que nous adorons, et c'est Toi Dieu dont nous implorons secours. Coran 1:5\n"
"Guide-nous dans le droit chemin, le chemin de ceux que Tu as comblés de faveurs. Coran 1:6-7\n"
"Certes, Nous t'avons accordé une victoire éclatante. Coran 48:1\n"
"Allah est le Protecteur de ceux qui ont la foi : Il les fait sortir des ténèbres à la lumière. Coran 2:257\n"
"Ô vous qui avez cru ! Craignez Allah comme Il doit être craint. Coran 3:102\n"
"Dis : « Il est Allah, Unique. Allah, Le Seul à être imploré pour ce que nous désirons. Coran 112:1-2\n"
"Il n'a jamais engendré, n'a pas été engendré non plus. Coran 112:3\n"
"Et nul n'est égal à Lui. Coran 112:4\n"
"Le Bouddha dit : « Vous êtes ce que vous pensez. » Dhammapada 1:1\n"
"Toutes les choses sont précédées par l'esprit, dirigées par l'esprit, créées par l'esprit. Dhammapada 1:2\n"
"Si une personne parle ou agit avec un esprit impur, la souffrance la suit. Dhammapada 1:3\n"
"Si une personne parle ou agit avec un esprit pur, le bonheur la suit, comme une ombre qui ne la quitte jamais. Dhammapada 1:4\n"
"La haine ne cesse pas par la haine en ce monde ; la haine cesse par l'amour. Dhammapada 1:5\n"
"Celui qui vit en regardant les plaisirs des sens, avec des sens non maîtrisés, est modéré dans sa nourriture, fidèle et persévérant. Dhammapada 7:1\n"
"Comme une fleur belle et parfumée, pleine de couleur, mais sans substance, ainsi sont les paroles et les actions fruites de celui qui ne pratique pas. Dhammapada 50:1\n"
"Mieux vaut vivre un seul jour en méditant et en réfléchissant que vivre cent ans sans sagesse ni maîtrise de soi. Dhammapada 110:1\n"
"Celui qui se vainc lui-même est plus fort que celui qui vainc mille fois mille hommes sur un champ de bataille. Dhammapada 103:1\n"
"Le mal fait à autrui nous revient comme la poussière jetée contre le vent. Dhammapada 127:1\n"
"Dieu est notre refuge et notre force, un secours toujours présent dans la détresse. Psaume 46:1\n"
"Le Seigneur est mon berger : je ne manquerai de rien. Psaume 23:1\n"
"Dieu est esprit, et il faut que ceux qui l'adorent l'adorent en esprit et en vérité. Jean 4:24\n"
"Car Dieu n'est pas un Dieu de désordre, mais de paix. 1 Corinthiens 14:33\n"
"Dieu est fidèle, et il ne permettra pas que vous soyez tentés au-delà de vos forces. 1 Corinthiens 10:13\n"
"Dieu a tant aimé le monde qu'il a donné son Fils unique, afin que quiconque croit en lui ne périsse point, mais qu'il ait la vie éternelle. Jean 3:16\n"
"Dieu est lumière, et en lui il n'y a point de ténèbres. 1 Jean 1:5\n"
"Dieu est amour, et celui qui demeure dans l'amour demeure en Dieu, et Dieu demeure en lui. 1 Jean 4:16\n"
"Dieu est notre refuge et notre force, un secours toujours présent dans la détresse. Psaume 46:1\n"
"Dieu est esprit, et il faut que ceux qui l'adorent l'adorent en esprit et en vérité. Jean 4:24\n"
"Allah est le Créateur de toute chose, et Il est le Garant de toute chose. Coran 39:62\n"
"Allah est Celui qui a créé les cieux et la terre et qui, du ciel, a fait descendre une eau. Coran 14:32\n"
"Allah est Celui qui a créé sept cieux et, de la terre, une semblable. La création descend entre elles. Coran 65:12\n"
"Allah est Celui qui a créé la nuit et le jour, le soleil et la lune. Chacun vogue dans une orbite. Coran 21:33\n"
"Allah est Celui qui a assujetti la mer pour que vous mangiez de sa chair fraîche. Coran 16:14\n"
"Allah est Celui qui a fait de la terre un lit pour vous et du ciel un toit. Coran 2:22\n"
"Allah est Celui qui a créé l'homme d'un caillot de sang. Coran 96:2\n"
"Allah est Celui qui a fait descendre le Livre avec la vérité et la balance. Coran 42:17\n"
"Allah est Celui qui a créé les anges, messagers dotés d'ailes. Coran 35:1\n"
"Allah est Celui qui a créé les cieux et la terre en six jours. Coran 7:54\n"
"Le Bouddha dit : « La paix vient de l'intérieur. Ne la cherchez pas à l'extérieur. » Dhammapada\n"
"Le Bouddha dit : « La méditation apporte la sagesse ; le manque de méditation laisse l'ignorance. » Dhammapada\n"
"Le Bouddha dit : « La santé est le plus grand des dons, la satisfaction le plus grand des richesses. » Dhammapada\n"
"Le Bouddha dit : « La vraie sagesse est de reconnaître sa propre ignorance. » Dhammapada\n"
"Le Bouddha dit : « La discipline est le chemin vers la liberté. » Dhammapada\n"
"Le Bouddha dit : « La compassion est la loi des plus forts. » Dhammapada\n"
"Le Bouddha dit : « La patience est la plus grande des prières. » Dhammapada\n"
"Le Bouddha dit : « La gratitude est la mémoire du cœur. » Dhammapada\n"
"Le Bouddha dit : « La simplicité est la clé de la paix intérieure. » Dhammapada\n"
"Le Bouddha dit : « La vérité est comme une lampe qui éclaire le chemin. » Dhammapada\n" ;

int count_lines(const char *filename) {
    FILE *f = fopen(filename, "r");
    if (!f) return -1;

    int lines = 0;
    int c;
    while ((c = fgetc(f)) != EOF) {
        if (c == '\n') lines++;
    }

    fclose(f);
    return lines;
}

char *get_line(const char *filename, int target_line) {
    FILE *f = fopen(filename, "r");
    if (!f || target_line < 0) return NULL;

    char *line = NULL;
    size_t len = 0;
    int current_line = 0;
    while (getline(&line, &len, f) != -1) {
        if (current_line == target_line) {
            fclose(f);
            return line; // La ligne est allouée dynamiquement
        }
        current_line++;
    }

    // Ligne non trouvée
    free(line);
    fclose(f);
    return NULL;
}

char* get_line_from_text(const char *text, int lineno) {
    static char line[1024];
    int current_line = 1;
    const char *start = text;
    const char *end;

    while (current_line < lineno && *start) {
        if (*start == '\n') current_line++;
        start++;
    }

    if (current_line != lineno) return NULL;

    end = strchr(start, '\n');
    if (!end) end = start + strlen(start);

    size_t len = end - start;
    if (len >= sizeof(line)) len = sizeof(line) - 1;

    memcpy(line, start, len);
    line[len] = '\0';
    return line;
}

char* replace_all(const char* texte, const char* mot, const char* remplacement) {
    size_t len_texte = strlen(texte);
    size_t len_mot = strlen(mot);
    size_t len_rep = strlen(remplacement);

    // Compter le nombre d’occurrences du mot
    size_t count = 0;
    const char *p = texte;
    while ((p = strstr(p, mot)) != NULL) {
        count++;
        p += len_mot;
    }
    if (count == 0) return NULL; // aucun remplacement

    // Calcul taille nouvelle chaîne
    size_t len_new = len_texte + count * (len_rep - len_mot);

    char *result = malloc(len_new + 1);
    if (!result) return NULL;

    const char *src = texte;
    char *dst = result;

    while ((p = strstr(src, mot)) != NULL) {
        // copier texte avant occurrence
        size_t n = p - src;
        memcpy(dst, src, n);
        dst += n;

        // copier remplacement
        memcpy(dst, remplacement, len_rep);
        dst += len_rep;

        src = p + len_mot;
    }

    // copier le reste
    strcpy(dst, src);

    return result;
}

void print_saying(char *name) {
    int i_line = get_exact_time() % 61;
    char *original_line = get_line_from_text(holy_sayings, i_line);
    if (!original_line) {
        printf("Erreur : impossible de lire la ligne.\n");
        return;
    }

    char *gods[] = {"Dieu", "Allah", "Le Bouddha"};

    for (int i = 0; i < 3; i++) {
        char *new_line = replace_all(original_line, gods[i], name);
        if (new_line) {
            printf("%s\n", new_line);
            free(new_line);
            return;
        }
    }

    // Aucun remplacement, on affiche la ligne originale
    printf("%s\n", original_line);
}
