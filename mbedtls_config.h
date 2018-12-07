#ifndef MBEDTLS_THREAD_CONFIG_H_
#define MBEDTLS_THREAD_CONFIG_H_

/* mbed TLS feature support */
#define MBEDTLS_ECP_DP_SECP256R1_ENABLED
#define MBEDTLS_ECP_NIST_OPTIM
#define MBEDTLS_KEY_EXCHANGE_ECJPAKE_ENABLED

#define MBEDTLS_SSL_MAX_FRAGMENT_LENGTH
#define MBEDTLS_SSL_PROTO_TLS1_2
#define MBEDTLS_SSL_PROTO_DTLS
#define MBEDTLS_SSL_DTLS_ANTI_REPLAY
#define MBEDTLS_SSL_DTLS_HELLO_VERIFY
#define MBEDTLS_SSL_EXPORT_KEYS
#define MBEDTLS_SSL_ALL_ALERT_MESSAGES

#define MBEDTLS_ENTROPY_MAX_SOURCES 4   // save 320 bytes of RAM (default is 20 entropy source)
#define MBEDTLS_SSL_MAX_CONTENT_LEN 4096 // Use 4kB buffers for input and output instead of 16kB


#define MBEDTLS_SHA256_SMALLER //reduce ROM usage ~1,4kB, perf hit 30%

/* mbed TLS modules */
#define MBEDTLS_AES_C
#define MBEDTLS_BIGNUM_C
#define MBEDTLS_CCM_C
#define MBEDTLS_CIPHER_C
#define MBEDTLS_CTR_DRBG_C
#define MBEDTLS_ECJPAKE_C
#define MBEDTLS_ECP_C
#define MBEDTLS_MD_C
#define MBEDTLS_OID_C
#define MBEDTLS_PK_C
#define MBEDTLS_SHA256_C
#define MBEDTLS_SSL_COOKIE_C
#define MBEDTLS_SSL_CLI_C
#define MBEDTLS_SSL_TLS_C

/* Save RAM at the expense of ROM */
#define MBEDTLS_AES_ROM_TABLES

/* Save RAM by adjusting to our exact needs */
#define MBEDTLS_ECP_MAX_BITS             256
#define MBEDTLS_MPI_MAX_SIZE              32 // 256 bits is 32 bytes

/* Save ROM and a few bytes of RAM by specifying our own ciphersuite list */
#define MBEDTLS_SSL_CIPHERSUITES MBEDTLS_TLS_ECJPAKE_WITH_AES_128_CCM_8

/* Optimization. Remove all not needed stuff */
/* For type TYPE_THREAD_SLEEPY_END_DEVICE
#undef MBEDTLS_X509_USE_C
#undef MBEDTLS_X509_CRT_PARSE_C
#undef MBEDTLS_ASN1_PARSE_C
#undef MBEDTLS_ASN1_WRITE_C
#undef MBEDTLS_ECDH_C
#undef MBEDTLS_PK_PARSE_C
#undef MBEDTLS_PK_WRITE_C
#undef MBEDTLS_KEY_EXCHANGE_PSK_ENABLED
#undef MBEDTLS_KEY_EXCHANGE_ECDHE_PSK_ENABLED
#undef MBEDTLS_X509_CREATE_C
#undef MBEDTLS_X509_CRT_WRITE_C
#undef MBEDTLS_SSL_SRV_C
*/

/* For TYPE_THREAD_BORDER_ROUTER */
#define MBEDTLS_X509_USE_C
#define MBEDTLS_X509_CRT_PARSE_C
#define MBEDTLS_ASN1_PARSE_C
#define MBEDTLS_ASN1_WRITE_C
#define MBEDTLS_ECDH_C
#define MBEDTLS_HMAC_DRBG_C
#define MBEDTLS_PK_PARSE_C
#define MBEDTLS_PK_WRITE_C
#define MBEDTLS_KEY_EXCHANGE_PSK_ENABLED
#define MBEDTLS_KEY_EXCHANGE_ECDHE_PSK_ENABLED
#define MBEDTLS_X509_CREATE_C
#define MBEDTLS_X509_CRT_WRITE_C
#define MBEDTLS_SSL_SRV_C

#undef MBEDTLS_X509_CRL_PARSE_C
#undef MBEDTLS_SSL_SERVER_NAME_INDICATION
#undef MBEDTLS_SELF_TEST
#undef MBEDTLS_SSL_ENCRYPT_THEN_MAC
#undef MBEDTLS_SSL_EXTENDED_MASTER_SECRET
#undef MBEDTLS_BASE64_C
#undef MBEDTLS_DEBUG_C
#undef MBEDTLS_ECDSA_C
#undef MBEDTLS_ERROR_C
#undef MBEDTLS_GCM_C
#undef MBEDTLS_PEM_PARSE_C
#undef MBEDTLS_RSA_C
#undef MBEDTLS_VERSION_C
#undef MBEDTLS_CERTS_C
#undef MBEDTLS_HMAC_DRBG_C
#undef MBEDTLS_CIPHER_MODE_CBC
#undef MBEDTLS_CIPHER_PADDING_PKCS7
#undef MBEDTLS_ECDSA_DETERMINISTIC
#undef MBEDTLS_SSL_SESSION_TICKETS
#undef MBEDTLS_VERSION_FEATURES
#undef MBEDTLS_X509_CHECK_KEY_USAGE
#undef MBEDTLS_X509_CHECK_EXTENDED_KEY_USAGE
#undef MBEDTLS_ERROR_STRERROR_DUMMY
#undef MBEDTLS_SSL_ALPN
#undef MBEDTLS_SSL_TICKET_C
#undef MBEDTLS_HAVE_SSE2
#undef MBEDTLS_PLATFORM_MEMORY
#undef MBEDTLS_PLATFORM_NO_STD_FUNCTIONS
#undef MBEDTLS_DEPRECATED_WARNING
#undef MBEDTLS_DEPRECATED_REMOVED
#undef MBEDTLS_CAMELLIA_SMALL_MEMORY
#undef MBEDTLS_CIPHER_MODE_CFB
#define MBEDTLS_CIPHER_MODE_CTR
#undef MBEDTLS_CIPHER_NULL_CIPHER
#undef MBEDTLS_CIPHER_PADDING_ONE_AND_ZEROS
#undef MBEDTLS_CIPHER_PADDING_ZEROS_AND_LEN
#undef MBEDTLS_CIPHER_PADDING_ZEROS
#undef MBEDTLS_ENABLE_WEAK_CIPHERSUITES
#define MBEDTLS_REMOVE_ARC4_CIPHERSUITES
#undef MBEDTLS_ECP_DP_CURVE25519_ENABLED
#undef MBEDTLS_KEY_EXCHANGE_DHE_PSK_ENABLED
#undef MBEDTLS_KEY_EXCHANGE_RSA_PSK_ENABLED
#undef MBEDTLS_KEY_EXCHANGE_RSA_ENABLED
#undef MBEDTLS_KEY_EXCHANGE_DHE_RSA_ENABLED
#undef MBEDTLS_KEY_EXCHANGE_ECDHE_RSA_ENABLED
#undef MBEDTLS_KEY_EXCHANGE_ECDHE_ECDSA_ENABLED
#undef MBEDTLS_KEY_EXCHANGE_ECDH_ECDSA_ENABLED
#undef MBEDTLS_KEY_EXCHANGE_ECDH_RSA_ENABLED
#undef MBEDTLS_PK_PARSE_EC_EXTENDED
#undef MBEDTLS_GENPRIME
#undef MBEDTLS_NO_DEFAULT_ENTROPY_SOURCES
#undef MBEDTLS_MEMORY_DEBUG
#undef MBEDTLS_MEMORY_BACKTRACE
#undef MBEDTLS_PK_RSA_ALT_SUPPORT
#undef MBEDTLS_PKCS1_V15
#undef MBEDTLS_PKCS1_V21
#undef MBEDTLS_RSA_NO_CRT
#undef MBEDTLS_SSL_AEAD_RANDOM_IV
#undef MBEDTLS_RSA_NO_CRT
#undef MBEDTLS_SSL_DEBUG_ALL
#undef MBEDTLS_SSL_FALLBACK_SCSV
#undef MBEDTLS_SSL_HW_RECORD_ACCEL
#undef MBEDTLS_SSL_CBC_RECORD_SPLITTING
#undef MBEDTLS_SSL_RENEGOTIATION
#undef MBEDTLS_SSL_SRV_SUPPORT_SSLV2_CLIENT_HELLO
#undef MBEDTLS_SSL_SRV_RESPECT_CLIENT_PREFERENCE
#undef MBEDTLS_SSL_PROTO_TLS1
#undef MBEDTLS_SSL_PROTO_TLS1_1
#undef MBEDTLS_SSL_DTLS_BADMAC_LIMIT
#undef MBEDTLS_SSL_TRUNCATED_HMAC
#undef MBEDTLS_THREADING_ALT
#undef MBEDTLS_THREADING_PTHREAD
#undef MBEDTLS_X509_ALLOW_EXTENSIONS_NON_V3
#undef MBEDTLS_X509_ALLOW_UNSUPPORTED_CRITICAL_EXTENSION
#undef MBEDTLS_X509_RSASSA_PSS_SUPPORT
#undef MBEDTLS_ZLIB_SUPPORT
#undef MBEDTLS_AESNI_C
#undef MBEDTLS_ARC4_C
#undef MBEDTLS_BLOWFISH_C
#undef MBEDTLS_CAMELLIA_C
#undef MBEDTLS_DES_C
#undef MBEDTLS_DHM_C
#undef MBEDTLS_HAVEGE_C
#undef MBEDTLS_MD2_C
#undef MBEDTLS_MD4_C
#undef MBEDTLS_MD5_C
#undef MBEDTLS_MEMORY_BUFFER_ALLOC_C
#undef MBEDTLS_PADLOCK_C
#undef MBEDTLS_PEM_WRITE_C
#undef MBEDTLS_PKCS5_C
#undef MBEDTLS_PKCS11_C
#undef MBEDTLS_PKCS12_C
#undef MBEDTLS_PLATFORM_C
#undef MBEDTLS_RIPEMD160_C
#undef MBEDTLS_SHA1_C
#undef MBEDTLS_SHA512_C
#undef MBEDTLS_SSL_CACHE_C
#undef MBEDTLS_THREADING_C
#undef MBEDTLS_X509_CSR_PARSE_C
#undef MBEDTLS_X509_CSR_WRITE_C
#undef MBEDTLS_XTEA_C


#include "mbedtls/check_config.h"

#endif /* MBEDTLS_CONFIG_H */
