🤖 TONY V0 – Robot Mobile Basic

Technological and Optimized Neural Yield – Version 0

TONY V0 est la première version expérimentale du projet TONY, un robot mobile éducatif développé par Toko_Clb Lab.
Cette version pose les fondations mécaniques et logicielles du robot avant l’intégration de capteurs avancés et d’intelligence artificielle.

L’objectif principal de TONY V0 est de maîtriser les bases du contrôle moteur, de la communication série et du feedback utilisateur, dans une approche simple, robuste et pédagogique.

🎯 Objectifs du projet

Comprendre le pilotage d’un robot différentiel (2 moteurs DC)

Utiliser un driver L298N

Implémenter un contrôle via le moniteur série

Ajouter un retour visuel et sonore (LED + buzzer)

Préparer l’évolution vers des versions plus avancées (ESP32, capteurs, IA)

🧩 Composants utilisés

Arduino Uno / Nano

Driver moteur L298N

2 moteurs DC (châssis 2WD)

1 LED (feedback visuel)

1 buzzer actif (feedback sonore)

Alimentation externe (batterie)

Câbles Dupont

⚙️ Fonctionnement général

Le robot est contrôlé via le moniteur série Arduino.
Chaque commande envoyée déclenche :

une action moteur

un feedback LED + bip sonore si la commande change

La vitesse des moteurs est contrôlée par PWM.

🎮 Commandes disponibles (Moniteur Série)
Commande	Action
a	Avancer
r	Reculer
g	Rotation courte à gauche
d	Rotation courte à droite
G	Tour complet à gauche (≈360°)
D	Tour complet à droite (≈360°)
q	Quart de tour à gauche (≈90°)
e	Quart de tour à droite (≈90°)
s	Stop
💡 Feedback utilisateur

À chaque nouvelle commande différente :

✅ La LED s’allume brièvement

🔊 Le buzzer émet un bip court

Cela permet de confirmer visuellement et auditivement que le robot a bien reçu l’ordre.

🧠 Architecture logicielle

Structure modulaire (fonctions dédiées par mouvement)

Séparation claire :

moteurs

feedback

logique de commande

Mémoire de la dernière commande pour éviter les feedbacks inutiles

🚀 Évolutions prévues

Passage vers ESP32

Contrôle via Bluetooth / Wi-Fi

Ajout de capteurs ultrasoniques

Écran OLED pour expressions

Intégration d’une IA embarquée / hybride

Connexion avec l’assistant TONY (web & mobile)

🏷️ Auteur

Toko_Clb Lab - https://calebtoko.com/entreprise.html

📍 Kinshasa – RDC 🇨🇩

Build and Invest in Yourself.
