//WHERE TO PLACE DEBUG INFORMATIONS AND CHANGES ON THE RELEASE
/*
DATE: 19/12/2014

verifier icat perfs ?

nouveauté: appel de références de gélatines depuis la trichro

debug >
multiples débordements de tableaux ( merci à ruiserge de son accompagnement)
audio autoload depuis banger
rafraichissement macro channel au démarrage
fader compris dans un fgroup sur lui même
grand master plus facilement remétable à full
La sélection du bouton de ratio pour un crossfade manuel déclenchait à tors le GO
Enregistrement automatique des ratios lors de la manipulation
Faders echo: snap kill bounce coupe le LFO du Fader

to do:
core minifaders faders
doc chemin relatif
affichage grada plus lisible
lecteur audio last level et num de fichiers +
shift f1 nouvelle memoiore auto numerotage
visu midi au dessu s pastilles banger
liste gel debut

CFG_config_panel_8.cpp
----------------------
Erreur en ligne 1324 : il indique "Resource leak: cfg_file" mais je ne comprend pas, j'y vois juste un "return (1);"
4 Warnings : scanf without field width limits can crash with huge input data. Add a field width specifier to fix this problem: %s => %20s
si j'ai bien compris le conseil il faudrait  (%24s ou %23s) et (%17s ou %16s) pour les cas suivants
ligne 1387 fscanf( cfg_file , "%s\n" ,  IP_artnet_IN ); --> fscanf( cfg_file , "%24s\n" ,  IP_artnet_IN ); // char IP_artnet_IN[24];
... fscanf( cfg_file , "%s\n" ,  IP_artnet_OUT ); --> fscanf( cfg_file , "%24s\n" ,  IP_artnet_OUT ); // char IP_artnet_OUT[24];
... fscanf( cfg_file , "%s\n" ,  IP_fantastick ); --> fscanf( cfg_file , "%24s\n" ,  IP_fantastick ); // char IP_fantastick[24];
... fscanf( cfg_file , "%s\n" ,  specified_fs_ip ); --> fscanf( cfg_file , "%17s\n" ,  specified_fs_ip ); //char specified_fs_ip[17]={"192.168.1.13"};

saves_export_import.cpp
ligne 440 - erreur "Resource leak: fpscwz" que je ne comprend tjr pas
if ((fpscwz=fopen(f_boolcues, "rb"))==NULL)
ligne 492 "Possible null pointer dereference: fpscwz - otherwise it is redundant to check it against null." -- tjr pas compris peut-être l'heure :-)> non c est que j utilise le pointeur plusieurs fois je crois. a garder de coté.

save_show_13.cpp
----------------

ligne 1723 : sprintf(rep,"%s\%s\%s",mondirectory,rep_saves,nomduspectacle);
ligne 4701 : sprintf(rep,"%s\%s\%s",mondirectory,rep_saves,nomduspectacle);
ligne 7759 : sprintf(rep,"%s\%s\%s",mondirectory,rep_saves,nomduspectacle);
--> Incorrect format. A different number of actual arguments is expected while calling 'sprintf' function. Expected: 3. Present: 5.
bug de l'analyseur ou il faut doubler les anti-slash ? // a tester je penses plutot bug analyser. sur les slashs y a des trucs venant de linux (gcc) et de windows, qui font que c est pas forcément clair. Actuellement tout marche, la question est ce que ca pose un souci de débordement quelque part ?

main_janv_2014_opensource_kbd.cpp
---------------------------------
ligne 573 : if((bytesreceived=recvfrom(sock,artnet_message,sizeof(artnet_message),0,(SOCKADDR*)&sinServ,&sinsizeServ)>0))
--> Consider reviewing the expression of the 'A = B > C' kind. The expression is calculated as following: 'A = (B > C)'.
ligne 1071 : if((bytesreceived = recvfrom(sock,artpollreply_message,sizeof(artpollreply_message),0,(SOCKADDR*)&sinS,&sinsize)!=0))
--> Consider reviewing the expression of the 'A = B != C' kind. The expression is calculated as following: 'A = (B != C)'.
va falloir se pencher dessus, mais pour l instant tout fonctionne sur la réception artnet...



//////TO DO///////////////////////////////////////////////


wizard logical
icat logical
cfg menu logical


si en mode check dimmers ne pas désolectionner les dimmers apres affectation >

revoir check chan et aparition dimmers


to do: rwannoux systemes groupes de device et picker une couleur ou cycler une

couleur

identifiant midi en affect midi > afficher l id pas au survol !


DOC:

FAIRE UN DO LOGIC POUR ICAT ET WIZARD

accelerometre slave / chaser rwanoux partagé sur plusieur faders !!!

faire un mode fader Exclusive ( fader solo flash solo / impact Faders / Sequenciel /

All)

to do audio > export midi > export pdf

midi export audio autopause et autocue



keyboard customizing

LIST: BUG NBRE PROJOS
import ascii temps minutes passent en secondes !!!


faders: assign midi de chaque dock !

wizard: insert de memoires il fait disparaitre la FROM MEMORY


refaire layout telecommandes

NETTOYER DO LOGICAL

PLOT PB PATCH ET SAISIE PROJOS SYMBOLS

//////////////////////////////////////////////////////////////////////////
BUG ESC F1= quand on fait CTRL flag !!! >>> KB_CTRL_FLAG

ctrl s affichage merde sur pc recent > pb driver

harmoniser les affichages survol midi les retours d affectations

damper mode pour contenu fader

faire proc affichage sur CFG


Bugs vus en stage martinique:

draw refresh ipad avec Matrix num. En activ ok, pas en matrix num

ibrahim: un bouton black out faders + stage

hosni: patch : num circ F1 click dimmer / bouton select all / unselect all sur les

channels view

affichage temps delays deborde sur chiffres in out seq


affectation midi = Beep ? question des sons de base

fichier bat pour creer serevur ad hoc sur w8

déplacement barre des circuits en mode perso view= 0

nommer les courbes avec F5

Rotation GPL> Draw

Passer mode BPM sur Chasers + GPL + Tap Tempo

bug plot: nom du plan avec espace fout le bordel dans la lecture des datas de plot/

pb de scanf


roue trichromie en relatif

icat -> une previsu de la couleur

revoir param plot et XML

se pencher sur les sauvegardes XML




BUGS:

bug plot sur selectuin et recopie selection des notes

nettoyage d un fader ( contenu buffer fader ) au changement d affectation



probleme roll back sur banger et SAW d un fader


WIZARD sur faders please !


nav circuit shift flecheches haut bas pour +12


MOLETTE:
molette sur faders molette sur circuit mode jacques

Midi:
affichage au survol de la string midi de la commande > Systematiser les affichages

dans toutes les procs


faders:
flash solos mode
selection clavier d un fader
un mode pour monter a la fleche haut basse le fader sélectionne


CFG midi: un onglet pour voir les affectation par numero de controleur, ou par

grande famille

Channel macros: AND NOT OR Circuit Condition num


/////////////////////////////////////////////////////////////





verifier artnet poll


Force midi pour gridplayer

Gridplayer: clicker mode pour reprendre molette les niveaux

DMX IN ENTTEC BROKEN

souci up down si temps trop rapide fader va pas à full

Jacques whitecat

CHANEL TIME


descripteur POrts com et selecteur d'affectation port COM enttec pro et open et

arduino !




WIZARD, chantier:
swap exchange > macros
/ + wizard channel sur faders et autres contenus dynamiques
/ + wizard mems sur chasers !


ajouter dans wizard recopie d un bloc de memoires

rajouter dans wizard une fonction multiply en float des valeurs



////////////////////////////////



clear ciruits non solicites depuis wizard



roue midi en relatif

saturation roue midi sur controle midi




associer courbes aux docks, pas aux faders !

veritables channel time sur sequenciel


creer 92 grpes de circuits + noms



wizard> affecter chasers, faders, grid, trichro, video tracking, banger, list



aide: un espace au survol, affichable

Nico:l'aide intégrée dans Whitecat :
Cette idée est directement inspirée du logiciel audio Live Ableton : une petite

fenêtre que l'on décide ou non d'afficher et dans laquelle vient s'inscrire l'aide

concernant le bouton, la fenêtre etc... que l'on est entrain de survoler avec la

souris à l’écran. Hyper rapide et efficace. Le meilleur système d'aide rapide que je

connaisse.
Cette fenêtre pourrait également afficher le raccourci clavier d'un bouton survolé.

revoir les affichages de contenu attirb midi de manièr systematique








question de repercussion de memes commandes sur commandes midi grid banger / icat /

arduino.
Tout revoir et centraliser en un seul bloc d automations ?

//Midi Preset Canevas

Mover

catégories audio dans iCat et Banger



//////////////////////////////////////////////////////////////////////////

fonction PICK UP  à créer:

Importer / exporter des chasers/grid : de manière précise, c est celà ( genre

charger depuis un autre show les chasers 4, 18 et 25 ) ? avec une possibilité de les

visualiser ?
ou bien tu parles d un panel affichant leur descriptif, un peu à l instar de LIST ,

et te permettant de les charger rapidement ?

Banger / Chaser / fader / memory / temps des memoires séparés


///////////////////////

/////////////////////
Kaptur à faire comme ici: http://www.zikinf.com/news/kapture-pad-total-recall-

tactile-ableton-live-929



/////////////////////////
faire color vert rouge en personnalisable


///////////////
Mapping clavier
English mapping kbd from help menu

Pour un clavier QWERTY, le A et le Q sont inversés (par rapport à un AZERTY). Le W

et le Z sont inversés.
Le M se trouve à la place de la touche ",?" (celle juste après le N, où tu as

programmé un point) et la touche point sur un QWERTY devrait se retrouver sur la

touche ":/" de l'AZERTY (3ème après le N).
Fr	 Eng
A/a	 Q/q	(this is the 1st key in the 2d row)
Q/q	 A/a	(this is the 1st key in the 3d row)
W/w	 Z/z	(this is the 1st key in the 4th row)
Z/z	 W/w	(this is the 2d key in the 2d row)
M/m	 :/; (this is the 10th key in the 3d row)
./,	 M/m	(this is the 7th key in the 3d row)
???	 >/.	(this is the 9th key in the 3d row)

J'ai vu d'ailleurs que  tu avais programmé le point à la fois sur la touche ",?" et

sur la touche ";/", mais je crois pas que ça ait la moindre incidence...

/////////////////////////

tracker > mover

//////////////////////////

arduino artnet client

//////////////////////
banger  -> chasers BACK
	-> minifaders Back




////////////////////////////////////////////////////////////////////////////////////

//
Sequenciel:

PB affichage temps sequenciels
AFfichage temps dans sequenciel: . Il reste une anomalie dans le calcul/affichage

des temps
Le temps global représenté est affecté d'un décalage secondes vers minutes (et peut

être pire) !
Avec l'exemple en illustration au surplus un go back fait apparaitre des temps

négatifs !


////////////////////////////////////////////////////////////////////////////////////
List: faire une option FOLLOW des circuits en les choisissant en affcihage dans list

///////////////////////////////////////////////////////////////


//////////////////////////
DMX:
-LTP mode
-descriptif des pas dans LTP ( 5% ou 10%)
-16 bits

//////////////////////////
-EDITEUR DE NOMS DE PRESETS


////////////////////////
BANGER:
-condition si enchassé dans memoire en cours, affecter le speed aux temps
-incorporer la pause dans les envois banger en mémoires / et revoir le goback sur

base temps
-go backs manquant

/////////////
Tracking:
-refresh image video à l ouverture
-params image par sec ailleurs ? dans CFG?


/////////////////
Faders:

-fonction autopaste sur dock pour passer d un dock a l autre les direct ch / idem

pour le son
-Lors de LFO rapides (mini chaser) les circuits n'ont pas le temps de revenir à

zéro.
-fonction snapshot d etat des faders / sel et pas sel
-avec 6 ou touches de recall des états ( équivalent au recall g)
-donner nom general a un fader
-grand master du buffer faders

////////////////////
direct CH:
-affecter direct channel en mode raffale ( *8 ou *12) sur les docks en mode

horizontal


//////////////////////////////////
midi:
-mode direct Chan Midi hors systeme faders
-Midi routage velocité:  Bang mode sur un CC on/OFF
-barre fader en relatif ou absolute
-roue de couleur absolute et relatif


-ASCII sur congo v6 : enchainements automatiques des mémoires décalés (au lieu de

passer de la 2 à la 3 tout seul, ce chat passe de 3 à 4 seul)
ascii avab VLC SAFARI ne prends pas export WCAt en ASCII voir forum



Network:
-trouver qui coorespond à quoi ( rj45 / wifi) ( nom de carte)

CROSSFADE SEQ:
-taper mem + racc clavier pour charger en preset une mem
-raccourcis pour les affectations de temps avec syntaxe de mémoire

Circuits:
-groupes: Ctrl-1 Ctrl-2 ... // faire 10 groupes sur le coté + descriptif.

Launchpad:
-Rajouter le clignotant, se pencher dessus, nom de nom


Optimisation:
-cleaner core/visu  saveload wizard
-optimiser procs affichage sur configs


Audio:
-direct ch mode
-revoir la bibliothèque ? implémentation différentes fréquences ? ou bien changer

complètement ?

MENUS:
-timeline
-plot
-serveur video
-matrice midi: des presets midi, nommables, qui permettent d appeler avec un meme

bouton differentes actions.


DMX:
-Enttec Pro -> passer en FTDI driver pour IN et OuT simultannés
-adaptation retro compatibilité 6c siudi
-LANBOX
-artnet : Subnet à faire en parametres


*/
