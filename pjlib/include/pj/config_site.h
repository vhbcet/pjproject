/* Android'e özgü ayarları 'config_site_sample.h' içinde etkinleştir */
#define PJ_CONFIG_ANDROID 1

/* Özelliklerin etkinleştirilmesi için tanımlamalar */
#define PJ_HAS_VIDEO             1 // Video görüşmeleri etkinleştir
#define PJ_HAS_MESSAGING        1 // Mesajlaşma özelliğini etkinleştir (varsayılan olarak devre dışı, çünkü PJSIP doğrudan mesajlaşma protokolü içermez)


#include <pj/config_site_sample.h>

/* Video için gerekli ek başlık dosyaları */
#ifdef PJ_HAS_VIDEO
#   include <pjmedia/video_dev.h>
#endif


/* Koşullu derleme ile özelliklere göre optimizasyonlar */
#if PJ_HAS_VIDEO && PJ_HAS_MESSAGING
    // Hem video hem de mesajlaşma etkinleştirildiğinde yapılacak ayarlar
    #define PJSUA_DEFAULT_CODEC_QUALITY         5 // Daha yüksek kalite, daha fazla kaynak kullanımı
    #define PJSIP_MAX_PKT_LEN                   2048 // Paket boyutunu artır
#elif PJ_HAS_VIDEO
    // Sadece video etkinleştirildiğinde yapılacak ayarlar
    #define PJSUA_DEFAULT_CODEC_QUALITY         4 // Orta kalite
     #define PJSIP_MAX_PKT_LEN                   1536 // Paket boyutunu biraz artır
#elif PJ_HAS_MESSAGING
    // Sadece mesajlaşma etkinleştirildiğinde yapılacak ayarlar
    #define PJSUA_DEFAULT_CODEC_QUALITY         3 // Daha düşük kalite, daha az kaynak kullanımı
    #define PJSIP_MAX_PKT_LEN                   1024 // Varsayılan paket boyutu
#else
    // Varsayılan ayarlar (video ve mesajlaşma devre dışı)
    #define PJSUA_DEFAULT_CODEC_QUALITY         4 // Orta kalite
	#define PJSIP_MAX_PKT_LEN                   1024 // Varsayılan paket boyutu
#endif

// Ağ ayarları
#define PJSIP_UDP_SO_SNDBUF_SIZE     8192 // Giden UDP paketi arabelleği boyutunu artır
#define PJSIP_UDP_SO_RCVBUF_SIZE     8192 // Gelen UDP paketi arabelleği boyutunu artır


/* Ses kodek ayarları (isteğe bağlı) */
#define PJMEDIA_HAS_ILBC_CODEC              1  //iLBC kodeğini etkinleştir
#define PJMEDIA_HAS_G729_CODEC              1  //G729 kodeğini etkinleştir
// Diğer kodekleri etkinleştirmek veya devre dışı bırakmak için buraya eklemeler yapabilirsiniz


/* Diğer performans optimizasyonları (isteğe bağlı) */
// #define PJSUA_SEPARATE_WORKER_FOR_TIMER  1 // Zamanlayıcı için ayrı bir iş parçacığı


/*  Mesajlaşma için 3. parti kütüphane entegrasyonu (gerekirse)  */
// #define PJ_USE_XMPP 1 //  Örnek: XMPP kullanılacaksa tanımlayın.  
// XMPP veya başka bir mesajlaşma protokolü kullanacaksanız,
// ilgili başlık dosyalarını eklemeniz ve gerekli ayarları yapmanız gerekecektir.
// Bu, PJSIP'nin kapsamı dışındadır ve ek kütüphaneler gerektirir.