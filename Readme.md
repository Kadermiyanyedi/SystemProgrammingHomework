## Sistem Programlama Dersi Proje Ödevi

Proje kapsamında program verilen kitit dosyasındaki anahtarlara göre giriş dosyasını kriptolayabilecek ve kriptolanmış metni eski haline dönüştürebilecektir. Sonuçta ortaya çıkan metni ise çıkış dosyasına yazdıracaktır. Kütüphane olarak libfdr kütüphanesi kullanılacak ve C dilinde gerçeklenecektir. Program linux ortamında çalıştırılmalıdır. Proje içinde istenilen tüm görevler yerine getirilmiştir.

### Proje Ekibi

- Kader Miyanyedi (B191210380) @Kadermiyanyedi
- Özge Çinko (G181210084) @ozgecinko
- Arif Emir Aslantürk (G191210371) @arifemir
- Şerife Gönüllü (B191210089) @serifegnll

### Makefile dosyasının yapısı

- **run**: Sırası ile clean, make, kriptola komutlarını çalıştırır.
- **make**: Projede yer alan main.c dosyasını derler ve kripto isimli çalıştırılabilir dosyayı üretir.
- **kriptola**: Aşağıdaki komutları sırası ile çalıştırır.
  kripto -e input.txt output.txt
  kripto -d output.txt output2.txt
- **clean**: Derleme sırasında oluşan dosyaları temizler.
- **cleanall**: Tüm .o, .txt dosyalarını, kilit dosyasını ve çalıştırılabilir kripto dosyasını siler.

### Kullanım

Proje içerisinde libfdr.a derlenmiş kütüphanesinin bulunduğundan emin olunuz.
Proje klasörü içerisinde `make` komutunu çalıştırınız.
