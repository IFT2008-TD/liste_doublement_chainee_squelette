# Squelette de projet pour la classe Liste

Voici le projet que nous utiliserons lors de la séance de travaux dirigés du jeudi mai, 11:00.

Il s'agit exactement du problème proposé dans le fichier Liste.zip disponible sur le site du cours, avec des tests légèrement modifiés et quelques modifications cosmétiques de l'interface.  

Libre à vous de travailler ce problème à-partir du présent template, ou du fichier du site du cours.  Le présent template est suggéré strictement pour votre commodité.

## Travail à faire

- Analyser l'interface de la classe: les méthodes publiques sont dans Liste.h.  La documentation de ces méthodes est dans Liste_Implantation.h avec les prototypes des méthodes.
- Les comportements souhaités sont décrits dans la documentation et correspondent aux tests dans /tests/tests_liste.cpp
- Les méthodes privées sont suggérées.  Vous pouvez faire ce que vous voulez avec.  L'important est de respecter l'interface.

## Pour réflexion

- Il y a deux manières d'implanter une liste doublement chaînée: avec ou sans sentinelle.  Pouvez-vous faire les deux versions?  Quels sont les avantages et inconvénients d'avoir des sentinelles?
- Nous avons vu qu'il existe deux stratégies, en C++ pour réduire la duplication des programmes:
  - Les templates
  - L'héritage
  - Laquelle de ces deux stratégies pourrait nous servir à implanter une liste circulaire?