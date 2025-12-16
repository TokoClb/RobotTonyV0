// TONY V0 Robot simple avec L298N, LED et buzzer by Toko_Clb Lab
// Commandes via moniteur série :
// a=avancer, r=reculer, g=gauche court, d=droite court, s=stop
// G=tour complet gauche, D=tour complet droite
// q=quart de tour gauche, e=quart de tour droite

// Moteur gauche
const int IN1 = 8;
const int IN2 = 9;
const int ENA = 5;  // PWM

// Moteur droit
const int IN3 = 10;
const int IN4 = 11;
const int ENB = 6;  // PWM

// LED et buzzer
const int LED_PIN = 4;
const int BUZZER_PIN = 7;

// Variable pour mémoriser la dernière commande
char lastCmd = 's';  // au départ "stop"

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  Serial.begin(9600);
  Serial.println("Commandes: a=avancer, r=reculer, g=droite court, d=gauche court, s=stop, G/D=tour complet, q/e=quart de tour");
}

void avancer() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
}

void reculer() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
}

void gaucheCourt() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);  // moteur gauche arrière
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);  // moteur droit avant
  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
  delay(400);  // rotation courte
  stop();
}

void droiteCourt() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);  // moteur gauche avant
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);  // moteur droit arrière
  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
  delay(400);  // rotation courte
  stop();
}

void tourCompletGauche() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
  delay(1200);  // temps approximatif pour 360°
  stop();
}

void tourCompletDroite() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
  delay(1200);  // temps approximatif pour 360°
  stop();
}

void quartTourGauche() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
  delay(600);  // temps approximatif pour 90°
  stop();
}

void quartTourDroite() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
  delay(600);  // temps approximatif pour 90°
  stop();
}

void stop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}

// Fonction pour activer LED + buzzer brièvement
void feedback() {
  digitalWrite(LED_PIN, HIGH);
  tone(BUZZER_PIN, 1200, 150);  // bip court
  delay(150);
  digitalWrite(LED_PIN, LOW);
}

void loop() {
  if (Serial.available() > 0) {
    char cmd = Serial.read();

    // Si la commande est différente de la précédente → feedback
    if (cmd != lastCmd) {
      feedback();
      lastCmd = cmd;  // mise à jour
    }

    if (cmd == 'a') {
      reculer();
      Serial.println("Avancer");
    } else if (cmd == 'r') {
      avancer();
      Serial.println("Reculer");
    } else if (cmd == 'g') {
      droiteCourt();
      Serial.println("Tourner un peu à gauche");
    } else if (cmd == 'd') {
      gaucheCourt();
      Serial.println("Tourner un peu à droite");
    } else if (cmd == 'G') {
      tourCompletDroite();
      Serial.println("Tour complet gauche");
    } else if (cmd == 'D') {
      tourCompletGauche();
      Serial.println("Tour complet droite");
    } else if (cmd == 'q') {
      quartTourGauche();
      Serial.println("Quart de tour gauche");
    } else if (cmd == 'e') {
      quartTourDroite();
      Serial.println("Quart de tour droite");
    } else if (cmd == 's') {
      stop();
      Serial.println("Stop");
     }
  }
}  
   
