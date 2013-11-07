#ifndef __CurlWrap__h__included__
#define __CurlWrap__h__included__

#ifdef _WIN32
#include <windows.h>
#endif

/// resides in ExtLibs
#include "curl/curl.h"

/// Base API

typedef CURLFORMcode ( *curl_formadd_func )( struct curl_httppost** httppost, struct curl_httppost** last_post, ... );
typedef int ( *curl_formget_func )( struct curl_httppost* form, void* arg, curl_formget_callback append );
typedef void ( *curl_formfree_func )( struct curl_httppost* form );
typedef char* ( *curl_getenv_func )( const char* variable );
typedef char* ( *curl_version_func )( void );
typedef char* ( *curl_easy_escape_func )( CURL* handle, const char* string, int length );
typedef char* ( *curl_escape_func )( const char* string, int length );
typedef char* ( *curl_easy_unescape_func )( CURL* handle, const char* string, int length, int* outlength );
typedef char* ( *curl_unescape_func )( const char* string, int length );
typedef void ( *curl_free_func )( void* p );
typedef CURLcode ( *curl_global_init_func )( long flags );
typedef CURLcode ( *curl_global_init_mem_func )( long flags, curl_malloc_callback m, curl_free_callback f, curl_realloc_callback r, curl_strdup_callback s, curl_calloc_callback c );
typedef void ( *curl_global_cleanup_func )( void );
typedef struct curl_slist* ( *curl_slist_append_func )( struct curl_slist*, const char* );
typedef void ( *curl_slist_free_all_func )( struct curl_slist* );
typedef time_t ( *curl_getdate_func )( const char* p, const time_t* unused );
typedef CURLSH* ( *curl_share_init_func )( void );
typedef CURLSHcode ( *curl_share_setopt_func )( CURLSH*, CURLSHoption option, ... );
typedef CURLSHcode ( *curl_share_cleanup_func )( CURLSH* );
typedef curl_version_info_data* ( *curl_version_info_func )( CURLversion );
typedef const char* ( *curl_easy_strerror_func )( CURLcode );
typedef const char* ( *curl_share_strerror_func )( CURLSHcode );
typedef CURLcode ( *curl_easy_pause_func )( CURL* handle, int bitmask );

extern curl_formadd_func curl_formadd_P;
extern curl_formget_func curl_formget_P;
extern curl_formfree_func curl_formfree_P;
extern curl_getenv_func curl_getenv_P;
extern curl_version_func curl_version_P;
extern curl_easy_escape_func curl_easy_escape_P;
extern curl_escape_func curl_escape_P;
extern curl_easy_unescape_func curl_easy_unescape_P;
extern curl_unescape_func curl_unescape_P;
extern curl_free_func curl_free_P;
extern curl_global_init_func curl_global_init_P;
extern curl_global_init_mem_func curl_global_init_mem_P;
extern curl_global_cleanup_func curl_global_cleanup_P;
extern curl_slist_append_func curl_slist_append_P;
extern curl_slist_free_all_func curl_slist_free_all_P;
extern curl_getdate_func curl_getdate_P;
extern curl_share_init_func curl_share_init_P;
extern curl_share_setopt_func curl_share_setopt_P;
extern curl_share_cleanup_func curl_share_cleanup_P;
extern curl_version_info_func curl_version_info_P;
extern curl_easy_strerror_func curl_easy_strerror_P;
extern curl_share_strerror_func curl_share_strerror_P;
extern curl_easy_pause_func curl_easy_pause_P;

/// Easy API

typedef CURL*    ( *curl_easy_init_func )( void );
typedef CURLcode ( *curl_easy_setopt_func )( CURL* curl, CURLoption option, ... );
typedef CURLcode ( *curl_easy_perform_func )( CURL* curl );
typedef void     ( *curl_easy_cleanup_func )( CURL* curl );
typedef CURLcode ( *curl_easy_getinfo_func )( CURL* curl, CURLINFO info, ... );
typedef CURL*    ( *curl_easy_duphandle_func )( CURL* curl );
typedef void     ( *curl_easy_reset_func )( CURL* curl );
typedef CURLcode ( *curl_easy_recv_func )( CURL* curl, void* buffer, size_t buflen, size_t* n );
typedef CURLcode ( *curl_easy_send_func )( CURL* curl, const void* buffer, size_t buflen, size_t* n );

extern curl_easy_init_func    curl_easy_init_P;
extern curl_easy_setopt_func  curl_easy_setopt_P;
extern curl_easy_perform_func curl_easy_perform_P;
extern curl_easy_cleanup_func curl_easy_cleanup_P;
extern curl_easy_getinfo_func curl_easy_getinfo_P;
extern curl_easy_duphandle_func curl_easy_duphandle_P;
extern curl_easy_reset_func curl_easy_reset_P;
extern curl_easy_recv_func curl_easy_recv_func_P;
extern curl_easy_send_func curl_easy_send_P;

// we support both dynamic and static_ linking
#define CURL_DYNAMIC_LINK 1

#if !defined( _WIN32 )
#  undef CURL_DYNAMIC_LINK
#endif // OS_ANDROID

bool Curl_Load();
bool Curl_Unload();

#endif
