#!/bin/bash
echo -e "[!] Bienvenue dans le projet strucitc [!]\n"
echo -e "Les directives du makefile se sont déroulées avec succès !"
echo -e "\n./strucitc filename.c [OPTIONS]"
echo -e ">> C'est le fichier qui permet la vérification et la génération de code de strucit-frontend à strucit-backend"
echo -e "\n./check_backend filename.be"
echo -e ">> C'est le fichier qui permet la vérification du langage strucit-backend"
echo -e "\nProjet-Compilation-2020.pdf"
echo -e ">> C'est le fichier qui regroupe l'énoncé du projet"
echo -e "\nfrontend/"
echo -e ">> Regroupe les parties du générateur de code"
echo -e "\nbackend/"
echo -e ">> Regroupe les parties sur la vérification de code"
echo -e "\nChaque partie contient un dossier src/ qui contient les sources et un dossier test/ qui contient les tests"
echo -e "Chaque dossier src/ a son Makefile avec ses productions: clean, all, tests"
echo -e "\tmake clean: Permet de supprimer les fichiers générés par make all"
echo -e "\tmake: Permet de compiler la partie"
echo -e "\tmake tests: Permet de lancer les tests à partir du fichier src/mktests.sh"
