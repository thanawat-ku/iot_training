//ลงทะเบียนขอรหัส token ที่ https://notify-bot.line.me/my/

#include <WiFi.h> // นำเข้าไลบรารี่ WiFi
#include <ArtronShop_LineNotify.h> // นำเข้าไลบารี่ ArtronShop_LineNotify

const char* ssid = "WiFi Name"; // ชื่อ WiFi
const char* password = "WiFi Password"; // รหัสผ่าน WiFi
#define LINE_TOKEN "LINE Token" // LINE Token

void setup() {
  Serial.begin(115200); // เริ่มต้นใช้ Serial ที่ความเร็ว 115200
  while (!Serial) { delay(100); }

  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println("******************************************************");
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password); // เริ่มต้นเชื่อมต่อ WiFi

  while (WiFi.status() != WL_CONNECTED) { // วนลูปหากยังเชื่อมต่อ WiFi ไม่สำเร็จ
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  LINE.begin(LINE_TOKEN); // เริ่มต้นใช้ LINE Notify

  if (LINE.send("รถโดนขโมย")) {  // ถ้าส่งข้อความ "รถโดนขโมย" ไปที่ LINE สำเร็จ
    Serial.println("Send notify successful"); // ส่งข้อความ "Send notify successful" ไปที่ Serial Monitor
  } else { // ถ้าส่งไม่สำเร็จ
    Serial.printf("Send notify fail. check your token (code: %d)\n", LINE.status_code); // ส่งข้อความ "Send notify fail" ไปที่ Serial Monitor
  }
}

void loop() {

}
}
