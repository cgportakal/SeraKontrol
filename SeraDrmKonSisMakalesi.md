# SeraKontrol
# Arduino ile Sera Kontrol Sistemi veya Sera Durum Kontrol Sistemi
Bu Proje Erciyes Üniversitesi Elektronik Devreler dersinde yapmış olduğum projedir. Proje raporu sayfada paylaşılmıştır. Geliştiricilerin yararına olmasını dilerim.

Özet
Günümüz dünyasında çok fazla yer almaya başlayan otonom sistemlerin bir örneği olan sera projemizde, arduino geliştirme kartı kullanarak geliştirilmiştir. Proje sensörlerden oluşmaktadır. Kullanıcı sensörlerden okunan değerleri izleyebilmektedir. DHT11 sensörü ile ortam sıcaklığını ve nemini, toprak nem sensörü ile toprak nemini, yağmur sensörü ile havanın yağışlı olup olmadığını, LDR ile havanın aydınlık olup olmadığını ölçüp bu bilgileri üzerinde barındırdığı ledlere, LCD ekranda ve telefon uygulamasına bluetooth ile bildirebilmektedir. Kullanıcıya ölçümlere göre öneri vererek seranın gelişimini anlık olarak takip edilebilmesini sağlamakla birlikte serada yetiştirilen bitkilerin stres, hastalık ve diğer kötü etkenlere en az derecede maruz kalmasına yardımcı olabilmektedir. Kullanıcılar isterlerse yapılan bu projeyi kendi ihtiyaçları doğrultusunda değiştirebilmekte ekleme veya çıkarmalar yapabilmektedir.


Kullanılan Malzeme ve Yöntemler
Projede kullanılan elemanlar kullanım örnekleri aşağıda zikredilecektir. Projemiz bilindiği üzere sera sistemlerindeki kontrolü sağlamak amacıyla oluşturulmuştur. Bu kapsamda sıcaklık ve nem sensörü olan DHT11 ile alınan veriler, toprağa batırılarak kullanılan toprak nem sensörü, iletim değişimine göre çalışan yağmur sensörü, ışık değişimi ile direnci değişen ve bu şekilde kullanılan LDR ışık sensörü ortamdan alınan verilere göre kullanıcıyı Led, LCD ve Bluetooth ile iletişim sağlayarak Android telefon ve tabletlerde uygulama üzerinden bilgilendirmektedir.


Tasarım ve Uygulama
Sera kontrol uygulaması kapsamında yapılan maketin fotoğrafı aşağıdaki gibidir. Bu maket hazırlanırken aktif olarak kullanılan 8lt’lik bir adet saksı, 2 adet 10lt’lik su şişesi, Arduino geliştirme kartı, gerekli modüller ve saksıya tutturmak için raptiyeler kullanılmıştır. Seranın üst kısmı tasarlanırken 2 adet şişeden 45 derecelik yan parça çıkarılmış ve sera üzerine monte edilebilmiştir. Yağmur sensörü kesilen şişelerin üzerine raptiyeler ile tutturulmuştur. Saksının yan tarafına yan yana gelecek biçimde arduino geliştirme kartı ve breadbord yerleştirilmiştir. Arduino’yu besleyecek olan güç kaynağı da saksının yan tarafına tutturulmuştur. 


Sonuç
Sera kontrol sisteminde karşılaştığımız sorunlari listelemek gerekirse Arduino Uno’dan başlamamız gerekir. Arduino’daki pinler projemize eklemek istediğimiz su motoru, fan, step motor, buzzer gibi aygıtlar için yetersiz kaldı. Fan motoru bağlantısını gerçekleştirirken transistör ile yaşadığımız sıkıntıyı halen çözememiş bulunmaktayız bu sebeple fan takma işlemini iptal etmek zorunda kaldık. Projeye başlarken elimizde tam bir kaynak bulunmaması da bazı şeyleri dene öğren yöntemi ile öğrenmemize sebep oldu ve bu da bize vakit kaybıyla geri döndü. Sera sisteminde su kullanıldığı için elektronik akşamları sudan korumak gerekiyordu yanlışlıkla ıslanmaları bizim için büyük sorun teşkil ederdi. Bu sebeple elektronik aygıtların dış kısmına sıvıdan koruyucu bir kit yerleştirilebilirdi. Arduino devresini tasarlarken Fritzing uygulamasını kullanmak istedik fakat beta sürüm olduğundan dolayı açarken veya bir işlem yaparken kitlenip kapanıyordu. Bu sebeple sistemin bütünsel olarak bir devre çizimini yapamadık. Bunun yerine her sensörü ayrı ayrı çizmek zorunda kaldık. Bu sistemin maket boyutlarındaki halinde verimli bir kullanım elde ettik. Bunu daha büyük sistemlerde gerçek sera ortamlarında deneyimlemek üzere çalışmalar yürütmek için planlarımızı oluşturmaya başlamış bulunmaktayız.

Gün geçtikçe tarım sektöründe şirketleşmeler ve yatırımlar artmakta olduğu için bundan sonra yapılacak projelerin sayısının artacağı ve yapılacak olan projelere kaynaklık edeceği görüşündeyiz.

