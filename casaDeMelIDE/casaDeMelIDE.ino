#include <Arduino.h>

#include <WiFi.h>
#include <Firebase_ESP_Client.h>
#include <addons/TokenHelper.h>
#include <addons/RTDBHelper.h>

const char* WIFI_SSID = "Celerity_LFAJARDO_2.4";
const char* WIFI_PASSWORD= "LUFACO8520";


const char* API_KEY= "AIzaSyBx2_zDjXkMcPilnnMnxrvfMllufHPICTo";

const char* DATABASE_URL= "https://realtime-34175-default-rtdb.firebaseio.com/"; //<databaseName>.firebaseio.com or <databaseName>.<region>.firebasedatabase.app;

const char* USER_EMAIL= "pintado27@gmail.com";
const char* USER_PASSWORD= "1234567";


FirebaseData fbdo;

FirebaseAuth auth;
FirebaseConfig config;

unsigned long sendDataPrevMillis = 0;

unsigned long count = 0;

const int BUTTON =15;
const int BUTTON2 =23;
const int BUTTON3 =22;
const int BUTTON4 =21;
const int BUTTON5 =19;
const int BUTTON6=18;

int buttonState = 0;


void setup_WIFI(){
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  unsigned long ms = millis();
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();
}

void setupFirebase() {
  config.api_key = API_KEY;
  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;
  config.database_url = DATABASE_URL;
  config.token_status_callback = tokenStatusCallback; // see addons/TokenHelper.h
  config.signer.tokens.legacy_token = "<database secret>";
  Firebase.reconnectNetwork(true);
  fbdo.setBSSLBufferSize(4096, 1024);
  fbdo.setResponseSize(2048);
  Firebase.begin(&config, &auth);
  Firebase.setDoubleDigits(5);
  config.timeout.serverResponse = 10 * 1000;
  Serial.printf("Firebase Client v%s\n\n", FIREBASE_CLIENT_VERSION);

}

void setup() {
    Serial.begin(115200);
    setup_WIFI();
    setupFirebase();
    pinMode(BUTTON,INPUT);
}

void loop() {

  if (Firebase.ready() && (boolean() - sendDataPrevMillis > 15000 || sendDataPrevMillis == 0))
  {
      buttonState = digitalRead(BUTTON);

    //Serial.printf("Get int... %s\n", Firebase.RTDB.getInt(&fbdo, F("/sensor/a")) ? String(fbdo.to<int>()).c_str() : fbdo.errorReason().c_str());
    Serial.printf("Set int... %s\n", Firebase.RTDB.setInt(&fbdo, F("/Casa/cocina"), buttonState) ? "ok" : fbdo.errorReason().c_str());

  }
   if (Firebase.ready() && (millis() - sendDataPrevMillis > 15000 || sendDataPrevMillis == 0))
  {
      buttonState = digitalRead(BUTTON2);

    //Serial.printf("Get int... %s\n", Firebase.RTDB.getInt(&fbdo, F("/sensor/a")) ? String(fbdo.to<int>()).c_str() : fbdo.errorReason().c_str());
    Serial.printf("Set int... %s\n", Firebase.RTDB.setInt(&fbdo, F("/Casa/bano"), buttonState) ? "ok" : fbdo.errorReason().c_str());

  }
   if (Firebase.ready() && (millis() - sendDataPrevMillis > 15000 || sendDataPrevMillis == 0))
  {
      buttonState = digitalRead(BUTTON3);

    //Serial.printf("Get int... %s\n", Firebase.RTDB.getInt(&fbdo, F("/sensor/a")) ? String(fbdo.to<int>()).c_str() : fbdo.errorReason().c_str());
    Serial.printf("Set int... %s\n", Firebase.RTDB.setInt(&fbdo, F("/Casa/atico"), buttonState) ? "ok" : fbdo.errorReason().c_str());

  }
   if (Firebase.ready() && (millis() - sendDataPrevMillis > 15000 || sendDataPrevMillis == 0))
  {
      buttonState = digitalRead(BUTTON4);

    //Serial.printf("Get int... %s\n", Firebase.RTDB.getInt(&fbdo, F("/sensor/a")) ? String(fbdo.to<int>()).c_str() : fbdo.errorReason().c_str());
    Serial.printf("Set int... %s\n", Firebase.RTDB.setInt(&fbdo, F("/Casa/dormitorio"), buttonState) ? "ok" : fbdo.errorReason().c_str());

  }
   if (Firebase.ready() && (millis() - sendDataPrevMillis > 15000 || sendDataPrevMillis == 0))
  {
      buttonState = digitalRead(BUTTON5);

    //Serial.printf("Get int... %s\n", Firebase.RTDB.getInt(&fbdo, F("/sensor/a")) ? String(fbdo.to<int>()).c_str() : fbdo.errorReason().c_str());
    Serial.printf("Set int... %s\n", Firebase.RTDB.setInt(&fbdo, F("/Casa/lavanderia"), buttonState) ? "ok" : fbdo.errorReason().c_str());

  }
   if (Firebase.ready() && (millis() - sendDataPrevMillis > 15000 || sendDataPrevMillis == 0))
  {
      buttonState = digitalRead(BUTTON6);

    //Serial.printf("Get int... %s\n", Firebase.RTDB.getInt(&fbdo, F("/sensor/a")) ? String(fbdo.to<int>()).c_str() : fbdo.errorReason().c_str());
    Serial.printf("Set int... %s\n", Firebase.RTDB.setInt(&fbdo, F("/Casa/sala"), buttonState) ? "ok" : fbdo.errorReason().c_str());

  }

}