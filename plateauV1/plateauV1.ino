#include "plateauV1.h"

//=== CONSTANTES ===
#define encodeuseGaucheAvant 13 //encodeur gauche A
#define encodeuseDroiteAvant 11 //encodeur droit A
#define pinTrigger 31 // pin du capteur Trigger
// === Variable ===
CDF_plateau plateau(pinTrigger);

void setup() {
	Serial.begin(115200);
 	plateau.asservisement = CDF_asservisement(13,12,11,10,6,3,22,23,52,53);// regarde le README.md
 	attachInterrupt(digitalPinToInterrupt(encodeuseGaucheAvant), [&](){plateau.asservisement.compteur_tick_L();}, RISING);
 	attachInterrupt(digitalPinToInterrupt(encodeuseDroiteAvant), [&](){plateau.asservisement.compteur_tick_R();}, RISING);
	// Le roboot attent le signal..
	plateau.Trigger();
	// le roboot se rend au point..
	plateau.parcours(2,0);
	plateau.parcours(0,0);
	plateau.parcours(2,0);
	plateau.parcours(0,0);
}

void loop() {
}
