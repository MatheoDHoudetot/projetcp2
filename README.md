Ici on peut écrire notre avancement par l'équipe et par personnes si jamais pour pas ce perdre dans ce qu'on a déjà fait.


17/02/2026 (2H):
  L'équipe:
    Création d'un google doc avec toutes les idées.


18/02/2026 (4H):

  L'équipe:
    division en deux groupe pour deux taches:
    - Antoine et Mael pour la création d'une maquette pour le site (code couleur, disposition...)
    - Mathéo et Valentin pour le back end connectivité entre arduino, base de donnée et site internet 
      et création de l'espace de travail collectif sur github pour travailler sur les mêmes ficher. 

  Valentin (détails):
    - J'ai d'abord tester la connexion entre l'esp et une base de données simple pour simplement lire 
      un fichier données sur le moniteur série dans l'IDE Arduino. Pour cela j'ai crée un fichier get.php 
      qui permet de faire le pont entre la base de donnée et l'ESP8266 et pour heberger les données 
      on crée un 'serveur' avec xxamp donc un serveur local.
      Pour avoir accés a cette base on crée un wifi local (point de connexion avec un téléphone par exemple) 
      ce qui permet a tout appareil connecté sur ce wifi d'accéder au serveur ce qui permet donc a l'ESP d'avoir accés au données.
    - Ensuite j'ai crée un fichier receive.php qui permet à l'arduino de modifier les données de la base.
    - Et enfin j'ai ajouté dans le fichier index.html un code qui, grace a des boutons, modifie la base de données
      grace à du javascript inclus dans le html et en passant par le ficher receive.php.


19/02/2026 (4H):

  L'équipe: Toujours sur les mêmes tâches.

  Valentin (détails):
  - J'ai voulu changer les nom de variables test en les remplacant par deux données binaires qui controle chacune un servo-moteur.
    Dans le code arduino j'ai donc crée une condition si la variable VarServoXX est égale à 0 alors le servo-moteur ce met a un angle de
    90°, attend X secondes puis ce referme et remet la variable VarServoXX à 0 dans la base de données. J'ai aussi fait 4 boutons
    dans le html pour controler les servo-moteurs a partir du site.
  - J'ai recu le lecteur RFID donc je l'ai cablé et tester puis
  - J'ai crée une fonction dans le code arduino qui permet de lire l'UID des cartes puis de l'envoyer dans la base de données à la variable
    "UIDactif".


20/02/2026 (4H):


    
