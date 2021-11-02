/* Uncomment the following line to get the compliant version: */
// #define COMPLIANT 1

#define MAX_COMPUTERNAME_LENGTH_FQDN 10

typedef char WCHAR;
typedef char * LPWSTR;
typedef int HRESULT;
typedef void error_status_t;

HRESULT hr;
HRESULT *phr = &hr;

HRESULT GetMachineName(
  WCHAR *pwszPath,
  WCHAR wszMachineName[MAX_COMPUTERNAME_LENGTH_FQDN+1])
{
  WCHAR *pwszServerName = wszMachineName;
  LPWSTR pwszTemp = pwszPath + 2;
#ifndef COMPLIANT
  while (*pwszTemp != L'\\')
    *pwszServerName++ = *pwszTemp++;
#else
  LPWSTR end_addr = pwszServerName + MAX_COMPUTERNAME_LENGTH_FQDN;
  while ( (*pwszTemp != L'\\')
     &&  ((*pwszTemp != L'\0'))
     && (pwszServerName < end_addr) )
  {
    *pwszServerName++ = *pwszTemp++;
  }
#endif
  /* ... */
  return 0;
}

HRESULT GetServerPath(
  WCHAR *pwszPath, WCHAR **pwszServerPath  ){
  WCHAR *pwszFinalPath = pwszPath;
  WCHAR wszMachineName[MAX_COMPUTERNAME_LENGTH_FQDN+1];
  hr = GetMachineName(pwszPath, wszMachineName);
  *pwszServerPath = pwszFinalPath;
  return 0;
}

error_status_t _RemoteActivation(
  /* ... */ WCHAR *pwszObjectName, ... ) {
  *phr = GetServerPath(
              pwszObjectName, &pwszObjectName);
  /* ... */
}

int main(void) {
  /* backslash at index 4 */
  WCHAR myObjectName1[] = "Foo\\";
  _RemoteActivation(myObjectName1);
  /* backslash at index 18 */
  WCHAR myObjectName2[] = "Foo walks into a Bar\\";
  _RemoteActivation(myObjectName2);
  return 0;
}
