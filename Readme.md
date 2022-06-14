# Little C Compiler

## Un simple compileur générant un graph à partir d'un code C.

## Utilisation

#### Pour compiler le programme, il suffit d'exécuter compiler.sh avec la commande "./compiler.sh" en se trouvant dans le dossier racine du projet.
#### Un fichier exécutable "miniC" sera créé.
#### Ensuite, l'utilisation du programme s'effectue comme ceci :

```
./miniC Nom_Du_Fichier_Dot_Qui_Sera_Généré < chemin_du_fichier_miniC_à_lire
```

#### Le nom du fichier dot qui sera généré doit se situer dans le répertoire courant.

## Exemple
#### Exemple d'utilisations complète du projet : 

#### 1) ./compiler.sh
#### 2) ./miniC variables.dot < Tests/variables.c


## Tips
#### Pour faciliter la tâche, nous avons créé un script "runProgram.sh" qui exécute le programme miniC pour tous les Tests (listes des commandes écrites à la main).

#### Exemple d'utilisation complète du projet avec runProgram : 

#### 1) ./compiler.sh
#### 2) ./runProgram.sh


#### Après, il suffit de copier le contenu du fichier dot et de le copier par exemple dans "https://dreampuf.github.io/GraphvizOnline" pour le visualiser.
