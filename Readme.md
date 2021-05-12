## Sistem Programlama Dersi Proje Ödevi

Proje kapsamında program verilen kitit dosyasındaki anahtarlara göre giriş dosyasını kriptolayabilecek ve kriptolanmış metni eski haline dönüştürebilecektir. Sonuçta ortaya çıkan metni ise çıkış dosyasına yazdıracaktır. Kütüphane olarak libfdr kütüphanesi kullanılacak ve C dilinde gerçeklenecektir. Program linux ortamında çalıştırılmalıdır.

### Proje Ekibi

- Kader Miyanyedi (B191210380) @Kadermiyanyedi
- Özge Çinko (G181210084) @ozgecinko
- Arif Emir Aslantürk (G191210371) @arifemir
- Şerife Gönüllü (B191210089) @serifegnll

### Makefile dosyasının yapısı

- **all**: Sırası ile cleanoutputfile, make, run, clean komutlarını çalıştırır.
- **make**: Projede yer alan .c dosyalarını derler ve kripto isimli çalıştırılabilir dosyayı üretir.
- **run**: Eski output dosyalarını silecek komutu çağırır. Aşağıdaki komutları sırası ile çalıştırır.
  kripto -e input.txt output.txt
  kripto -d output.txt output2.txt
- **clean**: Tüm .o dosyalarını siler.
- **cleanall**: Tüm .o, .txt dosyalarını, kilit dosyasını ve çalıştırılabilir kripto dosyasını siler.
- **cleanoutputfile**: output.txt ve output2.txt dosyalarını siler.

### Kullanım

Proje klasörü içerisinde `make` komutunu çalıştırınız.
