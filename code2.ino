
#define Echo 7 // Echo回声脚
#define Trig 6 //  Trig 触发脚
int Front_Distance = 0;//

#define BREZZE 3
#define LEDY 4
#define motor 9
#define switch_in 10
//const int dis_bound=
unsigned long timer1 = 0;
unsigned long timer2 = 0;
bool flag1=true;
bool flag2=true;
bool flag3=true;
bool flag4=true;
bool flag5=true;

bool flag6=true;
bool ismotro=false;
void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);  // start serial for output
  pinMode(Echo, INPUT);    
  pinMode(Trig, OUTPUT);   
  pinMode(BREZZE,OUTPUT);
  pinMode(LEDY,OUTPUT);
  pinMode(motor,OUTPUT);
  pinMode(8,INPUT);
  pinMode(switch_in,INPUT);
  timer1 = millis();
}

void loop() {
  if (digitalRead(switch_in)==LOW){
  flag6=true;
}
  if (digitalRead(switch_in)==HIGH && flag6){
  flag6=false;
  ismotro=!ismotro;
}
Front_Distance = 10*Distance_test();
 Serial.println(ismotro);
if (digitalRead(8)==HIGH){
  digitalWrite(LEDY,LOW);
 
}else{
if ((Front_Distance > 800 && Front_Distance < 1000) && flag1)
{
flag1=false;
if (ismotro){
  tone(BREZZE,850);
}else{
  digitalWrite(motor,HIGH);
}

digitalWrite(LEDY,HIGH);
timer1 = millis();
}
else if ((Front_Distance > 600 && Front_Distance < 800) && flag2)
{     
flag2=false;
if (ismotro){
  tone(BREZZE,850);
}else{
  digitalWrite(motor,HIGH);
}
digitalWrite(LEDY,HIGH);
timer1 = millis();
}
else if ((Front_Distance > 400 && Front_Distance < 600) && flag3)
{
flag3=false;
if (ismotro){
  tone(BREZZE,850);
}else{
  digitalWrite(motor,HIGH);
}
digitalWrite(LEDY,HIGH);
timer1 = millis();
}else if ( Front_Distance < 400 && flag4)
{
flag4=false;
if (ismotro){
  tone(BREZZE,850);
}else{
  digitalWrite(motor,HIGH);
}
digitalWrite(LEDY,HIGH);
timer1 = millis();
timer2=millis();
}
if (!flag1){
if ((millis()-timer1) >1000){
noTone(BREZZE); 
digitalWrite(LEDY,LOW);
digitalWrite(motor,LOW);
flag1=true;
}
}
if (!flag2){
if ((millis()-timer1) >500){
noTone(BREZZE); 
digitalWrite(LEDY,LOW);
digitalWrite(motor,LOW);
flag2=true;
}
}
if (!flag3){
if ((millis()-timer1) >200){
noTone(BREZZE); 
digitalWrite(LEDY,LOW);
digitalWrite(motor,LOW);
flag3=true;
}

}
if (!flag4){
if ((millis()-timer1) >50){
noTone(BREZZE); 
digitalWrite(LEDY,LOW);
digitalWrite(motor,LOW);
flag4=true;
}

}
}
delay(100);
}

float Distance_test()   // Measure distance 
{
  digitalWrite(Trig, LOW);   // 给触发脚低电平2μs
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);  // 给触发脚高电平10μs，这里至少是10μs
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);    // 持续给触发脚低电
  float Fdistance = pulseIn(Echo, HIGH);  // 读取高电平时间(单位：微秒)
  Fdistance= Fdistance/58;       //为什么除以58等于厘米，  Y米=（X秒*344）/2
  // X秒=（ 2*Y米）/344 ==》X秒=0.0058*Y米 ==》厘米=微秒/58
  Serial.print("Distance:");      //distan（cm）
  Serial.println(Fdistance);         //Show the distance
  //Distance = Fdistance;
  return Fdistance;
}  
