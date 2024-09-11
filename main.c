#include <stdio.h>

int main()
{
    float notes[100];
    char nom[100][15];
    char prenom[100][15];
    int choix, count = 0;
    float noteMax = 0.0, noteMin = 0.0;
    float somme = 0.0, moyenne = 0.0;

    do
    {
        printf("\nMenu Principal :\n");
        printf("1. Ajouter un etudiant\n");
        printf("2. Afficher la moyenne\n");
        printf("3. Trouver les meilleures et moins bonnes notes\n");
        printf("4. Verifier le nombre d'etudiants avec une note superieure a la moyenne\n");
        printf("5. Quitter le programme\n");
        printf("Choix : \n");
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:

            if (count >= 100)
            {
                printf("Nombre maximum d'etudiant atteint.\n");
                break;
            }
            
            printf("Entrez le prenom de l'etudiant : ");
            scanf("%s", prenom[count]);
            
            printf("Entrez le nom de l'etudiant : ");
            scanf("%s", nom[count]);
            
            printf("Entrez la note de l'etudiant : ");
            scanf("%f", &notes[count]);

            if (count == 0) 
            {
                noteMax = noteMin = notes[count];
            } 
            else 
            {
                if (notes[count] > noteMax) noteMax = notes[count];
                if (notes[count] < noteMin) noteMin = notes[count];
            }
            somme += notes[count];
            count++;
            break;
        case 2:
            if (count == 0)
            {
                printf("Aucun etudiant n'a ete ajoute.\n");
            }
            else
            {
                moyenne = somme / count;
                printf("La moyenne des notes est : %.2f\n", moyenne);
            }
            break;
        case 3:
            if (count == 0)
            {
                printf("Aucun etudiant n'a ete ajoute.\n");
            }
            else
            {
                printf("Meilleure note : %.2f\n", noteMax);
                printf("Moins bonne note : %.2f\n", noteMin);

                for (int i = 0; i < count; i++)
                {
                    if (notes[i] == noteMax)
                    {
                        printf("Etudiant avec la meilleure note : %s %s\n", prenom[i], nom[i]);
                    }
                    if (notes[i] == noteMin)
                    {
                        printf("Etudiant avec la moins bonne note : %s %s\n", prenom[i], nom[i]);
                    }
                }
            }
            break;
        case 4:
            if (count == 0)
            {
                printf("Aucun etudiant n'a ete ajoute.\n");
            }
            else
            {
                int x = 0;
                for ( int i = 0; i < count; i++)
                {
                    if (notes[i] > moyenne)
                    {
                        x++;
                    }
                }
                printf("Nombre d'etudiants avec une note superieure a la moyenne : %d\n", x);
                break;
            }
        case 5:
            printf("Quitter le programme.\n");
            break;

        default:
            printf("Choix invalide. Veuillez réessayer.\n");
            break;
        }
    } while (choix != 5);

    return 0;   
}