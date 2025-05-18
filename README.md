==========================================                                                                     
ADAM'S TOOLS
==========================================
Adam Tools est une collection d’outils système personnalisés pour Linux, développée en C.

📦 Installation
----------------

1. Télécharger le paquet `.deb`

Depuis la dernière version disponible sur GitHub :

    wget https://github.com/cTHE0/adam-tools/releases/latest/download/adam_tools_1.0_amd64.deb

2. Installer le paquet

    sudo dpkg -i adam_tools_1.0_amd64.deb

Si des erreurs de dépendances apparaissent, corrigez-les avec :

    sudo apt -f install


✅ Vérifier l'installation
---------------------------

Après installation, la commande suivante devrait être disponible :

    adam_tools


🔧 Exemple d'utilisation
-------------------------

Afficher les 16 premiers octets d’un fichier en binaire :

    adam_tools binary mon_fichier.txt 16


📁 Fichiers locaux
-------------------

Adam Tools utilise le répertoire `~/.adam_tools/` pour enregistrer ses données locales.
Ce dossier est créé automatiquement si nécessaire.


🛠️ Compilation manuelle (optionnel)
-------------------------------------

Si vous souhaitez compiler le projet manuellement :

    git clone https://github.com/cTHE0/adam-tools.git
    cd adam-tools
    make
    ./adam_tools


📄 Licence
-----------

MIT — libre d'utilisation et de modification.
