//deklarasi pin lampu utara
int um = 13;
int uk = 12;
int uh = 11;
//deklarasi pin lampu timur
int tm = 10;
int tk = 9;
int th = 8;
//deklarasi pin lampu selatan
int sm = 7;
int sk = 6;
int sh = 5;
//deklarasi pin lampu barat
int bm = 4;
int bk = 3;
int bh = 2;

void setup (){
  //set pin yang digunakan sebagai output
  for (int i = 2; i <= 13; i++) {
    pinMode(i, OUTPUT);
  }
  //tes pin dengan mode default
  modeDefault();
}

void loop(){
  aktifkanSimpang("utara");
  aktifkanSimpang("timur");
  aktifkanSimpang("selatan");
  aktifkanSimpang("barat");
}

void modeDefault(){
  //matikan semua lampu dan nyalakan semua lampu merah
  for (int i = 2; i <= 13; i++) {
    digitalWrite(i, LOW);
  }
  
  digitalWrite(um, HIGH);
  digitalWrite(tm, HIGH);
  digitalWrite(sm, HIGH);
  digitalWrite(bm, HIGH);
}

void aktifkanSimpang(String arah) {
  //variabel pin lampu tergantung arah yang menyala
  int merah, kuning, hijau;

  //percabangan untuk assign nomor pin sesuai arah
  if (arah == "utara") {
    merah = um; kuning = uk; hijau = uh;
  } 
  else if (arah == "timur") {
    merah = tm; kuning = tk; hijau = th;
  } 
  else if (arah == "selatan") {
    merah = sm; kuning = sk; hijau = sh;
  } 
  else if (arah == "barat") {
    merah = bm; kuning = bk; hijau = bh;
  }
  
  //nyalakan semua lampu merah selama dua detik
  modeDefault();
  delay(2000);

  //nyalakan lampu hijau selama lima detik
  digitalWrite(merah, LOW);
  digitalWrite(hijau, HIGH);
  delay(5000);
  digitalWrite(hijau, LOW);

  //kedip lampu kuning sebanyak tiga kali
  for (int i = 0; i < 3; i++) {
    digitalWrite(kuning, HIGH);
    delay(333);
    digitalWrite(kuning, LOW);
    delay(333);
  }
  //nyalakan lampu kuning selama dua detik
  digitalWrite(kuning, HIGH);
  delay(2000);
  digitalWrite(kuning, LOW);

  //nyalakan lampu merah
  digitalWrite(merah, HIGH);
}

