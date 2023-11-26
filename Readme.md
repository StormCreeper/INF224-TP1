# Projet d'INF224 Telo PHILIPPE
## Projet
Il y la partie C++ qui est le serveur, et la partie Java qui est le client.

Avec la télécommande, on peut demander de lister les objects, d'en jouer un et de l'afficher à partir de son nom (list, display [nom] et play [nom]). Il y a trois fichiers de test, images et vidéos, dans le dossier `Medias` pour tester le programme.

Je n'ai pas fait la documentation avec Doxygen par manque de temps.

Lancer le serveur d'abord, puis le client, avec ``make run`` dans les bons dossiers (cpp et swing).
## Questions C++
### Etape 4
C'est une méthode virtuelle pure car elle n'a pas de définition dans la classe de base. Elle est donc obligatoire à implémenter dans les classes filles.

On la déclare comme ceci : `virtual void play() = 0;`
La classe de base devient alors abstraite, et on ne peut plus l'instancier.
### Etape 5
On utilise le polymorphisme pour appeler la méthode `play()` de la classe `Multimedia` sur un objet de type `Film` ou `Video`. Cela permet d'appeler la méthode `play()` de la classe fille, et non celle de la classe mère.

Il faut donc déclarer la méthode `play()` comme virtuelle dans la classe `Multimedia` : `virtual void play();`

Le tableau doit alors être un tableau de pointeurs de type `Multimedia` : `Multimedia** tab;`, ou pour utiliser des smart pointers : `std::vector<std::shared_ptr<Multimedia>> tab;`
### Etape 10
Pour interdire l'instantiation avec `new`, on rend le constructeur privé : `private: Photo();`
### Etape 13
J'ai utilisé la première méthode pour sa simplicité : en cas d'erreurs, les fonctions `addNewPhoto()`, `addNewVideo()` et `addNewFilm()` renvoient `null`, et affichent un message d'erreur. On peut alors tester le retour de ces fonctions pour savoir si l'ajout s'est bien passé.
## Questions Java
### Etape 1
On ne peut pas voir le texte qui dépasse du JTextArea, car il n'y a pas de scroll bar. Il faut donc ajouter un JScrollPane au JTextArea.