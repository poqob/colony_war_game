# colony war game

Oyunu kendi parametreleriniz ile çalıştırabilmek için makefile içerisindeki run bölümünü dilediğiniz şekilde değiştirin.

örnek
makefile, run:
./bin/Main 127 54 49 47 67 211 300 177






Rapordaki "d. manufacture" ve "e. strategy" kısımlarına detaylıca değinmek istiyorum. 

her koloni yaratılırken rastgele olacak şekilde strateji ve manüfaktüre sınıflarından üyelere sahip olurlar.
bu rastgele seçilme işlemi src/colony/Colony.c dosyasında pickStrategy(), pickManufacture() fonksiyonları içerisinde
gerçeklenmektedir. 

her koloninin strateji ve manufakture alanları tipi void*'dır. Bu  koloni yaratımınındaki strateji ve üretim(manufacture)
alanlarının derleme anında değil de yürütme anında gerçekleşmesinden doğan tip belirsizliğinden kaynaklanmaktadır.
Tip belirsizliği olan bir alanın içine erişim imkanım olmadığından dolayı yaratım esnasında hangi üretim(manufacture) sınıfı 
ve strateji sınıfı parametre olarak koloniye atandı bunun bilgisini sakladım. daha sonra strateji ve üretim(manufacture) alanlarının
içindeki "produce()" ve "fight()" metotlarına rahatlıkla erişebildim. Hangi strateji ve üretim sınfının atandığını strateji için; 
include/strategy/Strategies.h, src/strategy/Strategies.c üretim için ise;  include/manufacture/Manufactures.h, src/manufacture/Manufactures.c
dosyalarındaki enum veri tipleri ile yaptım. Her koloni strateji ve üretim sınıfına sahip olduğu gibi yukarıdaki her iki enumdan örneklere de sahiptir.
bu örneklerdeki strateji ve üretim tipine göre void* tipindeki alanlara cast yöntemiyle enum değişkenleri baz alınarak çevrildikten sonra erişilmektedir.

2 Rapor, girdiler kısmı:
programa yapılacak girdiler sayı girişleridir make file içinde run kısmından yapılmaktadır. 
hatalı girişler program tarafından sıfır değeri olarak değerlendirilir.  
-örnek-
makefile, run:
./bin/Main 127 54 49 47 67 211 300 177

3 Çıktılar: 
Bu bir oyun bu oyunun insanlığa bir yararı olacağını düşünmüyorum ancak programcıya c dilinin mantığını doğru yöntemle işiaretçi kullanımını program hayatı 
boyunca bellekteki durumunu yönetmeyi bunlarla birlikte nesneye dayalı programlamanın nasıl doğmuş olabileceğinin fikri benzetimi sayesinde öğrenilmiştir.
