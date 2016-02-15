// déclaration des broches pour la gestion des lignes et des colonnes
int colonne[] = {7,6,5,4,3,2,1}; // matrice de colonne
int ligne[] = {8,9,10,11,12};    // matrice de ligne
int vx = 1;
int vy = 1;
int x = 2;
int y = 5;

// sous routine d'intialisation des broches
void setup() {                
  // initialisation des sorties.
  for (int i= 0; i < 7; i++) pinMode(colonne[i], OUTPUT);
  for (int i= 0; i < 5; i++) pinMode(ligne[i], OUTPUT);
  //place tous les potentiels de colonne à 1  et les lignes à 0 pour eteindre tous les points
  for (int i= 0; i < 7; i++) digitalWrite(colonne[i], HIGH);
  for (int i= 0; i < 5; i++) digitalWrite(ligne[i], LOW);
}

void pixel(int i,int j,int temps) {
    digitalWrite(ligne[j],1);
    digitalWrite(colonne[i],0);
    delay (temps); 
    digitalWrite(ligne[j],0);
    digitalWrite(colonne[i],1); 
}

// programme principal:
void loop() {
  pixel(x,y,100);
  x = x+vx;
  y = y+vy;
  if (x >= 6)
  {
    x = 6;
    vx = -1;
  }
  if (x <= 0)
  {
    x = 0;
    vx = 1;
  }
  if (y >= 4)
  {
    y = 4;
    vy = -1;
  }
  if (y <= 0)
  {
    y = 0;
    vy = 1;
  }
}
