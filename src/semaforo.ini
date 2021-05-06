#define LED_VERM1 4
#define LED_VERD1 2
#define LED_AMA1 3
#define LED_VERM2 5
#define LED_VERD2 7
#define LED_AMA2 6
#define RGB_VERDE1 10
#define RGB_VERM1 9
#define RGB_VERDE2 11
#define RGB_VERM2 12

int buttonPin1 = 8;
int buttonPin2 = 13;

void RGBVerde(){
  digitalWrite(RGB_VERDE1, HIGH);
  digitalWrite(RGB_VERM1, LOW);
  digitalWrite(RGB_VERDE2, LOW);
  digitalWrite(RGB_VERM2, LOW);
}

void RGBVermelho(){
  digitalWrite(RGB_VERM1, HIGH);
  digitalWrite(RGB_VERDE1, LOW);
  digitalWrite(RGB_VERM2, LOW);
}

void RGBVerde2(){
  digitalWrite(RGB_VERDE2, HIGH);
  digitalWrite(RGB_VERM1, LOW);
  digitalWrite(RGB_VERDE1, LOW);
  digitalWrite(RGB_VERM2, LOW);
}

void RGBVermelho2(){
  digitalWrite(RGB_VERM2, HIGH);
  digitalWrite(RGB_VERDE2, LOW);
  digitalWrite(RGB_VERM1, LOW);
}

void acionaBotao1() {
  digitalWrite(LED_VERD1, LOW);
  digitalWrite(LED_AMA1, HIGH);
  delay(2000);
  digitalWrite(LED_AMA1, LOW);
  digitalWrite(LED_VERM1, HIGH);
  digitalWrite(LED_VERD2, HIGH);
  RGBVerde();
  delay(2000);
}

void setup(){
  pinMode(LED_VERM1, OUTPUT);
  pinMode(LED_VERD1, OUTPUT);
  pinMode(LED_AMA1, OUTPUT);
  pinMode(LED_VERM2, OUTPUT);
  pinMode(LED_VERD2, OUTPUT);
  pinMode(RGB_VERDE1, OUTPUT);
  pinMode(RGB_VERM1, OUTPUT);
  pinMode(RGB_VERDE2, OUTPUT);
  pinMode(RGB_VERM2, OUTPUT);
  pinMode(LED_AMA2, OUTPUT);
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  
  // Define o estado inicial das luzes antes do acionamento dos botoes
  digitalWrite(LED_VERD1, HIGH);
  digitalWrite(LED_VERM2, HIGH);
}

void loop(){ 
  if(digitalRead(buttonPin1) == LOW){
    acionaBotao1();
  }
}
