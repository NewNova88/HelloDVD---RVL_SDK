# HelloDVD - RVL_SDK (Nintendo Wii)

Petit exemple de chargement d'un fichier sur le DVD avec le Revolution SDK (le SDK de la Nintendo Wii).

Réalisé sur CodeWarrior For Wii V1.7 sur Windows XP SP3.

# Régler le dossier DVDDATA

ETAPE 1 :

Créer le dossier dvddata.
Il est préférable de le créer à la racine du projet CodeWarrior.


ETAPE 2 :

Changer la racine.
Pour cela, ouvrir une invite de commande (Win+R puis CMD), et taper ceci : 

setndenv DvdRoot "[CHEMIN VERS DVDDATA]"

Remplacer [CHEMIN VERS DVDDATA] par votre chemin absolu. 
Il doit rester entre les guillemets.


Ne pas oublier que le changement de racine est valable pour toute la session.
Donc si vous travaillez sur de multiples projets avec leurs DVDDATA propres, 
il faudra changer à chaque fois.
